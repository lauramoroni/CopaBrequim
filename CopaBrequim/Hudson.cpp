/**********************************************************************************
// Hudson (C�digo Fonte)
//
// Cria��o:     15 Jun 2025
// Compilador:  Visual C++ 2022
//
// Descri��o:   Define o personagem jog�vel Hudson
//
**********************************************************************************/

#include "Hudson.h"
#include "CopaBrequim.h"
#include "Ball.h"
#include "MCQueen.h"
#include "Wall.h"

// ---------------------------------------------------------------------------------

Hudson::Hudson(char up, char right, char down, char left, char init_side)
{
    // inicializa anima��o 
    carSprite = new Sprite("Resources/hudson.png");

    // cria bounding box
    Point carVertex[4] = {
        Point(-16.0f, -25.0f),  // ponto superior esquerdo
        Point(16.0f, -25.0f),  // ponto superior direito
        Point(16.0f,  25.0f),  // ponto inferior direito
        Point(-16.0f,  25.0f)   // ponto inferior esquerdo
    };

    BBox(new Poly(carVertex, 4));

    // posi��o inicial 
    initial_side = toupper(init_side);
    if (initial_side == 'L')
        MoveTo(window->CenterX() - 250, window->CenterY());
    else if (initial_side == 'R')
        MoveTo(window->CenterX() + 250, window->CenterY());

    // escala e rota��o 
    ScaleTo(1.5f);

    // inicializa dire��o e velocidade 
    if (initial_side == 'L') {
        RotateTo(90.0f);
        direction.RotateTo(0.0f);  // esquerda
    }
    else if (initial_side == 'R') {
        RotateTo(270.0f);
        direction.RotateTo(180.0f);    // direita
    }

    direction.ScaleTo(10.0f);
    speed.ScaleTo(0.0f);

    // atribui teclas de controle
    this->up = up;
    this->right = right;
    this->down = down;
    this->left = left;

    // tipo do objeto
    type = CAR;

    // Sounds
    CopaBrequim::audio->Add(HUDSON_ENGINE, "Resources/Audio/hudson_engine.wav");
    CopaBrequim::audio->Volume(HUDSON_ENGINE, MIN_ENGINE_VOLUME);
    CopaBrequim::audio->Frequency(HUDSON_ENGINE, MIN_ENGINE_FREQ);
    CopaBrequim::audio->Play(HUDSON_ENGINE, true);
}

// ---------------------------------------------------------------------------------

Hudson::~Hudson()
{
    CopaBrequim::audio->Stop(HUDSON_ENGINE);
    delete carSprite;
}

// ---------------------------------------------------------------------------------

void Hudson::Start()
{
    // inicia o carro
    started = true;
}

// ---------------------------------------------------------------------------------

void Hudson::Forward()
{
    // impulsiona para frente
    direction.ScaleTo(ACCELERATION * gameTime);
    speed.Add(direction);
}

// ---------------------------------------------------------------------------------

void Hudson::Backward()
{
    // impulsiona para tr�s
    Vector thrust;
    thrust.RotateTo(direction.Angle() < 180 ? direction.Angle() + 180.0f : direction.Angle() - 180.0f);
    thrust.ScaleTo(ACCELERATION * 1.5f * gameTime);
    speed.Add(thrust);
}

// ---------------------------------------------------------------------------------

void Hudson::Rotate(float angle)
{
    // ajusta a rota��o para depender da velocidade
    angle = angle * (speed.Magnitude() / YAW_RESISTANCE);  // quanto maior o YAW_RESISTANCE, menor a velocidade de rota��o

    // rotaciona objeto e vetor
    Object::Rotate(angle);
    direction.Rotate(angle);

    if (!window->KeyDown(VK_SHIFT)) // K � a tecla de drift
        speed.Rotate(angle);  // mant�m a velocidade na dire��o atual
}

// -------------------------------------------------------------------------------

void Hudson::Update()
{
	if (!started)
		return;


    // deslocamento padr�o
    float delta = 100 * gameTime;

    // vetor de atrito
	// - atua na dire��o da velocidade, sentido oposto
	// - quanto mais perto de 0 maior a conserva��o da velocidade
    // - quanto maior a diferen�a entre a dire��o e a velocidade, maior a perda de velocidade (derrapagem)
    float friction_factor = -0.998f - (abs(speed.Angle() - direction.Angle()) / SKIDDING_ANGLE);
    Vector friction_vector{ speed.Angle(), friction_factor * speed.Magnitude() * gameTime };
    speed.Add(friction_vector);
    if (speed.Magnitude() > MAXSPEED)
        speed.ScaleTo(MAXSPEED);

    // rotaciona
    if (window->KeyDown(right))
        Rotate(delta);
    if (window->KeyDown(left))
        Rotate(-delta);

    // impulsiona
    if (window->KeyDown(up))
        Forward();
    if (window->KeyDown(down))
        Backward();

	// audio: ajusta o volume e frequencia do motor dependendo da velocidade
	CopaBrequim::audio->Volume(HUDSON_ENGINE, 0.1 + speed.Magnitude() / MAXSPEED);
	CopaBrequim::audio->Frequency(HUDSON_ENGINE, 0.2f + speed.Magnitude() / MAXSPEED);
    
    // in�rcia desloca constantemente atrav�s do vetor speed
    Translate(speed.XComponent() * 0.1f * delta, -speed.YComponent() * 0.1f * delta);

    // faz o carro girar ao redor da tela
    if (x + 24.0f < 0)
        MoveTo(window->Width() + 24.0f, y);
    if (x - 24.0f > window->Width())
        MoveTo(-24.0f, y);
    if (y + 24.0f < 0)
        MoveTo(x, window->Height() + 24.0f);
    if (y - 24.0f > window->Height())
        MoveTo(x, -24.0f);
}

// -------------------------------------------------------------------------------

void Hudson::Draw()
{
    // desenha o carro
    carSprite->Draw(x, y, Layer::LOWER, scale, rotation);
}

// -------------------------------------------------------------------------------

void Hudson::OnCollision(Object* obj) {
    if (obj->Type() == CAR)
    {
        Hudson* carA = this;
        MCQueen* carB = static_cast<MCQueen*>(obj);

        // �ngulo formado pela linha que interliga os centros
        Point pA{ carA->X(), carA->Y() };
        Point pB{ carB->X(), carB->Y() };
        float angleA = Line::Angle(pA, pB);
        float angleB = angleA + 180.0f;

        // mant�m �ngulo na faixa de 0 a 359 graus
        if (angleB > 360)
            angleB -= 360.0f;

        // vetores gerados no impacto
        Vector impactA{ angleA, 0.05f * carA->speed.Magnitude() };
        Vector impactB{ angleB, 0.05f * carB->speed.Magnitude() };

        // adiciona vetor impacto � velocidade
        carA->speed.Add(impactB);
        carB->speed.Add(impactA);
    }
    else if (obj->Type() == BALL)
    {
        // bola colidiu com o carro
        Ball* ball = static_cast<Ball*>(obj);

        // �ngulo formado pela linha que interliga os centros
        Point pA{ x, y };
        Point pB{ ball->X(), ball->Y() };
        float angleA = Line::Angle(pA, pB);
		float angleB = angleA + 180.0f;

        // vetor de impacto
		Vector impactA{ angleA, 0.60f * speed.Magnitude() };
		Vector impactB{ angleB, 0.0005f * ball->speed.Magnitude() };

		if (impactA.Magnitude() < ball->speed.Magnitude())
			impactA.ScaleTo(ball->speed.Magnitude());

        // adiciona vetor impacto � velocidade da bola
		this->speed.Add(impactB);
        ball->speed.Add(impactA);
    }
    else if (obj->Type() == WALL)
    {
        Wall* wall = static_cast<Wall*>(obj);

        // C�lculo da normal da colis�o

        float vec_x = this->X() - wall->X();
        float vec_y = -(this->Y() - wall->Y());

        // Eixos da parede (paredes com rota��o ainda t� bugado)
        Vector wallAxisX(0, 1);
        wallAxisX.RotateTo(wall->Angle());

        Vector wallAxisY(90, 1);
        wallAxisY.RotateTo(wall->Angle() + 90.0f);

        Vector normal;

        float projX = (vec_x * wallAxisX.XComponent()) + (vec_y * wallAxisX.YComponent());
        float projY = (vec_x * wallAxisY.XComponent()) + (vec_y * wallAxisY.YComponent());

        if (abs(projX) / wall->Width() > abs(projY) / wall->Length())
        {
            normal = wallAxisX;
            if (projX < 0) normal.Rotate(180);
        }
        else
        {
            normal = wallAxisY;
            if (projY < 0) normal.Rotate(180);
        }

        // Vetor de rea��o � colis�o

        float elasticity = 0.25f;
        Vector v = this->speed;
        float j = -(1 + elasticity) * Vector::Dot(v, normal);
        Vector impulse = normal;
        impulse.ScaleTo(j);
        this->speed.Add(impulse);

        // Corre��o final de posi��o
        float push_factor = 1.0f;
        Translate(normal.XComponent() * push_factor, -normal.YComponent() * push_factor);
    }
}

// ----------------------------------------------------------------------------------

void Hudson::Reset()
{
    // reinicia o carro
    started = false;

    // inicializa dire��o e velocidade 
    if (initial_side == 'L') {
        RotateTo(90.0f);
        direction.RotateTo(0.0f);  // esquerda
        MoveTo(window->CenterX() - 250, window->CenterY());
    }
    else if (initial_side == 'R') {
        RotateTo(270.0f);
        direction.RotateTo(180.0f);    // direita
        MoveTo(window->CenterX() + 250, window->CenterY());
    }

    direction.ScaleTo(10.0f);
    speed.ScaleTo(0.0f);

    // Engine default audio
    CopaBrequim::audio->Volume(HUDSON_ENGINE, MIN_ENGINE_VOLUME);
	CopaBrequim::audio->Frequency(HUDSON_ENGINE, MIN_ENGINE_FREQ);
}