#include "CopaBrequim.h"
#include "Ball.h"
#include "Engine.h"
#include "Home.h"
#include "Level1.h"
#include "Level2.h"
#include "MCQueen.h"
#include "Hudson.h"
#include "Score.h"
#include "GameOver.h"
#include "Goal.h"

// ------------------------------------------------------------------------------

void Level1::Init()
{
    // cria gerenciador de cena
    this->scene = new Scene();

    // cria background
    this->backg = new Sprite("Resources/Background/Level1.png"); // TO-DO: acrescentar imagem correta do level1

    // cria players
    this->mcQueen = new MCQueen(VK_UP, VK_RIGHT, VK_DOWN, VK_LEFT, 'R');
    scene->Add(mcQueen, MOVING);

	this->hudson = new Hudson('W', 'D', 'S', 'A', 'L');
	scene->Add(hudson, MOVING);

    // cria bola
    // adiciona bola na cena
	ball = new Ball(this);
    scene->Add(ball, MOVING);
  
	// cria placar
    this->score = new Score();
    scene->Add(score, STATIC);

    goalLeft = new Goal(LEFT, 1);
	goalRight = new Goal(RIGHT, 1);

	scene->Add(goalLeft, STATIC);
    scene->Add(goalRight, STATIC);

	// define estado do jogo
	currentGameState = PAUSED;
}

// ------------------------------------------------------------------------------

void Level1::OnGoal(uint goalSide) {
    if (goalSide == LEFT) {
        CopaBrequim::mcQueenScore++;
    }
    else{
		CopaBrequim::hudsonScore++;
    }
    mcQueen->Reset();
    hudson->Reset();
    ball->Reset();
    score->Stop();
    currentGameState = PAUSED;
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
    
    if (window->KeyUp('B'))
    {
        ctrlKeyB = true;
    }

    if (window->KeyDown(VK_ESCAPE))
    {
		Engine::Next<Home>();
        return;
    }

    if (window->KeyDown('N'))
    {
		Engine::Next<Level2>(); 
        return;
	  }
	if (window->KeyDown('R'))
	{
		// reinicia o level
		Engine::Next<Level1>();
        return;
        return;
	}

    if (window->KeyPress(VK_SPACE)) { // press space to start
        mcQueen->Start();
        hudson->Start();
        score->Start();
    }

    if (CopaBrequim::mcQueenScore == 5 || CopaBrequim::hudsonScore == 5 || score->timeOver) { // condi��es de fim de partida
		Engine::Next<GameOver>();

        return;
    }

    // atualiza cena
    scene->Update();
    scene->CollisionDetection();
}

// ------------------------------------------------------------------------------

void Level1::Draw()
{
    // desenha placar
    score->Draw(); // por que desenhar vários score?

    // desenha o background
    backg->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
  
	// desenha placar
	score->Draw();

    // desenha cena
    scene->Draw();

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