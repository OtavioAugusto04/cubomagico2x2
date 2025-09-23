#ifndef FUNCAO_AVALIADORA_H
#define FUNCAO_AVALIADORA_H

#include "estado.h"

// Funcao Avaliadora - determina se um estado e final (resolvido)
class FuncaoAvaliadora
{
public:
    static bool ehEstadoFinal(const Estado &estado);
    static int calcularHeuristica(const Estado &estado); // Para futuro A*

private:
    static bool faceResolvida(const std::vector<int> &cubo, int face);
};

#endif