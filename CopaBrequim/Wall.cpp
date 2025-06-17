#include "Wall.h"

// ---------------------------------------------------------------------------------

Wall::Wall(float width, float lenght, float posX, float posY, float angle)
{
	this->width = width;
	this->lenght = lenght;

	BBox(new Rect(-lenght / 2.0f, -width / 2.0f, lenght, width)); // cria bounding box retangular

    // posição inicial da plataforma
    MoveTo(posX, posY, Layer::UPPER);

	// escala e rotação
	RotateTo(angle);

	type = WALL;
}

Wall::~Wall(){}

void Wall::OnCollision(Object* obj){}

void Wall::Update(){}

void Wall::Draw(){}