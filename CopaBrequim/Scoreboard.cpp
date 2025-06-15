#include "Ball.h"
#include "Engine.h"
#include "Home.h"
#include "Scoreboard.h"
#include "Scene.h"

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

    // cria gerenciador de cena
    //scene = new Scene();

    // carrega placar
    keyMap = new Sprite("Resources/background/placar.png");

}

// ------------------------------------------------------------------------------

void Scoreboard::Update()
{
	// atualiza temporizador
}

// ------------------------------------------------------------------------------

void Scoreboard::Draw()
{
    // desenha placar
    keyMap->Draw(window->CenterX(), window->Height() - 20.0f, Layer::FRONT);

	// desenha tempo e placar
    Color gray{ 0.70f, 0.70f, 0.70f, 1.0f };

    font->Draw(window->CenterX(), window->Height() - 14.0f, "01:43", gray);
    font->Draw(window->CenterX() - 130.0f, window->Height() - 4.0f, " 1 ", gray);
    font->Draw(window->CenterX() + 130.0f, window->Height() - 4.0f, " 0 ", gray);
}

// ------------------------------------------------------------------------------

void Scoreboard::Finalize()
{
    delete font;
    delete keyMap;
}

// ------------------------------------------------------------------------------