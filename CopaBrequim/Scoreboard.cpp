#include "Ball.h"
#include "Engine.h"
#include "Home.h"
#include "Scoreboard.h"
#include "Scene.h"
#include "GameOver.h"
#include <iostream>
using namespace std;

// ------------------------------------------------------------------------------

Font* Scoreboard::font = nullptr;       // fonte para exibição de texto
Sprite* Scoreboard::keyMap = nullptr;  // caixa para placar
Timer* Scoreboard::timer = nullptr;    // temporizador para animação

// ------------------------------------------------------------------------------

void Scoreboard::Init()
{
    // cria fonte para exibição de texto
    font = new Font("Resources/font/Tahoma14b.png");
    font->Spacing("Resources/font/Tahoma14b.dat");

    /*
	// inicia temporizador
	timer = new Timer();
	timer->Start();
    */

    // carrega placar
    keyMap = new Sprite("Resources/background/placar.png");

}

// ------------------------------------------------------------------------------
void Scoreboard::Update()
{
    /*
	// atualiza temporizador
	currentTime = timer->Elapsed();
	cout << currentTime << " segundos" << std::endl;
    
	// sempre verificar se ja ultrapassou o tempo (3 min)
    if (currentTime >= 180.0f) {
		// fim do jogo
		timer->Stop();
		Engine::Next<GameOver>();
	}
    */
    
}

// ------------------------------------------------------------------------------

void Scoreboard::Draw()
{
    // desenha placar
    keyMap->Draw(window->CenterX(), window->Height() - 20.0f, Layer::FRONT);

	// desenha tempo e placar
    Color gray{ 0.70f, 0.70f, 0.70f, 1.0f };

	// texto "Tempo"
    /*
	string currentTimeText = to_string(currentTime);

    font->Draw(window->CenterX(), window->Height() - 14.0f, currentTimeText, gray);
    */
    font->Draw(window->CenterX() - 130.0f, window->Height() - 4.0f, "1", gray);
    font->Draw(window->CenterX() + 130.0f, window->Height() - 4.0f, "0", gray);
}

// ------------------------------------------------------------------------------

void Scoreboard::Finalize()
{
    delete font;
    delete keyMap;
    //delete timer;
}

// ------------------------------------------------------------------------------