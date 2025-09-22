#include "funcao_avaliadora.h"

bool FuncaoAvaliadora::ehEstadoFinal(const Estado &estado)
{
    std::vector<int> cubo = estado.getCubo();

    // Verifica se todas as 6 faces estão resolvidas
    for (int face = 0; face < 6; face++)
    {
        if (!faceResolvida(cubo, face))
        {
            return false;
        }
    }
    return true;
}

bool FuncaoAvaliadora::faceResolvida(const std::vector<int> &cubo, int face)
{
    int primeira_cor = cubo[face * 4];
    for (int pos = 1; pos < 4; pos++)
    {
        if (cubo[face * 4 + pos] != primeira_cor)
        {
            return false;
        }
    }
    return true;
}

int FuncaoAvaliadora::calcularHeuristica(const Estado &estado)
{
    // Implementação futura para A*
    std::vector<int> cubo = estado.getCubo();
    int pecas_fora_lugar = 0;

    for (int face = 0; face < 6; face++)
    {
        if (!faceResolvida(cubo, face))
        {
            pecas_fora_lugar++;
        }
    }

    return pecas_fora_lugar;
}