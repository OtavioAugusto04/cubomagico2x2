#ifndef JOGO_H
#define JOGO_H

#include "estado.h"
#include "interface.h"

class Jogo
{
private:
    Estado estado_atual;
    bool rodando;

public:
    Jogo();
    void iniciar();

private:
    void inicializarJogo();
    void modoJogo();
    void embaralharCubo();
    void resetarCubo();
    void verEmbaralhamento();
    void mostrarAjuda();
    int lerOpcao();
    std::string lerComando();
    bool processarMovimento(const std::string &comando);
};

#endif