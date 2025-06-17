/**********************************************************************************
// Goal (Arquivo de Cabe�alho)
//
// Cria��o:     16 Jun 2025
// Atualiza��o: 16 Jun 2025
// Compilador:  Visual C++ 2022
//
// Descri��o:   Gol do jogo Copa Brequim
//
/**********************************************************************************/

#ifndef COPABREQUIM_GOAL_H
#define COPABREQUIM_GOAL_H

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // interface de Sprites
#include "Animation.h"
#include "TileSet.h"                   

enum goalSide { LEFT, RIGHT, NONE };

class Goal : public Object
{
private:
	goalSide side = NONE;

public:
	Goal(uint goalSide, int level);
	~Goal();

	bool GetTeam() const;
	void Update();
	void Draw();
};
inline void Goal::Draw() {
}

inline bool Goal::GetTeam() const {
	return side;
}
#endif