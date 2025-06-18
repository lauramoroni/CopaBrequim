/**********************************************************************************
// Gol (Codigo Fonte)
//
// Criacao:     16 jun 2025
// Atualizacao: 16 jun 2025
// Compilador:  Visual C++ 2022
//
// Descricao:   Gol do jogo Copa Brequim
//
**********************************************************************************/

#include "CopaBrequim.h"
#include "Goal.h"
#include "Ball.h"

Goal::Goal(uint goalSide, int level) {
	if (level == 1) {
		if (goalSide == LEFT) {
			side = LEFT;
			MoveTo(window->CenterX() - 405, window->CenterY());
		}
		else {
			side = RIGHT;
			MoveTo(window->CenterX() + 405, window->CenterY());
		}
		BBox(new Rect(-10, -50, 10, 50));
	}
	if (level == 2) {
		if (goalSide == LEFT) {
			side = LEFT;
			MoveTo(window->CenterX() - 430, window->CenterY());
		}
		else {
			side = RIGHT;
			MoveTo(window->CenterX() + 430, window->CenterY());
		}
		BBox(new Rect(-10, -70, 10, 70)); // verificar medidas depois
	}

	type = GOAL;
}

Goal::~Goal() {

}
void Goal::Update() {

}
