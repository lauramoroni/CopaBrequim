/**********************************************************************************
// CopaBrequim (Arquivo de Cabeçalho)
//
// Criação:     10 Jun 2025
// Atualização: 
// Compilador:  Visual C++ 2022
//
// Descrição:   Jogo estilo plataforma usando a engine do curso
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
     
    static Game* level;            // nível atual do jogo

public:
    enum CopaBrequimObjects {
        PLAYER,
        PLAYER1,
        PLAYER2,
        BALL,
        WALLS  // sujeito a averiguação posterior
    };

    static bool viewBBox;           // estado da bounding box

    void Init();                    // inicializa jogo
    void Update();                  // atualiza lógica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza jogo

    template<class T>
    static void NextLevel()         // muda para próximo nível do jogo
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