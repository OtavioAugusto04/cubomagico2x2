#include "jogo.h"
#include "estrutura_dados.h"
#include "funcao_sucessora.h"
#include "funcao_avaliadora.h"
#include "busca_dfs_iterativa.h" // NOVO INCLUDE
#include <iostream>
#include <limits>
#include <memory>
#include <random>

Jogo::Jogo() : rodando(true)
{
    inicializarJogo();
}

void Jogo::inicializarJogo()
{
    estado_atual.resetar();
    motor = std::make_unique<MotorBusca>(std::make_unique<FilaJogador>());
}

void Jogo::iniciar()
{
    Interface::limparTela();
    std::cout << "Bem-vindo ao Simulador de Cubo Magico 2x2x2!" << std::endl;
    std::cout << "Estado, Funcao Sucessora e Funcao Avaliadora implementados." << std::endl;
    std::cout << "Agora com IA: Busca em Profundidade Limitada (Iterativa)!" << std::endl;

    while (rodando)
    {
        Interface::mostrarCubo(estado_atual);
        Interface::mostrarMenu();

        int opcao = lerOpcao();

        switch (opcao)
        {
        case 1:
            modoJogadorHumano();
            break;
        case 2:
            embaralharCubo();
            break;
        case 3:
            modoIA();
            break;
        case 4:
            resetarCubo();
            break;
        case 5:
            mostrarAjuda();
            break;
        case 6:
            verEmbaralhamento();
            break;
        case 7:
            rodando = false;
            std::cout << "Obrigado por jogar!" << std::endl;
            break;
        default:
            std::cout << "Opcao invalida! Tente novamente." << std::endl;
            std::cout << "Pressione Enter para continuar...";
            std::cin.ignore();
            std::cin.get();
            break;
        }

        if (rodando)
        {
            Interface::limparTela();
        }
    }
}

void Jogo::modoIA()
{
    Interface::limparTela();
    Interface::mostrarCubo(estado_atual);
    Interface::mostrarMenuIA();

    int opcao = lerOpcao();

    switch (opcao)
    {
    case 1:
        resolverComDFS();
        break;
    case 2:
        // Voltar ao menu principal
        break;
    default:
        std::cout << "Opcao invalida!" << std::endl;
        std::cout << "Pressione Enter para continuar...";
        std::cin.ignore();
        std::cin.get();
        break;
    }
}

void Jogo::resolverComDFS()
{
    Interface::limparTela();

    // Verificar se já está resolvido
    if (FuncaoAvaliadora::ehEstadoFinal(estado_atual))
    {
        std::cout << "O cubo ja esta resolvido!" << std::endl;
        std::cout << "Pressione Enter para continuar...";
        std::cin.ignore();
        std::cin.get();
        return;
    }

    std::cout << "Iniciando Busca em Profundidade Limitada (Iterativa)..." << std::endl;
    Interface::mostrarCubo(estado_atual);

    // Criar e executar DFS Iterativa
    BuscaDFSIterativa dfs(15); // Limite máximo de 15 movimentos

    std::cout << "\nIniciando busca..." << std::endl;
    bool sucesso = dfs.buscar(estado_atual);

    if (!sucesso)
    {
        std::cout << "\nNao foi possivel encontrar solucao com o limite estabelecido." << std::endl;
        std::cout << "Total de estados visitados: " << dfs.getTotalEstadosVisitados() << std::endl;
    }

    std::cout << "\nPressione Enter para voltar ao menu...";
    std::cin.ignore();
    std::cin.get();
}

void Jogo::modoJogadorHumano()
{
    Interface::limparTela();
    std::cout << "=== MODO JOGADOR HUMANO ===" << std::endl;
    std::cout << "Usando o LACO PRINCIPAL especificado no projeto." << std::endl;
    std::cout << "12 movimentos disponiveis: R R' L L' U U' D D' F F' B B'" << std::endl;
    std::cout << "\nVoce pode embaralhar manualmente ou resolver o cubo!" << std::endl;
    Interface::mostrarComandos();

    // Limpar apenas o caminho do jogador, manter embaralhamento
    estado_atual.limparCaminho();

    // Inicializar motor com estrutura para jogador humano
    motor = std::make_unique<MotorBusca>(std::make_unique<FilaJogador>());

    // EXECUTAR O LACO PRINCIPAL
    bool continuar = true;
    while (continuar)
    {
        std::cout << std::endl;
        Interface::mostrarCubo(estado_atual);

        // SÓ VERIFICAR SE ESTÁ RESOLVIDO SE O JOGADOR JÁ FEZ ALGUM MOVIMENTO
        bool jogador_fez_movimentos = !estado_atual.getCaminho().empty() || !estado_atual.getMovimentosEmbaralhamento().empty();

        if (jogador_fez_movimentos && FuncaoAvaliadora::ehEstadoFinal(estado_atual))
        {
            Interface::mostrarSolucao(estado_atual);
            std::cout << "\nPressione Enter para voltar ao menu...";
            std::cin.ignore();
            std::cin.get();
            break;
        }

        std::cout << "\nDigite um movimento (ou 'sair'): ";
        std::string comando = lerComando();

        if (comando == "sair")
        {
            continuar = false;
        }
        else if (processarMovimento(comando))
        {
            Interface::limparTela();
            std::cout << "=== MODO JOGADOR HUMANO ===" << std::endl;
            std::cout << "Movimento aplicado: " << comando << std::endl;
        }
        else
        {
            std::cout << "Movimento invalido! Use: R R' L L' U U' D D' F F' B B'" << std::endl;
        }
    }
}

bool Jogo::processarMovimento(const std::string &comando)
{
    std::vector<std::string> movimentos_validos = FuncaoSucessora::getTodosMovimentos();

    for (const auto &mov : movimentos_validos)
    {
        if (comando == mov)
        {
            estado_atual = FuncaoSucessora::aplicarMovimento(estado_atual, comando);
            return true;
        }
    }
    return false;
}

void Jogo::embaralharCubo()
{
    std::cout << "\nEmbaralhando o cubo..." << std::endl;

    estado_atual.resetar();

    std::vector<std::string> todos_movimentos = FuncaoSucessora::getTodosMovimentos();
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, todos_movimentos.size() - 1);

    int num_movimentos = 8;
    std::vector<std::string> movimentos_embaralhamento;

    for (int i = 0; i < num_movimentos; i++)
    {
        std::string movimento = todos_movimentos[dis(gen)];
        movimentos_embaralhamento.push_back(movimento);
        estado_atual.adicionarMovimentoEmbaralhamento(movimento);
    }

    for (const auto &movimento : movimentos_embaralhamento)
    {
        estado_atual = FuncaoSucessora::aplicarMovimento(estado_atual, movimento);
    }

    estado_atual.limparCaminho();

    std::cout << "Cubo embaralhado com " << movimentos_embaralhamento.size() << " movimentos aleatorios!" << std::endl;
    std::cout << "Use a opcao 6 se quiser ver quais foram os movimentos." << std::endl;
    std::cout << "Agora pode usar a opcao 3 para resolver com IA!" << std::endl;
    std::cout << "Pressione Enter para continuar...";
    std::cin.ignore();
    std::cin.get();
}

void Jogo::resetarCubo()
{
    std::cout << "\nResetando o cubo para o estado resolvido..." << std::endl;
    estado_atual.resetar();
    std::cout << "Cubo resetado com sucesso!" << std::endl;
    std::cout << "Pressione Enter para continuar...";
    std::cin.ignore();
    std::cin.get();
}

void Jogo::verEmbaralhamento()
{
    Interface::mostrarEmbaralhamento(estado_atual);
    std::cout << "\nPressione Enter para continuar...";
    std::cin.ignore();
    std::cin.get();
}

void Jogo::mostrarAjuda()
{
    Interface::mostrarComandos();
    std::cout << "\n=== FUNCIONALIDADES ===" << std::endl;
    std::cout << "> Cubo representado como vetor de 24 elementos" << std::endl;
    std::cout << "> Interface clara mostrando todas as faces" << std::endl;
    std::cout << "> 12 movimentos completos para todas as faces" << std::endl;
    std::cout << "> Embaralhamento automatico e manual" << std::endl;
    std::cout << "> Deteccao automatica de cubo resolvido" << std::endl;
    std::cout << "> IA: Busca em Profundidade Limitada (Iterativa)" << std::endl;
    std::cout << "\nPressione Enter para continuar...";
    std::cin.ignore();
    std::cin.get();
}

int Jogo::lerOpcao()
{
    int opcao;
    while (!(std::cin >> opcao))
    {
        std::cout << "Por favor, digite um numero valido: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return opcao;
}

std::string Jogo::lerComando()
{
    std::string comando;
    std::cin >> comando;
    return comando;
}