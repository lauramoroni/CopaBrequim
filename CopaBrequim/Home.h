#ifndef _COPABREQUIM_HOME_H_
#define _COPABREQUIM_HOME_H_

// ------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Sprite.h"
#include "Home.h"

// ------------------------------------------------------------------------------

class Home : public Game
{
private:
    Sprite* backg = nullptr;       // pano de fundo
    bool ctrlKeyESC = false;        // controle do ESC

public:
    void Init();                    // inicializa��o
    void Update();                  // atualiza��o
    void OnGoal(bool foo) override;
    void Draw();                    // desenho
    void Finalize();                // finaliza��o
};

// -----------------------------------------------------------------------------

#endif