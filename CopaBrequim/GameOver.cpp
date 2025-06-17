
#include "CopaBrequim.h"

#include "Engine.h"
#include "GameOver.h"
#include "Home.h"
#include "Sprite.h"

// ----------------------------------------------------------------------

void GameOver::Init()
{
	font = new Font("Resources/font/Tahoma14b.png");
	font->Spacing("Resources/font/Tahoma14b.dat");

	if (CopaBrequim::mcQueenScore > CopaBrequim::hudsonScore)
		backg = new Sprite("Resources/Background/mcqueen_winner.png");
	else if (CopaBrequim::hudsonScore > CopaBrequim::mcQueenScore)
		backg = new Sprite("Resources/Background/hudson_winner.png");
	else
		backg = new Sprite("Resources/Background/draw.png");

}

// ----------------------------------------------------------------------


void GameOver::Update()
{
	if (window->KeyPress(VK_ESCAPE)) {
        Engine::Next<Home>();
		return;
	}
}

// ----------------------------------------------------------------------

void GameOver::Draw()
{
	Color gray{ 0.70f, 0.70f, 0.70f, 1.0f };

    backg->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
	font->Draw(window->CenterX() - 240.0f, window->CenterY() - 10.0f, std::to_string(CopaBrequim::mcQueenScore), gray);
	font->Draw(window->CenterX() + 240.0f, window->CenterY() - 10.0f, std::to_string(CopaBrequim::hudsonScore), gray);

}

// ----------------------------------------------------------------------
void GameOver::OnGoal(bool foo) {

}
// ----------------------------------------------------------------------

void GameOver::Finalize()
{
    delete backg;
}

// ----------------------------------------------------------------------
