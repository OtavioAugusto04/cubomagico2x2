#ifndef BUSCA_BFS_H
#define BUSCA_BFS_H

#include "estado.h"
#include "motor_busca.h"
#include "estrutura_dados.h"
#include <memory>

class BuscaBFS
{
private:
    int total_estados_visitados;
    int limite_profundidade;

public:
    BuscaBFS(int limite_max = 8); // Limite padrao de 8 movimentos

    bool buscar(Estado estado_inicial);
    bool buscarComRetorno(Estado estado_inicial, Estado &estado_resolvido);
    int getTotalEstadosVisitados() const;
    void setLimiteProfundidade(int limite);
};

#endif
