#include "busca_dfs_iterativa.h"
#include "interface.h"
#include <iostream>

BuscaDFSIterativa::BuscaDFSIterativa(int limite_max)
    : limite_maximo(limite_max), limite_atual(0), total_estados_visitados(0) {}

bool BuscaDFSIterativa::buscar(Estado estado_inicial)
{
    total_estados_visitados = 0;

    std::cout << "\n=== BUSCA EM PROFUNDIDADE LIMITADA (ITERATIVA) ===" << std::endl;
    std::cout << "Limite maximo: " << limite_maximo << " movimentos" << std::endl;

    // ITERATIVO: aumenta profundidade gradualmente
    for (limite_atual = 0; limite_atual <= limite_maximo; limite_atual++)
    {
        std::cout << "\n--- Tentando profundidade " << limite_atual << " ---" << std::endl;

        if (buscarComLimite(estado_inicial, limite_atual))
        {
            std::cout << "\nSolucao encontrada na profundidade " << limite_atual << "!" << std::endl;
            std::cout << "Total de estados visitados: " << total_estados_visitados << std::endl;
            return true;
        }

        std::cout << "Nenhuma solucao encontrada na profundidade " << limite_atual << std::endl;
    }

    std::cout << "\nNenhuma solucao encontrada ate profundidade " << limite_maximo << std::endl;
    std::cout << "Total de estados visitados: " << total_estados_visitados << std::endl;
    return false;
}

bool BuscaDFSIterativa::buscarComLimite(Estado estado_inicial, int limite)
{
    // Usar o MOTOR DE BUSCA com PilhaDFS limitada
    auto estrutura = std::make_unique<PilhaDFS>(limite);
    MotorBusca motor(std::move(estrutura));

    bool encontrou = motor.executarBusca(estado_inicial);
    total_estados_visitados += motor.getContadorEstados();

    return encontrou;
}

bool BuscaDFSIterativa::buscarComRetorno(Estado estado_inicial, Estado &estado_resolvido)
{
    total_estados_visitados = 0;

    std::cout << "\n=== BUSCA EM PROFUNDIDADE LIMITADA (ITERATIVA) ===" << std::endl;
    std::cout << "Limite maximo: " << limite_maximo << " movimentos" << std::endl;

    // ITERATIVO: aumenta profundidade gradualmente
    for (limite_atual = 0; limite_atual <= limite_maximo; limite_atual++)
    {
        std::cout << "\n--- Tentando profundidade " << limite_atual << " ---" << std::endl;

        // Usar o MOTOR DE BUSCA com PilhaDFS limitada
        auto estrutura = std::make_unique<PilhaDFS>(limite_atual);
        MotorBusca motor(std::move(estrutura));

        bool encontrou = motor.executarBuscaComRetorno(estado_inicial, estado_resolvido);
        total_estados_visitados += motor.getContadorEstados();

        if (encontrou)
        {
            std::cout << "\nSolucao encontrada na profundidade " << limite_atual << "!" << std::endl;
            std::cout << "Total de estados visitados: " << total_estados_visitados << std::endl;
            return true;
        }

        std::cout << "Nenhuma solucao encontrada na profundidade " << limite_atual << std::endl;
    }

    std::cout << "\nNenhuma solucao encontrada ate profundidade " << limite_maximo << std::endl;
    std::cout << "Total de estados visitados: " << total_estados_visitados << std::endl;
    return false;
}

int BuscaDFSIterativa::getTotalEstadosVisitados() const
{
    return total_estados_visitados;
}