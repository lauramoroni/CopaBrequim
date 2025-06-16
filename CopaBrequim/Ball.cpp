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

// ---------------------------------------------------------------------------------

Ball::Ball() {
	// cria sprite da bola
	ballSprite = new Sprite("Resources/football.png");
	
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
	float friction_factor = 1 - gameTime;
	speed.Scale(friction_factor);

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

void Ball::OnCollision(Object* obj) {}

// ---------------------------------------------------------------------------------
