/**********************************************************************************
// GoalAnimation (Arquivo de Cabeçalho)
//
// Criação:     17 Jun 2025
// Atualização: 17 Jun 2025
// Compilador:  Visual C++ 2022
//
// Descrição:   Animação de gol do jogo Copa Brequim
//
/**********************************************************************************/

#ifndef COPABREQUIM_GOALANIMATION_H
#define COPABREQUIM_GOALANIMATION_H

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // animação de sprites

class GoalAnimation : Object {
private:
	TileSet* tileset = nullptr;        // folha de sprites do gol
	Animation* anim = nullptr;         // animação do gol

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