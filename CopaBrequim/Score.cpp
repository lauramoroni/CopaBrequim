/**********************************************************************************
// Score (Código Fonte)
//
// Criação:     12 jun 2025
// Atualização: 13 jun 2025
// Compilador:  Visual C++ 2022
//
// Descrição:   Score do jogo Copa Brequim
//
**********************************************************************************/

#include "CopaBrequim.h"
#include "Score.h"
using namespace std;
// ---------------------------------------------------------------------------------

Score::Score() {
	timer = new Timer();

	font = new Font("Resources/tahoma.png");
	font->Spacing("Resources/tahoma.dat");
	font->Spacing(60); // hard coded pra essa fonte, ainda tá bugado quando chega nos single digits
	p1_score = 0;
	p2_score = 0;

	MoveTo(window->CenterX(), 50.0f);
	timer->Reset(); // flusha o timer, permitindo que ele atualize o tempo corretamente
}

// ---------------------------------------------------------------------------------

Score::~Score() {
	timer->Stop();
	delete timer;
	delete font;
}

// ---------------------------------------------------------------------------------

void Score::Reset() { // volta todos os elementos ao seu estado inicial
	p1_score = 0;
	p2_score = 0;
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
	if (timer->Elapsed(maxTime)) { // se o tempo decorrido excedeu o limite
		timer->Stop();
		timerOn = false;
		timeOver = true;

	}
} 

// ---------------------------------------------------------------------------------
void Score::Draw() {
	Color white( 1.0f, 1.0f, 1.0f, 1.0f );
	Color red(0.83f, 0.32f, 0.29f, 1.0f);
	Color blue(0.31f, 0.37f, 0.58f, 1.0f);

	font->Draw(x - 80, y, to_string(p1_score), red, Layer::FRONT, 0.4); // 0.5 na courier
	font->Draw(x + 120, y, to_string(p2_score), blue, Layer::FRONT, 0.4);

	if (timerOn) { // atualiza o relógio da partida
		string elapsedTime = to_string(maxTime - (int)timer->Elapsed()); //TODO bug-fix: timer pausado não é exibido corretamente
		font->Draw(x, y, elapsedTime, white, Layer::FRONT, 0.4); 
	} else {
		font->Draw(x, y, to_string(maxTime), white, Layer::FRONT, 0.4f);
		font->Draw(window->CenterX() - 125, window->CenterY(), "PRESS SPACE", white, Layer::FRONT, 0.5f); // 0.75 na courier
	}



	


}
// ---------------------------------------------------------------------------------