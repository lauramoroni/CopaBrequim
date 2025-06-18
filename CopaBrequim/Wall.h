#ifndef _WALL_H_
#define _WALL_H_

// ---------------------------------------------------------------------------------

#include "Object.h"                         // interface de um objeto
#include "Sprite.h"                        // desenha animação
#include "Types.h"
#include "CopaBrequim.h"

// ---------------------------------------------------------------------------------

class Wall : public Object
{
private:
	float width;
	float lenght;

public:
	Wall(float width, float lenght, float posX, float posY, float angle);            // construtor
	~Wall();                                // destrutor
	void OnCollision(Object* obj);         // resolução da colisão
	void Update();                          // atualização 
	void Draw();                            // desenho
	
	float Width() const { return width; }
	float Length() const { return lenght; }
	float Angle() const { return rotation; }
};

#endif