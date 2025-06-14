/**********************************************************************************
// Ball (Arquivo de Cabe�alho)
//
// Cria��o:     12 Jun 2025
// Atualiza��o: 13 Jun 2025
// Compilador:  Visual C++ 2022
//
// Descri��o:  Bola do jogo Copa Brequim
//
/**********************************************************************************/

#ifndef BALL_H
#define BALL_H

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // interface de Sprites

class Ball : public Object
{
private:
	Sprite* sprite;

public:
	float velX;
	float velY;

	Ball(Sprite* sprite);
	~Ball();

	void OnCollision(Object* obj);
	void Update();
	void Draw();
};


inline void Ball::Draw()
{ sprite->Draw(x, y, z); }
#endif