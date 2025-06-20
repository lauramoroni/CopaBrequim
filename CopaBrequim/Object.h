/**********************************************************************************
// Object (Arquivo de Cabe�alho)
//
// Cria��o:     01 Out 2007
// Atualiza��o: 13 Set 2023
// Compilador:  Visual C++ 2022
//
// Descri��o:   Essa � a classe base para todos objetos do jogo.
//
//              Um objeto do jogo � qualquer coisa que poss�mos querer desenhar
//              ou interagir dentro do jogo. Por exemplo, um soldado, um pr�dio,
//              um proj�til, uma forma geom�trica, etc.
//
**********************************************************************************/

#ifndef _PROGJOGOS_OBJECT_H_
#define _PROGJOGOS_OBJECT_H_

// -----------------------------------------------------------------------------

#include "Types.h"              // usando os tipos personalizados da engine
#include "Game.h"               // representa��o de um jogo
#include "Window.h"             // janela usada para o jogo
#include "Geometry.h"           // todo objeto deve ter uma bounding box

// -----------------------------------------------------------------------------

class Object
{
private:
    float posX, posY, posZ;     // coordenadas do objeto
    float scaleFactor;          // escala do objeto
    float rotationAngle;        // rota��o do objeto
    Geometry* bbox;             // bounding box do objeto

protected:
    static Window*& window;    // janela do jogo
    static Game*& game;        // jogo em que o objeto est� inserido
    static float& gameTime;    // tempo do �ltimo quadro

    const float& x = posX;     // coordenada x do objeto
    const float& y = posY;     // coordenada y do objeto
    const float& z = posZ;     // coordenada z do objeto

    // valor da escala do objeto
    const float& scale = scaleFactor;

    // valor da rota��o do objeto
    const float& rotation = rotationAngle;

    uint type;                  // tipo do objeto

public:
    Object();                   // construtor
    virtual ~Object();          // destrutor virtual

    // ------------------------------------------------
    // fun��es virtuais    
    // ------------------------------------------------
    // podem ser sobrescritas na classe derivada
    // e chamadas corretamente mesmo usando um
    // ponteiro para a classe base

    // retorna coordenada x do objeto
    virtual float X() const;

    // retorna coordenada y do objeto
    virtual float Y() const;

    // retorna coordenada z do objeto
    virtual float Z() const;

    // retorna escala do objeto
    virtual float Scale() const;

    // retorna rota��o do objeto
    virtual float Rotation() const;

    // retorna tipo do objeto
    virtual uint Type() const;

    // muda a bounding box do objeto
    virtual void BBox(Geometry* bb);

    // retorna a bounding box do objeto
    virtual Geometry* BBox() const;

    // move o objeto por (deltaX, deltaY, deltaZ)
    virtual void Translate(float dx, float dy, float dz = 0.0f);

    // amplia/reduz objeto pelo fator de escala 
    virtual void Scale(float factor);

    // ajusta escala para o valor informado
    virtual void ScaleTo(float value);

    // rotaciona geometria por um �ngulo
    virtual void Rotate(float angle);

    // ajusta a rota��o para o valor informado
    virtual void RotateTo(float value);

    // move o objeto para as coordenadas (x,y,z) indicadas
    virtual void MoveTo(float px, float py, float pz);

    // move o objeto para as coordenadas (x,y) indicadas
    virtual void MoveTo(float px, float py);

    // faz a resolu��o de colis�o do objeto
    virtual void OnCollision(Object* obj);

    // ------------------------------------------------
    // fun��es virtuais pura    
    // ------------------------------------------------    
    // devem ser sobrescritas na classe derivada
    // fazem com que a classe seja abstrata

    // atualiza estado do objeto
    virtual void Update() = 0;

    // desenha o objeto na tela
    virtual void Draw() = 0;
};

// -----------------------------------------------------------------------------
// M�todos Inline

// retorna coordenada x do objeto
inline float Object::X() const
{
    return posX;
}

// retorna coordenada y do objeto
inline float Object::Y() const
{
    return posY;
}

// retorna coordenada z do objeto
inline float Object::Z() const
{
    return posZ;
}

inline float Object::Scale() const
{
    return scaleFactor;
}

inline float Object::Rotation() const
{
    return rotationAngle;
}

// retorna tipo do objeto
inline uint Object::Type() const
{
    return type;
}

// retorna a bounding box do objeto
inline Geometry* Object::BBox() const
{
    return bbox;
}

// -----------------------------------------------------------------------------

#endif


