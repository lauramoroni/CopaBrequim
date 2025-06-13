
/**********************************************************************************
// Home (Arquivo de Cabe�alho)
//
// Cria��o:     12 Jun 2025
// Atualiza��o: 12 Jun 2025
// Compilador:  Visual C++ 2022
//
// Descri��o:   Tela de abertura do jogo Copa Brequim
//
**********************************************************************************/

#ifndef _COPABREQUIM_HOME_H_
#define _COPABREQUIM_HOME_H_

// ------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Sprite.h"

// ------------------------------------------------------------------------------

class Home : public Game
{
private:
    Sprite* backg = nullptr;       // pano de fundo

public:
    void Init();                    // inicializa��o
    void Update();                  // atualiza��o
    void Draw();                    // desenho
    void Finalize();                // finaliza��o
};

// -----------------------------------------------------------------------------

#endif