/**********************************************************************************
// Ball (Arquivo de Cabe�alho)
//
// Atualiza��o: 16 Jun 2025
// Compilador:  Visual C++ 2022
//
// Descri��o:   Bola
//
**********************************************************************************/

#ifndef _BALL_H_
#define _BALL_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                          // tipos espec�ficos da engine
#include "Object.h"                         // interface de um objeto
#include "Animation.h"                      // desenha anima��o
#include "Vector.h"                         // representa��o de vetores

// ---------------------------------------------------------------------------------

class Ball : public Object
{
private:
    Sprite* ballSprite;
	bool started = false;

public:
    Vector speed;                           // velocidade da rocha
    Ball();                                 // construtor
    ~Ball();                                // destrutor

    void OnCollision(Object* obj);         // resolu��o da colis�o
    void Update();                          // atualiza��o 
    void Draw();                            // desenho

	void Start() { started = true; }
    void Reset();

};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline

inline void Ball::Draw()
{
    ballSprite->Draw(x, y, Layer::MIDDLE, scale, rotation);
}

// ---------------------------------------------------------------------------------

#endif