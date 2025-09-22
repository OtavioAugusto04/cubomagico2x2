#include "jogo.h"
#include "movimentos.h"
#include <iostream>
#include <limits>
#include <random>

Jogo::Jogo() : rodando(true)
{
    inicializarJogo();
}

void Jogo::inicializarJogo()
{
    estado_atual.resetar();
}

void Jogo::iniciar()
{
    Interface::limparTela();
    std::cout << "Bem-vindo ao Simulador de Cubo Magico 2x2x2!" << std::endl;

    while (rodando)
    {
        Interface::mostrarCubo(estado_atual);
        Interface::mostrarMenu();

        int opcao = lerOpcao();

        switch (opcao)
        {
        case 1:
            modoJogo();
            break;
        case 2:
            embaralharCubo();
            break;
        case 3:
            resetarCubo();
            break;
        case 4:
            mostrarAjuda();
            break;
        case 5:
            verEmbaralhamento();
            break;
        case 6:
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

void Jogo::modoJogo()
{
    Interface::limparTela();
    std::cout << "=== MODO JOGO ===" << std::endl;
    std::cout << "12 movimentos disponiveis: R R' L L' U U' D D' F F' B B'" << std::endl;
    std::cout << "Voce pode embaralhar manualmente ou resolver o cubo!" << std::endl;
    Interface::mostrarComandos();

    estado_atual.limparCaminho();

    bool continuar = true;
    while (continuar)
    {
        std::cout << std::endl;
        Interface::mostrarCubo(estado_atual);

        bool tem_movimentos = !estado_atual.getCaminho().empty() || !estado_atual.getMovimentosEmbaralhamento().empty();

        if (tem_movimentos && estado_atual.isResolvido())
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
            std::cout << "=== MODO JOGO ===" << std::endl;
            std::cout << "Movimento aplicado: " << comando << std::endl;
        }
        else
        {
            std::cout << "=== MODO JOGO ===" << std::endl;
            std::cout << "Movimento invalido! Use: R R' L L' U U' D D' F F' B B'" << std::endl;
        }
    }
}

bool Jogo::processarMovimento(const std::string &comando)
{
    std::vector<std::string> movimentos_validos = Movimentos::getTodosMovimentos();

    for (const auto &mov : movimentos_validos)
    {
        if (comando == mov)
        {
            estado_atual = Movimentos::aplicarMovimento(estado_atual, comando);
            return true;
        }
    }
    return false;
}

void Jogo::embaralharCubo()
{
    std::cout << "\nEmbaralhando o cubo..." << std::endl;

    estado_atual.resetar();

    std::vector<std::string> todos_movimentos = Movimentos::getTodosMovimentos();
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, todos_movimentos.size() - 1);

    int num_movimentos = 20;
    std::vector<std::string> movimentos_embaralhamento;

    for (int i = 0; i < num_movimentos; i++)
    {
        std::string movimento = todos_movimentos[dis(gen)];
        movimentos_embaralhamento.push_back(movimento);
        estado_atual.adicionarMovimentoEmbaralhamento(movimento);
    }

    for (const auto &movimento : movimentos_embaralhamento)
    {
        estado_atual = Movimentos::aplicarMovimento(estado_atual, movimento);
    }

    estado_atual.limparCaminho();

    std::cout << "Cubo embaralhado com " << movimentos_embaralhamento.size() << " movimentos aleatorios!" << std::endl;
    std::cout << "Use a opcao 5 do menu se quiser ver quais foram os movimentos." << std::endl;
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