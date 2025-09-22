#include "estado.h"
#include <iostream>
#include <random>
#include <algorithm>

Estado::Estado() : cubo(24), estados_visitados(0)
{
    resetar();
}

Estado::Estado(const std::vector<int> &estado_cubo) : cubo(estado_cubo), estados_visitados(0) {}

Estado::Estado(const std::vector<int> &estado_cubo, const std::vector<std::string> &caminho_ate_aqui)
    : cubo(estado_cubo), caminho(caminho_ate_aqui), estados_visitados(0) {}

std::vector<int> Estado::getCubo() const
{
    return cubo;
}

int Estado::getCor(int face, int posicao) const
{
    return cubo[face * 4 + posicao];
}

std::vector<std::string> Estado::getCaminho() const
{
    return caminho;
}

std::vector<std::string> Estado::getMovimentosEmbaralhamento() const
{
    return movimentos_embaralhamento;
}

int Estado::getEstadosVisitados() const
{
    return estados_visitados;
}

void Estado::setCubo(const std::vector<int> &novo_cubo)
{
    if (novo_cubo.size() == 24)
    {
        cubo = novo_cubo;
    }
}

void Estado::setCor(int face, int posicao, int cor)
{
    cubo[face * 4 + posicao] = cor;
}

void Estado::adicionarMovimento(const std::string &movimento)
{
    caminho.push_back(movimento);
}

void Estado::adicionarMovimentoEmbaralhamento(const std::string &movimento)
{
    movimentos_embaralhamento.push_back(movimento);
}

void Estado::setEstadosVisitados(int estados)
{
    estados_visitados = estados;
}

bool Estado::operator==(const Estado &outro) const
{
    return cubo == outro.cubo;
}

bool Estado::operator<(const Estado &outro) const
{
    return cubo < outro.cubo;
}

void Estado::resetar()
{
    // Lista dos movimentos:
    // R = Right (lado direito) e R' = inverso de R.
    // O mesmo se aplica para todos os demais movimentos.
    for (int face = 0; face < 6; face++)
    {
        for (int pos = 0; pos < 4; pos++)
        {
            cubo[face * 4 + pos] = face;
        }
    }
    caminho.clear();
    movimentos_embaralhamento.clear();
    estados_visitados = 0;
}

void Estado::limparCaminho()
{
    caminho.clear();
}

void Estado::embaralhar(int num_movimentos)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 11);

    std::vector<std::string> movimentos = {"R", "R'", "L", "L'", "U", "U'", "D", "D'", "F", "F'", "B", "B'"};

    movimentos_embaralhamento.clear();
    for (int i = 0; i < num_movimentos; i++)
    {
        int mov = dis(gen);
        adicionarMovimentoEmbaralhamento(movimentos[mov]);
    }
}

Estado Estado::copiar() const
{
    Estado novo_estado(cubo, caminho);
    novo_estado.movimentos_embaralhamento = movimentos_embaralhamento;
    novo_estado.estados_visitados = estados_visitados;
    return novo_estado;
}

void Estado::imprimir() const
{
    std::cout << "Estado: ";
    for (int i = 0; i < 24; i++)
    {
        std::cout << cubo[i] << " ";
        if ((i + 1) % 4 == 0)
            std::cout << "| ";
    }
    std::cout << "\nMovimentos do jogador: ";
    for (const auto &mov : caminho)
    {
        std::cout << mov << " ";
    }
    std::cout << "\nMovimentos embaralhamento: ";
    for (const auto &mov : movimentos_embaralhamento)
    {
        std::cout << mov << " ";
    }
    std::cout << "\nEstados visitados: " << estados_visitados << std::endl;
}