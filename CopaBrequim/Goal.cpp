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

Goal::Goal(bool isLeftSide) {
	if (isLeftSide) {
		MoveTo(window->CenterX() - 335, window->CenterY());
	} else {
		MoveTo(window->CenterX() + 335, window->CenterY());
	}
	type = GOAL;
	
	BBox(new Rect(-10, -50, 10, 50)); // verificar medidas depois
}

Goal::~Goal() {

}
void Goal::Update() {

}
