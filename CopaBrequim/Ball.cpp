/**********************************************************************************
// Ball (Arquivo de Cabe�alho)
//
// Cria��o:     13 Jun 2025
// Atualiza��o: 13 Jun 2025
// Compilador:  Visual C++ 2022
//
// Descri��o:   Bola do jogo Copa Brequim
//
**********************************************************************************/

#include "Ball.h"
#include "CopaBrequim.h"
#include "Goal.h"
#include "Wall.h"

// ---------------------------------------------------------------------------------

Ball::Ball(Game * level) {
	currentLevel = level;

	// cria sprite da bola
	ballSprite = new Sprite("Resources/sprites/football.png");
	
	// Aproximação hexagonal para o BBox
	Point ballVertex[10] = {
		Point(32.0f,  0.0f),    // V�rtice 1 (direita)
		Point(25.9f,  18.8f),   // V�rtice 2
		Point(9.9f,   30.4f),   // V�rtice 3
		Point(-9.9f,  30.4f),   // V�rtice 4
		Point(-25.9f, 18.8f),   // V�rtice 5
		Point(-32.0f, 0.0f),    // V�rtice 6 (esquerda)
		Point(-25.9f, -18.8f),  // V�rtice 7
		Point(-9.9f,  -30.4f),  // V�rtice 8
		Point(9.9f,   -30.4f),  // V�rtice 9
		Point(25.9f,  -18.8f)   // V�rtice 10
	};

	// Cria a bounding box poligonal com os 10 v�rtices do dec�gono
	BBox(new Poly(ballVertex, 10));

	// posição inicial no centro
	MoveTo(window->CenterX(), window->CenterY());

	// velocidade inicial
	speed.ScaleTo(0.0f);

	// tipo do objeto
	type = BALL;

}

// ---------------------------------------------------------------------------------

Ball::~Ball() {
	delete ballSprite;
}

// ---------------------------------------------------------------------------------

void Ball::Update() {
	// friction factor
	float friction_factor = -0.998;
	Vector friction_vector{ speed.Angle(), friction_factor * speed.Magnitude() * gameTime };
	speed.Add(friction_vector);
	if (speed.Magnitude() > MAXSPEED)
		speed.ScaleTo(MAXSPEED);

	// desloca a bola
	Translate(speed.XComponent() * gameTime, -speed.YComponent() * gameTime);

	// verifica se a bola saiu da tela
	if (x < -20 || x > window->Width() + 20 || y < -20 || y > window->Height() + 20) {
		// reposiciona a bola no centro
		MoveTo(window->CenterX(), window->CenterY());
		speed.ScaleTo(0.0f); // zera a velocidade
	}
}

// ---------------------------------------------------------------------------------

void Ball::Reset() {
	// reinicia a bola
	started = false;
	speed.ScaleTo(0.0f);
	MoveTo(window->CenterX(), window->CenterY());
}

// ---------------------------------------------------------------------------------

void Ball::OnCollision(Object* obj) {
	if (obj->Type() == GOAL && currentLevel) {
		Goal* goal = static_cast<Goal*>(obj);
		if (goal->GetTeam() == LEFT) { // se o gol foi feito na esquerda
			currentLevel->OnGoal(LEFT);
		}
		else { // se o gol foi na direita
			currentLevel->OnGoal(RIGHT);
		}
	}

	else if (obj->Type() == WALL)
	{
		// --- INÍCIO DA LÓGICA DE COLISÃO REALISTA (IDÊNTICA À DO CARRO) ---

		Wall* wall = static_cast<Wall*>(obj);

		// --- CÁLCULO DA NORMAL DA COLISÃO ---
		float vec_x = this->X() - wall->X();
		float vec_y = -(this->Y() - wall->Y()); // Invertendo Y para o cálculo

		Vector wallAxisX(0, 1);
		wallAxisX.RotateTo(wall->Angle());
		Vector wallAxisY(90, 1);
		wallAxisY.RotateTo(wall->Angle() + 90.0f);

		Vector normal;

		float projX = (vec_x * wallAxisX.XComponent()) + (vec_y * wallAxisX.YComponent());
		float projY = (vec_x * wallAxisY.XComponent()) + (vec_y * wallAxisY.YComponent());

		if (abs(projX) / wall->Width() > abs(projY) / wall->Length())
		{
			normal = wallAxisX;
			if (projX < 0) normal.Rotate(180);
		}
		else
		{
			normal = wallAxisY;
			if (projY < 0) normal.Rotate(180);
		}

		// --- RESPOSTA FÍSICA À COLISÃO ---
		float elasticity = 0.8f; // Bolas são mais "elásticas"
		Vector v = this->speed;
		float j = -(1 + elasticity) * Vector::Dot(v, normal);
		Vector impulse = normal;
		impulse.ScaleTo(j);
		this->speed.Add(impulse);

		// --- CORREÇÃO DE POSIÇÃO ---
		float push_factor = 1.0f;
		Translate(normal.XComponent() * push_factor, -normal.YComponent() * push_factor);
	}

}

// ---------------------------------------------------------------------------------
