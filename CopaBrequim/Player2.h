/**********************************************************************************
// Player (Arquivo de Cabe�alho)
//
// Cria��o:     12 Jun 2025
// Atualiza��o: 13 Jun 2025
// Compilador:  Visual C++ 2022
//
// Descri��o:   Player do jogo Copa Brequim
//
/**********************************************************************************/

#ifndef COPABREQUIM_PLAYER2_H
#define COPABREQUIM_PLAYER2_H

// ---------------------------------------------------------------------------------
// Inclus�es

#include "CopaBrequim.h"
#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // interface de Sprites
using namespace std;

// ---------------------------------------------------------------------------------
// Constantes Globais

const float p2MainVelocity = 400.0f;

// ---------------------------------------------------------------------------------



class Player2 : public Object
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
    bool started = false;                 // indica se o jogador j� come�ou a partida

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

    

    Player2(const PlayerSpritesPath& sprites, bool isP1);                           // construtor
    ~Player2();                          // destrutor

    void Stop();                        // para jogador
    void Up();                          // muda dire��o para cima
    void Down();                        // muda dire��o para baixo
    void Left();                        // muda dire��o para esquerda
    void Right();                       // muda dire��o para direita
    void Start();                       // libera movimenta��o do jogador
    void Reset();                       // volta �s posi��es iniciais, esperando o start

    void OnCollision(Object* obj);     // resolu��o da colis�o

    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
};

#endif