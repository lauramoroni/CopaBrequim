/**********************************************************************************
// CopaBrequim (Arquivo de Cabeçalho)
//
// Criação:     10 Jun 2025
// Atualização: 
// Compilador:  Visual C++ 2022
//
// Descrição:   Jogo estilo plataforma usando a engine do curso
//
**********************************************************************************/

#ifndef _COPABREQUIM_H_
#define _COPABREQUIM_H_

// ---------------------------------------------------------------------------------

#include "Game.h"
#include "Audio.h"
#include "Resources.h"
#include "Sprite.h"
#include "Scene.h"
#include "Font.h"

// ------------------------------------------------------------------------------

enum CopaBrequimObjects { CAR, BALL, STATIC_BARRIERS, MOVING_BARRIERS }; 
	// static barriers = obstaculos estaticos, como paredes, trave, pilastres etc  
	// moving barriers = obstaculos em movimentos, como um carro ou uma barra se movimentando na tela pra atrapalhar os players

// ------------------------------------------------------------------------------

class CopaBrequim : public Game
{
private:
	Sprite* backg = nullptr;       // pano de fundo
	Sprite* keyMap = nullptr;      // caixa para placar
	bool viewBBox = false;
	Font* font = nullptr;

public:
	static Scene* scene;           // cena do jogo
	static Audio* audio;           // sistema de áudio

	void Init();
	void Update();
	void Draw();
	void Finalize();
};

// ------------------------------------------------------------------------------

#endif