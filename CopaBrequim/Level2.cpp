#include "Ball.h"
#include "Engine.h"
#include "Home.h"
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
    backg = new Sprite("Resources/Background/level2.png");

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
    Sprite* ballSprite = new Sprite("Resources/sprites/football.png");
    ball = new Ball(ballSprite);
    scene->Add(ball, MOVING);

	// cria obstaculos estaticos
	// adiciona obstaculos estaticos na cena

	// cria obstaculos em movimento (possivelmente em um level3?)
	// adiciona obstaculos em movimento na cena

    // carrega placar
    score = new Score();
    scene->Add(score, STATIC);

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
        Engine::Next<Level2>();
        return;
    }

    if (window->KeyPress(VK_SPACE)) { // press space to start
        p1->Start();
        p2->Start();
        score->Start();
    }

    if (ball->X() > window->Width()) // se a bola bate na esquerda da tela
    {
        int scoreP1 = score->GetP1Score();
        int scoreP2 = score->GetP2Score();
        OutputDebugString("Gol do Hudson!");
        score->p1_score = scoreP1 + 1;
        p1->Reset();
        p2->Reset();
        ball->Reset();
        score->Stop();
        currentGameState = PAUSED;
    }

    if (ball->X() < 0) { // se a bola bate na direita da tela
        int scoreP1 = score->GetP1Score();
        int scoreP2 = score->GetP2Score();
        OutputDebugString("Gol do McQueen!");
        score->p2_score = scoreP2 + 1;
        p1->Reset();
        p2->Reset();
        ball->Reset();
        score->Stop();
        currentGameState = PAUSED;
    }

    if (score->GetP1Score() == 5 || score->GetP2Score() == 5 || score->timeOver) { // condi��es de fim de partida
        p1->Reset();
        p2->Reset();
        score->Reset();
        ball->Reset();
        currentGameState = PAUSED;
    }

    // atualiza cena
    scene->Update();
    scene->CollisionDetection();

}

// ------------------------------------------------------------------------------

void Level2::Draw()
{
    // desenha placar
    score->Draw();

    // desenha o background
    backg->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);

    // desenha cena
    scene->Draw();

    // desenha bounding box dos objetos
    if (viewBBox)
        scene->DrawBBox();
}

// ------------------------------------------------------------------------------

void Level2::Finalize()
{
    delete backg;
    delete scene;
}