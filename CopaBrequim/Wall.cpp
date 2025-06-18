#include "Wall.h"
#include "Ball.h"

// ---------------------------------------------------------------------------------

Wall::Wall(float width, float lenght, float posX, float posY, float angle)
{
	this->width = width;
	this->lenght = lenght;

	Point wallVertex[4] = {
		Point(-width / 2.0f, -lenght / 2.0f),  // ponto superior esquerdo
		Point(width / 2.0f, -lenght / 2.0f),   // ponto superior direito
		Point(width / 2.0f, lenght / 2.0f),    // ponto inferior direito
		Point(-width / 2.0f, lenght / 2.0f)    // ponto inferior esquerdo
	};

	// cria bounding box
	BBox(new Poly(wallVertex, 4));

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