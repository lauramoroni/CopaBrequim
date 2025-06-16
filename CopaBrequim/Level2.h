#ifndef _COPABREQUIM_LEVEl2_H_
#define _COPABREQUIM_LEVEL2_H_

// ------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Sprite.h"
#include "Scene.h"
#include "Player1.h"
#include "Player2.h"

// ------------------------------------------------------------------------------

class Level2 : public Game
{
private:
    Sprite* backg = nullptr;       // background
    Scene* scene = nullptr;        // gerenciador de cena
    Player1* p1;                   // Mcqueen
    Player2* p2;				    // Hudson
    Ball* ball;
    Score* score;

    enum gameState { PAUSED, RUNNING }; // necessário aos resets globais
    gameState currentGameState;

    bool viewBBox = false;         // habilita visualizacao da bounding box
    bool ctrlKeyB = false;          // controle da tecla B

public:
    void Init();                    // inicializa jogo
    void Update();                  // atualiza l�gica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza jogo
};

// -----------------------------------------------------------------------------

#endif