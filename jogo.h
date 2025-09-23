#ifndef JOGO_H
#define JOGO_H

#include "estado.h"
#include "motor_busca.h"
#include "interface.h"
#include "busca_dfs_iterativa.h" // NOVO INCLUDE
#include <memory>

class Jogo
{
private:
    Estado estado_atual;
    std::unique_ptr<MotorBusca> motor;
    bool rodando;

public:
    Jogo();
    void iniciar();

private:
    void inicializarJogo();
    void modoJogadorHumano();
    void modoIA();
    void resolverComDFS();
    void embaralharCubo();
    void resetarCubo();
    void verEmbaralhamento();
    void mostrarAjuda();
    int lerOpcao();
    std::string lerComando();
    bool processarMovimento(const std::string &comando);
};

#endif