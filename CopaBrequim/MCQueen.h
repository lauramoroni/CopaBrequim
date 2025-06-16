/**********************************************************************************
// MCQueen (Arquivo de Cabeçalho)
//
// Criação:     15 Jun 2025
// Compilador:  Visual C++ 2022
//
// Descrição:   Define o personagem jogável MCQueen
//
**********************************************************************************/

#ifndef _ASTEROIDS_MCQueen_H_
#define _ASTEROIDS_MCQueen_H_

// ---------------------------------------------------------------------------------

#include "Vector.h"                     // representação de vetor
#include "Object.h"                     // objetos do jogo
#include "Sprite.h"
#include "Types.h"                      // tipos específicos da engine

// ---------------------------------------------------------------------------------

class MCQueen : public Object
{
private:
    Sprite* carSprite;                  // folha de sprites 

    // teclas de controle 
    char up;
    char down;
    char left;
    char right;

    char initial_side;                  // lado inicial  (L ou R)

    // constantes de controle 
    const float ACCELERATION = 40.0f;
    const float SKIDDING_ANGLE = 45;
public:
    Vector direction;                   // direção 
    Vector speed;                       // velocidade 

    MCQueen(char, char, char, char, char);                             // construtor    
    ~MCQueen();                            // destrutor

    void Forward();                     // propulsão para frente
    void Backward();                    // propulsão para trás

    void Rotate(float angle);           // sobrescreve método de Object
    void Update();                      // atualização
    void Draw();                        // desenho

    void OnCollision(Object* obj);      // resolução da colisão
};

// ---------------------------------------------------------------------------------

#endif