#include "Ball.h"
#include "Engine.h"
#include "Home.h"
#include "Scoreboard.h"
#include "Level1.h"
#include "Level2.h"
#include "Player1.h"
#include "Player2.h"

// ------------------------------------------------------------------------------

void Level2::Init()
{
    // cria gerenciador de cena
    scene = new Scene();

    // cria background
    backg = new Sprite("Resources/Background/Level1.png"); // TO-DO: acrescentar imagem correta do level2

    // jogador
    // atribui personagens

    // sprites de movimentao do mcqueen
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

    // sprites de movimentao do hudson
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

    // adicionar players na cena
    p1 = new Player1(sprites1, true);
    scene->Add(p1, MOVING);

    p2 = new Player2(sprites2, false);
    scene->Add(p2, MOVING);

	// cria bola
	// adiciona bola na cena
    Sprite* ballSprite = new Sprite("Resources/football.png");
    scene->Add(new Ball(ballSprite), MOVING);

	// cria obstaculos estaticos
	// adiciona obstaculos estaticos na cena

	// cria obstaculos em movimento (possivelmente em um level3?)
	// adiciona obstaculos em movimento na cena

    // carrega placar
	scoreboard = new Scoreboard();
	scoreboard->Init();

}

// ------------------------------------------------------------------------------

void Level2::Update()
{
    // habilita/desabilita bounding box
    if (ctrlKeyB && window->KeyDown('B'))
    {
        viewBBox = !viewBBox;
        ctrlKeyB = false;
    }
    else if (window->KeyUp('B'))
    {
        ctrlKeyB = true;
    }

    if (window->KeyDown(VK_ESCAPE))
    {
        // volta para a tela de abertura
        Engine::Next<Home>();
    }
    else if (window->KeyDown('R'))
    {
        // reinicia o level
        Engine::Next<Level2>();
    }
    else
    {
        // atualiza cena
        scene->Update();
        scene->CollisionDetection();
    }

	// atualiza placar

}

// ------------------------------------------------------------------------------

void Level2::Draw()
{
    // desenha placar
	scoreboard->Draw();

    // desenha cena
    backg->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
    scene->Draw();

    // desenha players

    // desenha bola

    // desenha bounding box dos objetos
    if (viewBBox)
        scene->DrawBBox();

}

// ------------------------------------------------------------------------------

void Level2::Finalize()
{
    delete scene;
    delete backg;
	delete scoreboard;
}