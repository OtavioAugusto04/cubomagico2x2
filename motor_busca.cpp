#include "motor_busca.h"
#include "interface.h"
#include <iostream>

MotorBusca::MotorBusca(std::unique_ptr<EstruturaAbstrata> estrutura_dados)
    : estrutura(std::move(estrutura_dados)), contador_estados(0) {}

bool MotorBusca::executarBusca(Estado estado_inicial)
{
    contador_estados = 0;
    estrutura->limpar();

    // 1. Adicionar estado na estrutura
    estrutura->adicionar(estado_inicial);

    // 2. Enquanto a estrutura nao estiver vazia:
    while (!estrutura->vazia())
    {

        // 3. Remover proximo estado da estrutura
        Estado estado_atual = estrutura->remover();
        contador_estados++;
        estado_atual.setEstadosVisitados(contador_estados);

        // 4. Avaliar estado
        // 5. SE estado final -> mostrar solucao e encerrar o programa
        if (FuncaoAvaliadora::ehEstadoFinal(estado_atual))
        {
            Interface::mostrarSolucao(estado_atual);
            return true;
        }

        // 6. Adicionar estados seguintes na estrutura
        adicionarEstadosSegintes(estado_atual);
    }

    // 7. Retornar "Sem solucao"
    std::cout << "Sem solucao encontrada!" << std::endl;
    return false;
}

void MotorBusca::adicionarEstadosSegintes(const Estado &estado_atual)
{
    auto sucessores = FuncaoSucessora::gerarSucessores(estado_atual);
    for (const auto &sucessor : sucessores)
    {
        estrutura->adicionar(sucessor);
    }
}

bool MotorBusca::executarBuscaComRetorno(Estado estado_inicial, Estado &estado_resolvido)
{
    contador_estados = 0;
    estrutura->limpar();

    // 1. Adicionar estado na estrutura
    estrutura->adicionar(estado_inicial);

    // 2. Enquanto a estrutura nao estiver vazia:
    while (!estrutura->vazia())
    {
        // 3. Remover proximo estado da estrutura
        Estado estado_atual = estrutura->remover();
        contador_estados++;
        estado_atual.setEstadosVisitados(contador_estados);

        // 4. Avaliar estado
        // 5. SE estado final -> retornar estado resolvido
        if (FuncaoAvaliadora::ehEstadoFinal(estado_atual))
        {
            estado_resolvido = estado_atual;
            Interface::mostrarSolucao(estado_atual);
            return true;
        }

        // 6. Adicionar estados seguintes na estrutura
        adicionarEstadosSegintes(estado_atual);
    }

    // 7. Retornar "Sem solucao"
    std::cout << "Sem solucao encontrada!" << std::endl;
    return false;
}

int MotorBusca::getContadorEstados() const
{
    return contador_estados;
}