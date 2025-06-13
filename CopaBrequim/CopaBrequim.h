/**********************************************************************************
// CopaBrequim (Arquivo de Cabe�alho)
//
// Cria��o:     10 Jun 2025
// Atualiza��o: 
// Compilador:  Visual C++ 2022
//
// Descri��o:   Jogo estilo plataforma usando a engine do curso
//
**********************************************************************************/

#ifndef _COPABREQUIM_H_
#define _COPABREQUIM_H_

// ---------------------------------------------------------------------------------

#include "Game.h"
#include "Audio.h"
#include "Resources.h"

// ------------------------------------------------------------------------------

// enum

// ------------------------------------------------------------------------------

class CopaBrequim : public Game
{
private:
     
    static Game* level;            // n�vel atual do jogo

public:
    enum CopaBrequimObjects {
        PLAYER,
        PLAYER1,
        PLAYER2,
        BALL,
        WALLS  // sujeito a averigua��o posterior
    };

    static bool viewBBox;           // estado da bounding box

    void Init();                    // inicializa jogo
    void Update();                  // atualiza l�gica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza jogo

    template<class T>
    static void NextLevel()         // muda para pr�ximo n�vel do jogo
    {
        if (level)
        {
            level->Finalize();
            delete level;
            level = new T();
            level->Init();
        }
    };
};

// ---------------------------------------------------------------------------------

#endif