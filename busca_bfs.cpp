#include "busca_bfs.h"
#include "interface.h"
#include <iostream>

BuscaBFS::BuscaBFS(int limite_max) : total_estados_visitados(0), limite_profundidade(limite_max) {}

bool BuscaBFS::buscar(Estado estado_inicial)
{
    total_estados_visitados = 0;

    std::cout << "\n=== BUSCA EM LARGURA (BFS) OTIMIZADA ===" << std::endl;
    std::cout << "Explorando estados por niveis de profundidade..." << std::endl;
    std::cout << "Limite de profundidade: " << limite_profundidade << " movimentos" << std::endl;

    // Usar o MOTOR DE BUSCA com FilaBFSLimitada para evitar crash
    auto estrutura = std::make_unique<FilaBFSLimitada>(limite_profundidade);
    MotorBusca motor(std::move(estrutura));

    std::cout << "\nIniciando busca em largura..." << std::endl;
    bool encontrou = motor.executarBusca(estado_inicial);
    total_estados_visitados = motor.getContadorEstados();

    if (encontrou)
    {
        std::cout << "\nSolucao encontrada com BFS!" << std::endl;
        std::cout << "Total de estados visitados: " << total_estados_visitados << std::endl;
    }
    else
    {
        std::cout << "\nNenhuma solucao encontrada com BFS no limite de " << limite_profundidade << " movimentos." << std::endl;
        std::cout << "Total de estados visitados: " << total_estados_visitados << std::endl;
        std::cout << "Tente aumentar o limite ou usar DFS iterativo." << std::endl;
    }

    return encontrou;
}

int BuscaBFS::getTotalEstadosVisitados() const
{
    return total_estados_visitados;
}

bool BuscaBFS::buscarComRetorno(Estado estado_inicial, Estado &estado_resolvido)
{
    total_estados_visitados = 0;

    std::cout << "\n=== BUSCA EM LARGURA (BFS) OTIMIZADA ===" << std::endl;
    std::cout << "Explorando estados por niveis de profundidade..." << std::endl;
    std::cout << "Limite de profundidade: " << limite_profundidade << " movimentos" << std::endl;

    // Usar o MOTOR DE BUSCA com FilaBFSLimitada para evitar crash
    auto estrutura = std::make_unique<FilaBFSLimitada>(limite_profundidade);
    MotorBusca motor(std::move(estrutura));

    std::cout << "\nIniciando busca..." << std::endl;
    bool encontrou = motor.executarBuscaComRetorno(estado_inicial, estado_resolvido);
    total_estados_visitados = motor.getContadorEstados();

    if (encontrou)
    {
        std::cout << "\nSolucao encontrada com BFS!" << std::endl;
        std::cout << "Total de estados visitados: " << total_estados_visitados << std::endl;
    }
    else
    {
        std::cout << "\nNenhuma solucao encontrada com BFS no limite de " << limite_profundidade << " movimentos." << std::endl;
        std::cout << "Total de estados visitados: " << total_estados_visitados << std::endl;
        std::cout << "Tente aumentar o limite ou usar DFS iterativo." << std::endl;
    }

    return encontrou;
}

void BuscaBFS::setLimiteProfundidade(int limite)
{
    limite_profundidade = limite;
}
