/**********************************************************************************
// Level1 (Código Fonte)
//
// Criação:     18 Jan 2013
// Atualização: 13 Jun 2025
// Compilador:  Visual C++ 2022
//
// Descrição:   Nível Teste do jogo 1
//
**********************************************************************************/

#include "Engine.h"
#include "Home.h"
#include "Level1.h"
#include "Player1.h"
#include "Player2.h"
#include <string>
#include <fstream>
using std::ifstream;
using std::string;

// ------------------------------------------------------------------------------

void Level1::Init()
{
    // cria gerenciador de cena
    scene = new Scene();

    // cria background


    // sprites de movimentação do mcqueen
    Player1::PlayerSpritesPath sprites1 = {
        "Resources/mcqueen/mcqueen_up.png",
		"Resources/mcqueen/mcqueen_down.png",
		"Resources/mcqueen/mcqueen_left.png",
		"Resources/mcqueen/mcqueen_right.png",

        "Resources/mcqueen/mcqueen_upRight.png",
		"Resources/mcqueen/mcqueen_upLeft.png",
		"Resources/mcqueen/mcqueen_downRight.png",
		"Resources/mcqueen/mcqueen_downLeft.png"
    };

    // cria jogador
    p1 = new Player1(sprites1, true);
    scene->Add(p1, MOVING);

    Player2::PlayerSpritesPath sprites2 = {
        "Resources/hudson/hudson_up.png",
        "Resources/hudson/hudson_down.png",
        "Resources/hudson/hudson_left.png",
        "Resources/hudson/hudson_right.png",

        "Resources/hudson/hudson_upRight.png",
        "Resources/hudson/hudson_upLeft.png",
        "Resources/hudson/hudson_downRight.png",
        "Resources/hudson/hudson_downLeft.png"
    };

    p2 = new Player2(sprites2, false);
	scene->Add(p2, MOVING);
}

// ------------------------------------------------------------------------------

void Level1::Update()
{
    // habilita/desabilita bounding box
    if (window->KeyPress('B'))
    {
        viewBBox = !viewBBox;
    }

    if (window->KeyPress(VK_ESCAPE))
    {
        // volta para a tela de abertura
        Engine::Next<Home>();
    }
    else if (window->KeyPress('N'))
    {
        // passa manualmente para o próximo nível
        //Engine::Next<Level2>();
    }
    else
    {
        // atualiza cena
        scene->Update();
        scene->CollisionDetection();
    }
}

// ------------------------------------------------------------------------------

void Level1::Draw()
{
   
    // desenha cena
    scene->Draw();

    p1->Draw();
    p2->Draw();
    // desenha bounding box dos objetos
    if (viewBBox)
        scene->DrawBBox();
}

// ------------------------------------------------------------------------------

void Level1::Finalize()
{
    delete backg;
    delete scene;
}

// ------------------------------------------------------------------------------