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
#include "Player2.h"
// ---------------------------------------------------------------------------------

//TODO receber um objeto sprites no construtor
Player2::Player2(const PlayerSpritesPath& sprites, bool isp1) {
    spriteU = new Sprite(sprites.up);
    spriteD = new Sprite(sprites.down);
    spriteL = new Sprite(sprites.left);
    spriteR = new Sprite(sprites.right);
    spriteUR = new Sprite(sprites.upRight);
    spriteUL = new Sprite(sprites.upLeft);
    spriteDR = new Sprite(sprites.downRight);
    spriteDL = new Sprite(sprites.downLeft);

    isPlayer1 = isp1;

        BBox(new Rect(-26, -24, 26, 24));
        MoveTo(window->CenterX(), spriteU->Height());

    // type = PLAYER; onde ele define isso?

}

// ---------------------------------------------------------------------------------

Player2::~Player2() {
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

void Player2::Stop()
{
    currState = STOPPED;
    velX = 0;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Player2::Up()
{
    currState = UP;
    velX = 0;
    velY = -p2MainVelocity;
}

// ---------------------------------------------------------------------------------

void Player2::Down()
{
    currState = DOWN;
    velX = 0;
    velY = p2MainVelocity;
}

// ---------------------------------------------------------------------------------

void Player2::Left()
{
    currState = LEFT;
    velX = -p2MainVelocity;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Player2::Right()
{
    currState = RIGHT;
    velX = p2MainVelocity;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Player2::Start() {
    started = true;
}

// ---------------------------------------------------------------------------------
void Player2::Update() {
    if (started) {
        if (window->KeyDown('A')) {
            Left();
            Translate(velX * gameTime, velY * gameTime);
        }
        if (window->KeyDown('D')) {
            Right();
            Translate(velX * gameTime, velY * gameTime);
        }
        if (window->KeyDown('W')) {
            Up();
            Translate(velX * gameTime, velY * gameTime);
        }
        if (window->KeyDown('S')) {
            Down();
            Translate(velX * gameTime, velY * gameTime);
        }
        if (window->KeyDown('W') && window->KeyDown('D')) {
            currState = UPRIGHT;

            velX = p2MainVelocity;
            velY = -p2MainVelocity;

            float magnitude = sqrt(velX * velX + velY * velY);
            velX = velX / (magnitude * 0.707f);
            velY = velY / (magnitude * 0.707f);

            Translate(velX * gameTime, velY * gameTime);
        }
        if (window->KeyDown('W') && window->KeyDown('A')) {
            currState = UPLEFT;

            velX = -p2MainVelocity;
            velY = -p2MainVelocity;

            float magnitude = sqrt(velX * velX + velY * velY);
            velX = velX / (magnitude * 0.707f);
            velY = velY / (magnitude * 0.707f);

            Translate(velX * gameTime, velY * gameTime);
        }
        if (window->KeyDown('S') && window->KeyDown('D')) {
            currState = DOWNRIGHT;

            velX = p2MainVelocity;
            velY = p2MainVelocity;

            float magnitude = sqrt(velX * velX + velY * velY);
            velX = velX / (magnitude * 0.707f);
            velY = velY / (magnitude * 0.707f);
            Translate(velX * gameTime, velY * gameTime);
        }
        if (window->KeyDown('S') && window->KeyDown('A')) {
            currState = DOWNLEFT;

            velX = -p2MainVelocity;
            velY = p2MainVelocity;

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

void Player2::OnCollision(Object* obj)
{

}

// ---------------------------------------------------------------------------------
void Player2::Draw() {

    switch (currState) {
    case STOPPED: spriteD->Draw(x, y, Layer::UPPER); break;

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
void Player2::Reset() {
    MoveTo(window->CenterX(), spriteU->Height());
    currState = STOPPED;
    velX = 0;
    velY = 0;
}