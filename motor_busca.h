#ifndef MOTOR_BUSCA_H
#define MOTOR_BUSCA_H

#include "estado.h"
#include "estrutura_dados.h"
#include "funcao_sucessora.h"
#include "funcao_avaliadora.h"
#include <memory>

class MotorBusca
{
private:
    std::unique_ptr<EstruturaAbstrata> estrutura;
    int contador_estados;

public:
    MotorBusca(std::unique_ptr<EstruturaAbstrata> estrutura_dados);

    bool executarBusca(Estado estado_inicial);

    int getContadorEstados() const;

private:
    void adicionarEstadosSegintes(const Estado &estado_atual);
};

#endif