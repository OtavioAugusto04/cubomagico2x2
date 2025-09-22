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