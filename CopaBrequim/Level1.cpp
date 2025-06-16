#include "Ball.h"
#include "Engine.h"
#include "Home.h"
#include "Level1.h"
#include "Level2.h"
#include "MCQueen.h"
#include "Hudson.h"

// ------------------------------------------------------------------------------

void Level1::Init()
{
    // cria gerenciador de cena
    scene = new Scene();

    // cria background
    backg = new Sprite("Resources/Background/Level1.png"); // TO-DO: acrescentar imagem correta do level1

    // cria player 1
    // adicionar player 1 na cena
    mcQueen = new MCQueen(VK_UP, VK_RIGHT, VK_DOWN, VK_LEFT, 'R');
    scene->Add(mcQueen, MOVING);

    // cria player 2
    // adicionar player 2 na cena
	hudson = new Hudson('W', 'D', 'S', 'A', 'L');
	scene->Add(hudson, MOVING);

    // cria bola
    // adiciona bola na cena
    scene->Add(new Ball(), MOVING);
  
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
}

// ------------------------------------------------------------------------------

void Level1::Draw()
{
    // desenha o background
    backg->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
  
    // desenha cena
    scene->Draw();

    // desenha players
    mcQueen->Draw();
    //p2->Draw();
     
	// desenha bola

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