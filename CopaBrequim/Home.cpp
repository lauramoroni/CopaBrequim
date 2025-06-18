#include "Audio.h"
#include "Engine.h"
#include "Home.h"
#include "Level1.h"
#include "CopaBrequim.h"

void Home::Init()
{
    backg = new Sprite("Resources/Background/tela-abertura.png");
  
	  CopaBrequim::audio = new Audio();
	  CopaBrequim::audio->Add(INTRO, "Resources/Audio/life-is-a-highway.wav");
    CopaBrequim::audio->Play(INTRO);
}

void Home::Update()
{
    // sai do jogo com a tecla ESC
    if (ctrlKeyESC && window->KeyDown(VK_ESCAPE))
    {
        ctrlKeyESC = false;
        window->Close();
    }
    else if (window->KeyUp(VK_ESCAPE))
    {
        ctrlKeyESC = true;
    }


    if (window->KeyDown(VK_RETURN))
        Engine::Next<Level1>();
        return;

}

void Home::Draw()
{
    backg->Draw(window->CenterX(), window->CenterY(), Layer::BACK);

}

void Home::Finalize()
{
    delete backg;
    delete CopaBrequim::audio;
}
void Home::OnGoal(uint foo)  {

}