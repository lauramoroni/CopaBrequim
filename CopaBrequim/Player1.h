/**********************************************************************************
// Player (Arquivo de Cabeçalho)
//
// Criação:     12 Jun 2025
// Atualização: 13 Jun 2025
// Compilador:  Visual C++ 2022
//
// Descrição:   Player do jogo Copa Brequim
//
/**********************************************************************************/

#ifndef COPABREQUIM_PLAYER1_H
#define COPABREQUIM_PLAYER1_H

// ---------------------------------------------------------------------------------
// Inclusões

#include "CopaBrequim.h"
#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // interface de Sprites
using namespace std;

// ---------------------------------------------------------------------------------
// Constantes Globais

const float p1MainVelocity = 400.0f;

// ---------------------------------------------------------------------------------


class Player1 : public Object
{
private:
    enum PlayerState { STOPPED, UP, DOWN, LEFT, RIGHT, UPRIGHT, UPLEFT, DOWNRIGHT, DOWNLEFT };


    Sprite* spriteU;          // Sprite do jogador
    Sprite* spriteR;
    Sprite* spriteD;
    Sprite* spriteL;

    Sprite* spriteUR;
    Sprite* spriteUL;
    Sprite* spriteDR;
    Sprite* spriteDL;

    float velX = 0;
    float velY = 0;
    bool isPlayer1;

    uint currState = STOPPED;            // estado atual do jogador

public:
    struct PlayerSpritesPath {
        string up;
        string down;
        string left;
        string right;
        string upRight;
        string upLeft;
        string downRight;
        string downLeft;
    };

    

    Player1(const PlayerSpritesPath& sprites, bool isP1);                           // construtor
    ~Player1();                          // destrutor

    void Stop();                        // para jogador
    void Up();                          // muda direção para cima
    void Down();                        // muda direção para baixo
    void Left();                        // muda direção para esquerda
    void Right();                       // muda direção para direita

    void OnCollision(Object* obj);     // resolução da colisão

    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
};

#endif