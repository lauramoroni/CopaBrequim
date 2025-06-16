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

Ball::Ball(Sprite * ball) {
	sprite = ball;
	velX = 0;
	velY = 0;

	BBox(new Circle(30));

	MoveTo(window->CenterX(), window->CenterY());
}

// ---------------------------------------------------------------------------------

Ball::~Ball() {

}

// ---------------------------------------------------------------------------------

void Ball::Update() { // placeholders de movimento da bola para testes
	if (window->KeyDown('I')) {
		velX = 0;
		velY = -600.0f;
		Translate(velX * gameTime, velY * gameTime);
	}
	else if (window->KeyDown('K')) {
		velX = 0;
		velY = 600.0f;
		Translate(velX * gameTime, velY * gameTime);
	}
	else if (window->KeyDown('J')) {
		velX = -600.0f;
		velY = 0;
		Translate(velX * gameTime, velY * gameTime);
	}
	else if (window->KeyDown('L')) {
		velX = 600.0f;
		velY = 0;
		Translate(velX * gameTime, velY * gameTime);
	} else {
		velX = 0;
		velY = 0;
	}

}

// ---------------------------------------------------------------------------------

void Ball::OnCollision(Object* obj) {

}

// ---------------------------------------------------------------------------------
