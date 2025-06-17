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
#include "Wall.h"

// ------------------------------------------------------------------------------

void Level1::Init()
{
    // cria gerenciador de cena
    this->scene = new Scene();

    // cria background
    this->backg = new Sprite("Resources/Background/Level1.png");

    // cria paredes
	// superior
	Wall* wallUp = new Wall(20.0f, 1024.0f, window->CenterX(), 105.0f, 0.0f);
	// inferior
	Wall* wallDown = new Wall(20.0f, 1024.0f, window->CenterX(), window->Height()-120, 0.0f);
	// esquerda
	Wall* wallLeftUp = new Wall(200.0f, 20.0f, 174.0f, window->CenterY() - 248, 90.0f);
	Wall* wallLeftDown = new Wall(200.0f, 20.0f, 174.0f, window->CenterY() + 140, 90.0f);
	// direita
	Wall* wallRightUp = new Wall(200.0f, 20.0f, window->Width()-184.0f, window->CenterY()-248, 90.0f);
	Wall* wallRightDown = new Wall(200.0f, 20.0f, window->Width()-184.0f, window->CenterY()+140, 90.0f);

	scene->Add(wallUp, STATIC);
	scene->Add(wallDown, STATIC);
	scene->Add(wallLeftUp, STATIC);
	scene->Add(wallLeftDown, STATIC);
	scene->Add(wallRightUp, STATIC);
	scene->Add(wallRightDown, STATIC);

    // cria players
    this->mcQueen = new MCQueen(VK_UP, VK_RIGHT, VK_DOWN, VK_LEFT, 'R');
    scene->Add(mcQueen, MOVING);

	this->hudson = new Hudson('W', 'D', 'S', 'A', 'L');
	scene->Add(hudson, MOVING);

    // cria bola
    // adiciona bola na cena
	ball = new Ball();
    scene->Add(ball, MOVING);
  
	// cria placar
    this->score = new Score();
    scene->Add(score, STATIC);

	// define estado do jogo
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

    if (ball->X() > window->Width()) // se a bola bate na esquerda da tela
    {
        CopaBrequim::hudsonScore++;
        mcQueen->Reset();
        hudson->Reset();
        ball->Reset();
        score->Stop();
        currentGameState = PAUSED;
    }

    if (ball->X() < 0) { // se a bola bate na direita da tela
        CopaBrequim::mcQueenScore++;
        mcQueen->Reset();
        hudson->Reset();
        ball->Reset();
        score->Stop();
        currentGameState = PAUSED;
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
    score->Draw();

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