/**********************************************************************************
// CopaBrequim (Código Fonte)
//
// Criação:     10 Jun 2025
// Atualização: 
// Compilador:  Visual C++ 2022
//
// Descrição:   Jogo estilo topdown usando a engine do curso
//
**********************************************************************************/

#include "Engine.h"
#include "Resources.h"
#include "Home.h"
#include "Font.h"
#include "CopaBrequim.h"

// ------------------------------------------------------------------------------

Scene * CopaBrequim::scene = nullptr;         // cena do jogo
Audio * CopaBrequim::audio = nullptr;         // sistema de áudio

// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    Engine* engine = new Engine();

    // configura o motor
    engine->window->Mode(WINDOWED);
    engine->window->Size(1024, 700);
    engine->window->Color(30, 50, 80);
    engine->window->Title("CopaBrequim");
    engine->window->Icon(IDI_ICON);
    engine->window->Cursor(IDC_CURSOR);
    //engine->graphics->VSync(true);

    // inicia o jogo
    int status = engine->Start(new Home());

    delete engine;
    return status;
}

// ----------------------------------------------------------------------------

