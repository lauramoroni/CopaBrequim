#include "Audio.h"
#include "Engine.h"
#include "Home.h"
#include "Level1.h"

void Home::Init()
{
    backg = new Sprite("Resources/Background/tela-abertura.png");

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

}

void Home::Draw()
{
    backg->Draw(window->CenterX(), window->CenterY(), Layer::BACK);

}

void Home::Finalize()
{
    delete backg;
}

void Home::OnGoal(bool foo)  {

}