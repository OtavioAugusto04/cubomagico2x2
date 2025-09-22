#ifndef INTERFACE_H
#define INTERFACE_H

#include "estado.h"
#include <string>

class Interface
{
public:
    static void mostrarCubo(const Estado &estado);
    static void mostrarMenu();
    static void mostrarComandos();
    static void mostrarSolucao(const Estado &estado_final);
    static void mostrarEmbaralhamento(const Estado &estado);
    static void limparTela();
    static char corParaChar(int cor);
    static std::string corParaNome(int cor);

private:
    static void mostrarCuboDesenrolado(const std::vector<int> &cubo);
};

#endif