/**********************************************************************************
// Player (Código Fonte)
//
// Criação:     12 jun 2025
// Atualização: 13 jun 2025
// Compilador:  Visual C++ 2022
//
// Descrição:   Player do jogo Copa Brequim
//
**********************************************************************************/

#include "CopaBrequim.h"
#include "Player1.h"
// ---------------------------------------------------------------------------------

//TODO receber um objeto sprites no construtor
Player1::Player1(const PlayerSpritesPath& sprites, bool isp1) {
    spriteU = new Sprite(sprites.up);
    spriteD = new Sprite(sprites.down);
    spriteL = new Sprite(sprites.left);
    spriteR = new Sprite(sprites.right);
    spriteUR = new Sprite(sprites.upRight);
    spriteUL = new Sprite(sprites.upLeft);
    spriteDR = new Sprite(sprites.downRight);
    spriteDL = new Sprite(sprites.downLeft);

    isPlayer1 = isp1;

    BBox(new Rect(-26, -20, 26, 20));

    // estado inicial do player
    MoveTo(spriteL->Width() + 150.f, window->CenterY());

    // type = PLAYER; onde ele define isso?

}

// ---------------------------------------------------------------------------------

Player1::~Player1() {
    delete spriteU;
    delete spriteD;
    delete spriteL;
    delete spriteR;

    delete spriteUR;
    delete spriteUL;
    delete spriteDR;
    delete spriteDL;
}

// ---------------------------------------------------------------------------------

void Player1::Stop()
{
    currState = STOPPED;
    velX = 0;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Player1::Up()
{
    currState = UP;
    velX = 0;
    velY = -p1MainVelocity;
}

// ---------------------------------------------------------------------------------

void Player1::Down()
{
    currState = DOWN;
    velX = 0;
    velY = p1MainVelocity;
}

// ---------------------------------------------------------------------------------

void Player1::Left()
{
    currState = LEFT;
    velX = -p1MainVelocity;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Player1::Right()
{
    currState = RIGHT;
    velX = p1MainVelocity;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Player1::Start() {
    started = true;
}

void Player1::Update() {
    if (started) {
        if (window->KeyDown(VK_LEFT))
        {
            Left();
            Translate(velX * gameTime, velY * gameTime);
        }

        if (window->KeyDown(VK_RIGHT))
        {
            Right();
            Translate(velX * gameTime, velY * gameTime);
        }

        if (window->KeyDown(VK_UP))
        {
            Up();
            Translate(velX * gameTime, velY * gameTime);
        }

        if (window->KeyDown(VK_DOWN))
        {
            Down();
            Translate(velX * gameTime, velY * gameTime);
        }

        if (window->KeyDown(VK_UP) && window->KeyDown(VK_RIGHT)) {
            currState = UPRIGHT;

            velX = p1MainVelocity;
            velY = -p1MainVelocity;

            float magnitude = sqrt(velX * velX + velY * velY);
            velX = velX / (magnitude * 0.707f);
            velY = velY / (magnitude * 0.707f);

            Translate(velX * gameTime, velY * gameTime);
        }

        if (window->KeyDown(VK_UP) && window->KeyDown(VK_LEFT)) {
            currState = UPLEFT;

            velX = -p1MainVelocity;
            velY = -p1MainVelocity;

            float magnitude = sqrt(velX * velX + velY * velY);
            velX = velX / (magnitude * 0.707f);
            velY = velY / (magnitude * 0.707f);

            Translate(velX * gameTime, velY * gameTime);
        }

        if (window->KeyDown(VK_DOWN) && window->KeyDown(VK_RIGHT)) {
            currState = DOWNRIGHT;

            velX = p1MainVelocity;
            velY = p1MainVelocity;

            float magnitude = sqrt(velX * velX + velY * velY);
            velX = velX / (magnitude * 0.707f);
            velY = velY / (magnitude * 0.707f);

            Translate(velX * gameTime, velY * gameTime);
        }

        if (window->KeyDown(VK_DOWN) && window->KeyDown(VK_LEFT)) {
            currState = DOWNLEFT;

            velX = -p1MainVelocity;
            velY = p1MainVelocity;

            float magnitude = sqrt(velX * velX + velY * velY);
            velX = velX / (magnitude * 0.707f);
            velY = velY / (magnitude * 0.707f);

            Translate(velX * gameTime, velY * gameTime);
        }

        // mantém player dentro da tela por redesenhar ele do outro lado
        if (x + 33 < 0)
            MoveTo(window->Width() + 20.f, Y());

        if (x - 20 > window->Width())
            MoveTo(-20.0f, Y());

        if (Y() + 20 < 0)
            MoveTo(x, window->Height() + 20.0f);

        if (Y() - 20 > window->Height())
            MoveTo(x, -20.0f);
    }
}

// ---------------------------------------------------------------------------------

void Player1::OnCollision(Object* obj)
{

}

// ---------------------------------------------------------------------------------
void Player1::Draw() {

    switch (currState) {
    case STOPPED: spriteR->Draw(x, y, Layer::UPPER); break;

    case UP: spriteU->Draw(x, y, Layer::UPPER); break;
    case DOWN: spriteD->Draw(x, y, Layer::UPPER); break;
    case LEFT: spriteL->Draw(x, y, Layer::UPPER); break;
    case RIGHT: spriteR->Draw(x, y, Layer::UPPER); break;

    case UPRIGHT: spriteUR->Draw(x, y, Layer::UPPER); break;
    case DOWNRIGHT: spriteDR->Draw(x, y, Layer::UPPER); break;
    case UPLEFT: spriteUL->Draw(x, y, Layer::UPPER); break;
    case DOWNLEFT: spriteDL->Draw(x, y, Layer::UPPER); break;
    }
}

// ---------------------------------------------------------------------------------

void Player1::Reset() {
    MoveTo(spriteL->Width() + 150.f, window->CenterY());
    started = false;
    currState = STOPPED;
    velX = 0;
	velY = 0;
}