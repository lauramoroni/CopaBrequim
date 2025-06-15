#include "Ball.h"
#include "Engine.h"
#include "Home.h"
#include "Scoreboard.h"
#include "Level1.h"
#include "Level2.h"
#include "Player1.h"
#include "Player2.h"

// ------------------------------------------------------------------------------

void Level1::Init()
{
    // cria gerenciador de cena
    scene = new Scene();

    // cria background
    backg = new Sprite("Resources/Background/Level1.png"); // TO-DO: acrescentar imagem correta do level1

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

    // cria player 1
    // adicionar player 1 na cena
    p1 = new Player1(sprites1, true);
    scene->Add(p1, MOVING);

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

    // cria player 2
    // adicionar player 2 na cena
    p2 = new Player2(sprites2, false);
	  scene->Add(p2, MOVING);

    // cria bola
    // adiciona bola na cena
    Sprite* ballSprite = new Sprite("Resources/football.png");
    scene->Add(new Ball(ballSprite), MOVING);
  
    // carrega placar
    //keyMap = new Sprite("Resources/background/placar.png");
	scoreboard = new Scoreboard();

	// inicializa placar
	scoreboard->Init();

}

// ------------------------------------------------------------------------------

void Level1::Update()
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
    else if (window->KeyDown('N'))
    {
		    Engine::Next<Level2>(); 
	  }
	  else if (window->KeyDown('R'))
	  {
		    // reinicia o level
		    Engine::Next<Level1>();
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

void Level1::Draw()
{
    // desenha placar
    //keyMap->Draw(window->CenterX(), window->Height() - 20.0f, Layer::FRONT);
    scoreboard->Draw();

    // desenha o background
    backg->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
  
    // desenha cena
    scene->Draw();

    // desenha players
    p1->Draw();
    p2->Draw();
     
	  // desenha bola

    // desenha bounding box dos objetos
    if (viewBBox)
        scene->DrawBBox();

    // desenha texto
    //Color gray{ 0.70f, 0.70f, 0.70f, 1.0f };

    //font->Draw(window->CenterX(), window->Height() - 14.0f, "01:43", gray);
    //font->Draw(window->CenterX() - 130.0f, window->Height() - 4.0f, " 1 ", gray);
    //font->Draw(window->CenterX() + 130.0f, window->Height() - 4.0f, " 0 ", gray);
}

// ------------------------------------------------------------------------------

void Level1::Finalize()
{
    delete backg;
    delete scene;
    delete scoreboard;
}

// ------------------------------------------------------------------------------