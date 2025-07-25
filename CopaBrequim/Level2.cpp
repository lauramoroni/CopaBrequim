#include "CopaBrequim.h"

#include "GameOver.h"
#include "Ball.h"
#include "Engine.h"
#include "Home.h"
#include "Level1.h"
#include "Level2.h"
#include "MCQueen.h"
#include "Hudson.h"
#include "Score.h"
#include "Wall.h"

// ------------------------------------------------------------------------------

void Level2::Init()
{
    // sistema de audio
    CopaBrequim::audio = new Audio();
    CopaBrequim::audio->Add(MCQUEEN_GOAL, "Resources/Audio/mcqueen-goal.wav");
	CopaBrequim::audio->Add(HUDSON_GOAL, "Resources/Audio/hudson-goal.wav");

    // cria gerenciador de cena
    this->scene = new Scene();

    // cria background
    this->backg = new Sprite("Resources/Background/Level2.png");

    // cria paredes
    // superior
    Wall* wallUp = new Wall(20.0f, window->Width(), window->CenterX(), 86.0f, 90.0f);
    // inferior
    Wall* wallDown = new Wall(20.0f, window->Width(), window->CenterX(), window->Height() - 88.0f, 90.0f);

    // esquerda antes e depois do gol
    Wall* wallLeftUp = new Wall(20.0f, 200.0f, 112.0f, window->CenterY() - 170.0f, 0.0f);
    Wall* wallLeftDown = new Wall(20.0f, 200.0f, 112.0f, window->CenterY() + 168.0f, 0.0f);

    // direita antes e depois do gol
    Wall* wallRightUp = new Wall(20.0f, 200.0f, window->Width() - 115.0f, window->CenterY() - 170.0f, 0.0f);
    Wall* wallRightDown = new Wall(20.0f, 200.0f, window->Width() - 115.0f, window->CenterY() + 168.0f, 0.0f);

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
    this->ball = new Ball(this);
    scene->Add(ball, MOVING);

    // cria placar
    this->score = new Score();
    scene->Add(score, STATIC);

    goalLeft = new Goal(LEFT, 2);
    goalRight = new Goal(RIGHT, 2);

    scene->Add(goalLeft, STATIC);
    scene->Add(goalRight, STATIC);

    // define estado do jogo
    currentGameState = PAUSED;
}
// ------------------------------------------------------------------------------

void Level2::OnGoal(uint goalSide) {
    mcQueen->Reset();
    hudson->Reset();
    if (goalSide == LEFT) {
        CopaBrequim::mcQueenScore++;
        CopaBrequim::audio->Volume(MCQUEEN_GOAL, 2.0f);
		CopaBrequim::audio->Play(MCQUEEN_GOAL);
    }
    else {
        CopaBrequim::hudsonScore++;
		CopaBrequim::audio->Volume(HUDSON_GOAL, 2.0f);
		CopaBrequim::audio->Play(HUDSON_GOAL);
    }
    ball->Reset();
    score->Stop();
    currentGameState = PAUSED;
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
    delete CopaBrequim::audio;
}