#ifndef BUSCA_DFS_ITERATIVA_H
#define BUSCA_DFS_ITERATIVA_H

#include "estado.h"
#include "motor_busca.h"
#include "estrutura_dados.h"
#include <memory>

class BuscaDFSIterativa
{
private:
    int limite_maximo;
    int limite_atual;
    int total_estados_visitados;

public:
    BuscaDFSIterativa(int limite_max = 20);

    bool buscar(Estado estado_inicial);
    int getTotalEstadosVisitados() const;

private:
    bool buscarComLimite(Estado estado_inicial, int limite);
};

#endif