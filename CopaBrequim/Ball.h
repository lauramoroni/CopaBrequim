/**********************************************************************************
// Ball (Arquivo de Cabeçalho)
//
// Atualização: 16 Jun 2025
// Compilador:  Visual C++ 2022
//
// Descrição:   Bola
//
**********************************************************************************/

#ifndef _BALL_H_
#define _BALL_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                          // tipos específicos da engine
#include "Object.h"                         // interface de um objeto
#include "Animation.h"                      // desenha animação
#include "Vector.h"                         // representação de vetores

// ---------------------------------------------------------------------------------

class Ball : public Object
{
private:
    Sprite* ballSprite;

public:
    Vector speed;                           // velocidade da rocha
    Ball();                                 // construtor
    ~Ball();                                // destrutor

    void OnCollision(Object* obj);         // resolução da colisão
    void Update();                          // atualização 
    void Draw();                            // desenho
};

// ---------------------------------------------------------------------------------
// Função Membro Inline

inline void Ball::Draw()
{
    ballSprite->Draw(x, y, Layer::MIDDLE, scale, rotation);
}

// ---------------------------------------------------------------------------------

#endif