/**********************************************************************************
// Score (Arquivo de Cabe�alho)
//
// Cria��o:     14 Jun 2025
// Atualiza��o: 15 Jun 2025
// Compilador:  Visual C++ 2022
//
// Descri��o:   Score do jogo Copa Brequim
//
/**********************************************************************************/

#ifndef COPABREQUIM_SCORE_H
#define COPABREQUIM_SCORE_H

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // interface de Sprites
#include "Font.h"
#include "Timer.h"

class Score : public Object
{
private:
	Font * font = nullptr;
	Timer* timer = nullptr;
	Sprite* keyMap;      // caixa para placar 
	Sprite* pressEnter;      // caixa para placar 
	Sprite* tip;      // caixa para instru��es

public:
	const int maxTime = 180;			// tempo m�ximo da partida em segundos
	bool timerOn = false;				// verifica se o tempo est� rodando
	bool timeOver = false;				// verifica se acabou o tempo de partida

	Score();
	~Score();

	void Update();                      // atualiza��o do objeto
	void Start();						// inicia o rel�gio
	void Stop();						// para o rel�gio
	void Reset();						// reinicia o rel�gio e a pontua��o
	void Draw();                        // desenho do objeto
};

#endif