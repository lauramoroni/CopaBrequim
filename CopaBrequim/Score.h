/**********************************************************************************
// Score (Arquivo de Cabeçalho)
//
// Criação:     14 Jun 2025
// Atualização: 15 Jun 2025
// Compilador:  Visual C++ 2022
//
// Descrição:   Score do jogo Copa Brequim
//
/**********************************************************************************/

#ifndef COPABREQUIM_SCORE_H
#define COPABREQUIM_SCORE_H

#include "Types.h"                      // tipos específicos da engine
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

public:
	
	int mcQueen_score;
	int hudson_score;						// pontuação dos jogadores
	const int maxTime = 180;			// tempo máximo da partida em segundos
	bool timerOn = false;				// verifica se o tempo está rodando
	bool timeOver = false;				// verifica se acabou o tempo de partida

	Score();
	~Score();

	void Update();                      // atualização do objeto
	void Start();						// inicia o relógio
	void Stop();						// para o relógio
	void Reset();						// reinicia o relógio e a pontuação
	int GetP1Score() const;              // retorna a pontuação do jogador 1
	int GetP2Score() const;              // retorna a pontuação do jogador 2
	void Draw();                        // desenho do objeto
};

inline int Score::GetP1Score() const
{
	return mcQueen_score;
}

inline int Score::GetP2Score() const
{
	return hudson_score;
}

#endif