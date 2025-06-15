#pragma once
#ifndef _COPABREQUIM_SCOREBOARD_H_
#define _COPABREQUIM_SCOREBOARD_H_

// ------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Sprite.h"
#include "Font.h"
#include "Timer.h"

// ------------------------------------------------------------------------------

class Scoreboard : public Game
{
private:
    static Font* font;           // fonte para exibi����o de texto
    static Sprite* keyMap;      // caixa para placar 
	static Timer* timer;        // temporizador para anima����o

public:
    // tempo atual, atualizado nos niveis
    void Init();                    // inicializa��o
    void Update();                  // atualiza��o
    void Draw();                    // desenho
    void Finalize();                // finaliza��o
};

// -----------------------------------------------------------------------------

#endif