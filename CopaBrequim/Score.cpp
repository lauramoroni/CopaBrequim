/**********************************************************************************
// Score (C�digo Fonte)
//
// Cria��o:     12 jun 2025
// Atualiza��o: 16 jun 2025
// Compilador:  Visual C++ 2022
//
// Descri��o:   Score do jogo Copa Brequim
//
**********************************************************************************/

#include "CopaBrequim.h"
#include "Score.h"
using namespace std;
// ---------------------------------------------------------------------------------

Score::Score() {

	font = new Font("Resources/font/Tahoma14b.png");
	font->Spacing("Resources/font/Tahoma14b.dat");

	// carrega placar
	keyMap = new Sprite("Resources/background/placar.png");
	
	// carrega mensagem
	pressEnter = new Sprite("Resources/background/press_space.png");
	
	mcQueen_score = 0;
	hudson_score = 0;

	timer = new Timer();
	
	MoveTo(window->CenterX(), 50.0f);
	timer->Reset(); // flusha o timer, permitindo que ele atualize o tempo corretamente
}

// ---------------------------------------------------------------------------------

Score::~Score() {
	timer->Stop();
	delete timer;
	delete font;
	delete keyMap;
	delete pressEnter;
}

// ---------------------------------------------------------------------------------

void Score::Reset() { // volta todos os elementos ao seu estado inicial
	mcQueen_score = 0;
	hudson_score = 0;
	timer->Stop();
	timer->Reset();
	timerOn = false;
	timeOver = false;
}
// ---------------------------------------------------------------------------------

void Score::Start() { // inicia o timer

	timerOn = true;
	// timer->Reset();
	timer->Start();
}

// ---------------------------------------------------------------------------------

void Score::Stop() { // pausa/para o timer
	timerOn = false;
	timer->Stop();
}

// ---------------------------------------------------------------------------------

void Score::Update() {
	if (timer->Elapsed(float(maxTime))) 
	{ // se o tempo decorrido excedeu o limite
		timer->Stop();
		timerOn = false;
		timeOver = true;
	}
} 

// ---------------------------------------------------------------------------------
void Score::Draw() {

	// desenha placar
	keyMap->Draw(window->CenterX(), window->Height() - 20.0f, Layer::FRONT);

	// desenha tempo e placar
	Color gray{ 0.70f, 0.70f, 0.70f, 1.0f };

	font->Draw(window->CenterX() - 130.0f, window->Height() - 4.0f, to_string(mcQueen_score), gray);
	font->Draw(window->CenterX() + 130.0f, window->Height() - 4.0f, to_string(hudson_score), gray);


	if (timerOn) { // atualiza o rel�gio da partida
		string elapsedTime = to_string(maxTime - (int)timer->Elapsed()); //TODO bug-fix: timer pausado n�o � exibido corretamente
		font->Draw(window->CenterX(), window->Height() - 14.0f, elapsedTime, gray, Layer::FRONT);
	}
	else {
		pressEnter->Draw(window->CenterX(), window->CenterY(), Layer::FRONT);
	}

}
// ---------------------------------------------------------------------------------