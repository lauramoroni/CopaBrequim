#ifndef _COPABREQUIM_GAMEOVER_H_
#define _COPABREQUIM_GAMEOVER_H_

// ------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Sprite.h"
#include "Scene.h"
#include "Font.h"

// ------------------------------------------------------------------------------

class GameOver : public Game
{
private:
	Sprite* backg = nullptr;       // background
    Scene* scene = nullptr;        // gerenciador de cena
    Font* font = nullptr;

public:
	void Init(); // construtor com pontua����es
    void Update();                  // atualiza l�gica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza jogo
};

// -----------------------------------------------------------------------------

#endif