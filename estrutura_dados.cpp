#include "estrutura_dados.h"
#include <stdexcept>

// FilaJogador
void FilaJogador::adicionar(const Estado &estado)
{
    fila.push(estado);
}

Estado FilaJogador::remover()
{
    if (fila.empty())
    {
        throw std::runtime_error("Estrutura vazia");
    }
    Estado estado = fila.front();
    fila.pop();
    return estado;
}

bool FilaJogador::vazia() const
{
    return fila.empty();
}

void FilaJogador::limpar()
{
    while (!fila.empty())
    {
        fila.pop();
    }
}

// FilaBFS
void FilaBFS::adicionar(const Estado &estado)
{
    fila.push(estado);
}

Estado FilaBFS::remover()
{
    if (fila.empty())
    {
        throw std::runtime_error("Estrutura vazia");
    }
    Estado estado = fila.front();
    fila.pop();
    return estado;
}

bool FilaBFS::vazia() const
{
    return fila.empty();
}

void FilaBFS::limpar()
{
    while (!fila.empty())
    {
        fila.pop();
    }
}

// FilaBFSLimitada
FilaBFSLimitada::FilaBFSLimitada(int limite) : limite_profundidade(limite) {}

void FilaBFSLimitada::adicionar(const Estado &estado)
{
    // So adiciona se nao exceder o limite de profundidade
    if (static_cast<int>(estado.getCaminho().size()) <= limite_profundidade)
    {
        fila.push(estado);
    }
}

Estado FilaBFSLimitada::remover()
{
    if (fila.empty())
    {
        throw std::runtime_error("Estrutura vazia");
    }
    Estado estado = fila.front();
    fila.pop();
    return estado;
}

bool FilaBFSLimitada::vazia() const
{
    return fila.empty();
}

void FilaBFSLimitada::limpar()
{
    while (!fila.empty())
    {
        fila.pop();
    }
}

void FilaBFSLimitada::setLimite(int novo_limite)
{
    limite_profundidade = novo_limite;
}

int FilaBFSLimitada::getLimite() const
{
    return limite_profundidade;
}

// PilhaDFS
PilhaDFS::PilhaDFS(int limite) : limite_profundidade(limite) {}

void PilhaDFS::adicionar(const Estado &estado)
{
    // So adiciona se nao exceder o limite de profundidade
    if (static_cast<int>(estado.getCaminho().size()) <= limite_profundidade)
    {
        pilha.push(estado);
    }
}

Estado PilhaDFS::remover()
{
    if (pilha.empty())
    {
        throw std::runtime_error("Estrutura vazia");
    }
    Estado estado = pilha.top();
    pilha.pop();
    return estado;
}

bool PilhaDFS::vazia() const
{
    return pilha.empty();
}

void PilhaDFS::limpar()
{
    while (!pilha.empty())
    {
        pilha.pop();
    }
}

void PilhaDFS::setLimite(int novo_limite)
{
    limite_profundidade = novo_limite;
}

int PilhaDFS::getLimite() const
{
    return limite_profundidade;
}