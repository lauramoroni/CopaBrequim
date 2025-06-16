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

	// cria bounding box redonda
	BBox(new Circle(32));

	// posi��o inicial no centro
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
