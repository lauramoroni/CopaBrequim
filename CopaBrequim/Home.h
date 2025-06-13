
/**********************************************************************************
// Home (Arquivo de Cabeçalho)
//
// Criação:     12 Jun 2025
// Atualização: 12 Jun 2025
// Compilador:  Visual C++ 2022
//
// Descrição:   Tela de abertura do jogo Copa Brequim
//
**********************************************************************************/

#ifndef _COPABREQUIM_HOME_H_
#define _COPABREQUIM_HOME_H_

// ------------------------------------------------------------------------------
// Inclusões

#include "Game.h"
#include "Sprite.h"

// ------------------------------------------------------------------------------

class Home : public Game
{
private:
    Sprite* backg = nullptr;       // pano de fundo

public:
    void Init();                    // inicialização
    void Update();                  // atualização
    void Draw();                    // desenho
    void Finalize();                // finalização
};

// -----------------------------------------------------------------------------

#endif