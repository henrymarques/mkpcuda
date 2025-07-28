#ifndef __INDIVIDUO_H
#define __INDIVIDUO_H

#include "Mochila.h"

class Individuo
{
    float _fitness;
    int _hash;
    int* _itens;

public:
    ~Individuo()
    {
        delete[] _itens;
    }

    Individuo() :
        _fitness{0.0},
        _hash{0},
        _itens(new int[mochila::qtdItens]) {}

    int hash() const { return _hash; }
    float fitness() const { return _fitness; }
};
#endif