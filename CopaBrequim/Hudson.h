/**********************************************************************************
// Hudson (Arquivo de Cabe�alho)
//
// Cria��o:     15 Jun 2025
// Compilador:  Visual C++ 2022
//
// Descri��o:   Define o personagem jog�vel Hudson
//
**********************************************************************************/

#ifndef _ASTEROIDS_Hudson_H_
#define _ASTEROIDS_Hudson_H_

// ---------------------------------------------------------------------------------

#include "Vector.h"                     // representa��o de vetor
#include "Object.h"                     // objetos do jogo
#include "Sprite.h"
#include "Types.h"                      // tipos espec�ficos da engine

// ---------------------------------------------------------------------------------

class Hudson : public Object
{
private:
    Sprite* carSprite;                  // folha de sprites 

    // teclas de controle 
    char up;
    char down;
    char left;
    char right;

    char initial_side;                  // lado inicial  (L ou R)

    bool started = false;

    // constantes de controle 
    const float ACCELERATION = 30.0f;
    const float YAW_RESISTANCE = 25.0f;
    const float SKIDDING_ANGLE = 110.0f;
    const float MAXSPEED = 100.0f;
public:
    Vector direction;                   // dire��o 
    Vector speed;                       // velocidade 

    Hudson(char, char, char, char, char);                             // construtor    
    ~Hudson();                            // destrutor

    void Forward();                     // propuls�o para frente
    void Backward();                    // propuls�o para tr�s

    void Rotate(float angle);           // sobrescreve m�todo de Object
    void Update();                      // atualiza��o
    void Draw();                        // desenho

    void Start();
    void Reset();

	void OnCollision(Object* obj);      // resolu��o da colis�o
};

// ---------------------------------------------------------------------------------

#endif