#ifndef ESTRUTURA_DADOS_H
#define ESTRUTURA_DADOS_H

#include "estado.h"
#include <queue>
#include <stack>

// Interface abstrata para estruturas de dados
class EstruturaAbstrata
{
public:
    virtual ~EstruturaAbstrata() = default;
    virtual void adicionar(const Estado &estado) = 0;
    virtual Estado remover() = 0;
    virtual bool vazia() const = 0;
    virtual void limpar() = 0;
};

// Implementação para modo jogador (fila simples)
class FilaJogador : public EstruturaAbstrata
{
private:
    std::queue<Estado> fila;

public:
    void adicionar(const Estado &estado) override;
    Estado remover() override;
    bool vazia() const override;
    void limpar() override;
};

// Para futuras implementações de IA
class FilaBFS : public EstruturaAbstrata
{
private:
    std::queue<Estado> fila;

public:
    void adicionar(const Estado &estado) override;
    Estado remover() override;
    bool vazia() const override;
    void limpar() override;
};

#endif