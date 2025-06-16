/**********************************************************************************
// Ball (Arquivo de Cabeçalho)
//
// Criação:     13 Jun 2025
// Atualização: 13 Jun 2025
// Compilador:  Visual C++ 2022
//
// Descrição:   Bola do jogo Copa Brequim
//
**********************************************************************************/

#include "Ball.h"
#include "CopaBrequim.h"

// ---------------------------------------------------------------------------------

Ball::Ball() {
	// cria sprite da bola
	ballSprite = new Sprite("Resources/football.png");

	// cria bounding box redonda
	//BBox(new Circle(32));
	
	// Aproximação hexagonal para o BBox
	Point ballVertex[10] = {
		Point(32.0f,  0.0f),    // Vértice 1 (direita)
		Point(25.9f,  18.8f),   // Vértice 2
		Point(9.9f,   30.4f),   // Vértice 3
		Point(-9.9f,  30.4f),   // Vértice 4
		Point(-25.9f, 18.8f),   // Vértice 5
		Point(-32.0f, 0.0f),    // Vértice 6 (esquerda)
		Point(-25.9f, -18.8f),  // Vértice 7
		Point(-9.9f,  -30.4f),  // Vértice 8
		Point(9.9f,   -30.4f),  // Vértice 9
		Point(25.9f,  -18.8f)   // Vértice 10
	};

	// Cria a bounding box poligonal com os 10 vértices do decágono
	BBox(new Poly(ballVertex, 10));


		
	// posição inicial no centro
	MoveTo(window->CenterX(), window->CenterY());
	ScaleTo(0.6f);

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

void Ball::OnCollision(Object* obj) {}

// ---------------------------------------------------------------------------------
