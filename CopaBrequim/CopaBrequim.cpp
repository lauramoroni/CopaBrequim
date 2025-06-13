/**********************************************************************************
// CopaBrequim (C�digo Fonte)
//
// Cria��o:     10 Jun 2025
// Atualiza��o: 
// Compilador:  Visual C++ 2022
//
// Descri��o:   Jogo estilo topdown usando a engine do curso
//
**********************************************************************************/

#include "Engine.h"
#include "CopaBrequim.h"
#include "Home.h"

// ------------------------------------------------------------------------------

// inicializa membros est�ticos da classe

// ------------------------------------------------------------------------------

void CopaBrequim::Init()
{
    // cria sistema de �udio
    ;

    // bounding box


    // cria jogador teste
    

    // inicializa n�vel de abertura do jogo

}

// ------------------------------------------------------------------------------

void CopaBrequim::Update()
{
    // habilita/desabilita visualiza��o da bounding box

    // atualiza n�vel

}

// ------------------------------------------------------------------------------

void CopaBrequim::Draw()
{
    // desenha n�vel

}

// ------------------------------------------------------------------------------

void CopaBrequim::Finalize()
{
    // finaliza n�vel
}


// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    Engine* engine = new Engine();

    // configura o motor
    engine->window->Mode(WINDOWED);
    engine->window->Size(1280, 800);
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

