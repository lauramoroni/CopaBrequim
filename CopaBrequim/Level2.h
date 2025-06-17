#ifndef _COPABREQUIM_LEVEl1_H_
#define _COPABREQUIM_LEVEL1_H_

// ------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Sprite.h"
#include "Scene.h"
#include "MCQueen.h"
#include "Hudson.h"
#include "Ball.h"
#include "Goal.h"
#include "Score.h"
// ------------------------------------------------------------------------------

class Level2 : public Game
{
private:
    Sprite* backg = nullptr;       // background
    Scene* scene = nullptr;        // gerenciador de cena
    MCQueen* mcQueen;              // Mcqueen
    Hudson* hudson;				   // Hudson
    Ball* ball;
    Score* score;
    Goal* goalLeft;                   // gol esquerda
    Goal* goalRight;                  // gol direita

    enum gameState { PAUSED, RUNNING }; // necessário aos resets globais
    gameState currentGameState;

    bool viewBBox = false;         // habilita visualizacao da bounding box
    bool ctrlKeyB = false;         // controle da tecla B


public:
    void Init();                    // inicializa jogo
    void Update();                  // atualiza l�gica do jogo
    void OnGoal(uint goalSide);
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza jogo
};

// -----------------------------------------------------------------------------

#endif