#include "Ball.h"
#include "Engine.h"
#include "Home.h"
#include "Level1.h"
#include "Level2.h"
#include "MCQueen.h"
#include "Hudson.h"
#include "Score.h"

// ------------------------------------------------------------------------------

void Level2::Init()
{
    // cria gerenciador de cena
    this->scene = new Scene();

    // cria background
    this->backg = new Sprite("Resources/Background/Level2.png"); // TO-DO: acrescentar imagem correta do level2

    // cria players
    this->mcQueen = new MCQueen(VK_UP, VK_RIGHT, VK_DOWN, VK_LEFT, 'R');
    scene->Add(mcQueen, MOVING);

    this->hudson = new Hudson('W', 'D', 'S', 'A', 'L');
    scene->Add(hudson, MOVING);

    // cria bola
    // adiciona bola na cena
    this->ball = new Ball();
    scene->Add(ball, MOVING);

    // cria placar
    this->score = new Score();
    scene->Add(score, STATIC);

    // define estado do jogo
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
        // volta para a tela de abertura
        Engine::Next<Home>();
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
        int scoreP1 = score->GetP1Score();
        int scoreP2 = score->GetP2Score();
        OutputDebugString("Gol do Hudson!");
        score->mcQueen_score = scoreP1 + 1;
        mcQueen->Reset();
        hudson->Reset();
        ball->Reset();
        score->Stop();
        currentGameState = PAUSED;
    }

    if (ball->X() < 0) { // se a bola bate na direita da tela
        int scoreP1 = score->GetP1Score();
        int scoreP2 = score->GetP2Score();
        OutputDebugString("Gol do McQueen!");
        score->hudson_score = scoreP2 + 1;
        mcQueen->Reset();
        hudson->Reset();
        ball->Reset();
        score->Stop();
        currentGameState = PAUSED;
    }

    if (score->GetP1Score() == 5 || score->GetP2Score() == 5 || score->timeOver) { // condições de fim de partida
        mcQueen->Reset();
        hudson->Reset();
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

void Level2::Finalize()
{
    delete backg;
    delete scene;
}

// ------------------------------------------------------------------------------