/**********************************************************************************
// MCQueen (Arquivo de Cabe�alho)
//
// Cria��o:     15 Jun 2025
// Compilador:  Visual C++ 2022
//
// Descri��o:   Define o personagem jog�vel MCQueen
//
**********************************************************************************/

#ifndef _ASTEROIDS_MCQueen_H_
#define _ASTEROIDS_MCQueen_H_

// ---------------------------------------------------------------------------------

#include "Vector.h"                     // representa��o de vetor
#include "Object.h"                     // objetos do jogo
#include "Sprite.h"
#include "Types.h"                      // tipos espec�ficos da engine

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
    Vector direction;                   // dire��o 
    Vector speed;                       // velocidade 

    MCQueen(char, char, char, char, char);                             // construtor    
    ~MCQueen();                            // destrutor

    void Forward();                     // propuls�o para frente
    void Backward();                    // propuls�o para tr�s

    void Rotate(float angle);           // sobrescreve m�todo de Object
    void Update();                      // atualiza��o
    void Draw();                        // desenho

    void OnCollision(Object* obj);      // resolu��o da colis�o
};

// ---------------------------------------------------------------------------------

#endif