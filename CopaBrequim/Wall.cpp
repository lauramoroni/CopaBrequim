#include "Wall.h"

// ---------------------------------------------------------------------------------

Wall::Wall(float width, float lenght, float posX, float posY, float angle)
{
	this->width = width;
	this->lenght = lenght;

	BBox(new Rect(-lenght / 2.0f, -width / 2.0f, lenght, width)); // cria bounding box retangular

    // posi��o inicial da plataforma
    MoveTo(posX, posY, Layer::UPPER);

	// escala e rota��o
	RotateTo(angle);

	type = WALL;
}

Wall::~Wall(){}

void Wall::OnCollision(Object* obj){}

void Wall::Update(){}

void Wall::Draw(){}