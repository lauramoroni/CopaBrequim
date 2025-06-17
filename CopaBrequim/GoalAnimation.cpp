/**********************************************************************************
// GoalAnimation (Codigo Fonte)
//
// Criacao:     17 jun 2025
// Atualizacao: 17 jun 2025
// Compilador:  Visual C++ 2022
//
// Descricao:   Animação de gol do jogo Copa Brequim
//
**********************************************************************************/

#include "CopaBrequim.h"
#include "GoalAnimation.h"

GoalAnimation::GoalAnimation() {
	tileset = new TileSet("Resources/goal.png", 394, 138, 3, 6);
	anim = new Animation(tileset, 0.120f, false);
	uint animFrames[9] = { 3,4,5,4,3,4,5,4,3 }; 
	anim->Add(0, animFrames, 9);

	MoveTo(window->CenterX(), window->CenterY(), Layer::UPPER);
}

GoalAnimation::~GoalAnimation() {
	delete anim;
	delete tileset;
}

void GoalAnimation::Update() {
	anim->NextFrame();
	if (anim->Inactive())
		CopaBrequim::scene->Delete();
}