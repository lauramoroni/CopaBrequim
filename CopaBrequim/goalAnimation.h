/**********************************************************************************
// GoalAnimation (Arquivo de Cabe�alho)
//
// Cria��o:     17 Jun 2025
// Atualiza��o: 17 Jun 2025
// Compilador:  Visual C++ 2022
//
// Descri��o:   Anima��o de gol do jogo Copa Brequim
//
/**********************************************************************************/

#ifndef COPABREQUIM_GOALANIMATION_H
#define COPABREQUIM_GOALANIMATION_H

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // anima��o de sprites

class GoalAnimation : Object {
private:
	TileSet* tileset = nullptr;        // folha de sprites do gol
	Animation* anim = nullptr;         // anima��o do gol

public:
	GoalAnimation();
	~GoalAnimation();

	void Update();
	void Draw();
};

// ---------------------------------------------------------------------------------
inline void GoalAnimation::Draw() {
	anim->Draw(x, y, z);
}
// ---------------------------------------------------------------------------------

#endif