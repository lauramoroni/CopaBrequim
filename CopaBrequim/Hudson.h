/**********************************************************************************
// Hudson (Arquivo de Cabeçalho)
//
// Criação:     15 Jun 2025
// Compilador:  Visual C++ 2022
//
// Descrição:   Define o personagem jogável Hudson
//
**********************************************************************************/

#ifndef _ASTEROIDS_Hudson_H_
#define _ASTEROIDS_Hudson_H_

// ---------------------------------------------------------------------------------

#include "Vector.h"                     // representação de vetor
#include "Object.h"                     // objetos do jogo
#include "Sprite.h"
#include "Types.h"                      // tipos específicos da engine

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
    const float ACCELERATION = 40.0f;
    const float YAW_RESISTANCE = 25.0f;
    const float SKIDDING_ANGLE = 110.0f;
    const float MAXSPEED = 40.0f;
	const float MIN_ENGINE_VOLUME = 0.3f;
	const float MIN_ENGINE_FREQ = 0.2f;
public:
    Vector direction;                   // direção 
    Vector speed;                       // velocidade 

    Hudson(char, char, char, char, char);                             // construtor    
    ~Hudson();                            // destrutor

    void Forward();                     // propulsão para frente
    void Backward();                    // propulsão para trás

    void Rotate(float angle);           // sobrescreve método de Object
    void Update();                      // atualização
    void Draw();                        // desenho

    void Start();
    void Reset();

	void OnCollision(Object* obj);      // resolução da colisão
};

// ---------------------------------------------------------------------------------

#endif