#ifndef FUNCAO_SUCESSORA_H
#define FUNCAO_SUCESSORA_H

#include "estado.h"
#include <vector>

// Função Sucessora - gera todos os estados possíveis a partir de um estado
class FuncaoSucessora
{
public:
    static std::vector<Estado> gerarSucessores(const Estado &estado_atual);
    static Estado aplicarMovimento(const Estado &estado, const std::string &movimento);
    static std::vector<std::string> getTodosMovimentos();

private:
    static std::vector<int> movimentoR(const std::vector<int> &cubo);
    static std::vector<int> movimentoRi(const std::vector<int> &cubo);
    static std::vector<int> movimentoL(const std::vector<int> &cubo);
    static std::vector<int> movimentoLi(const std::vector<int> &cubo);
    static std::vector<int> movimentoU(const std::vector<int> &cubo);
    static std::vector<int> movimentoUi(const std::vector<int> &cubo);
    static std::vector<int> movimentoD(const std::vector<int> &cubo);
    static std::vector<int> movimentoDi(const std::vector<int> &cubo);
    static std::vector<int> movimentoF(const std::vector<int> &cubo);
    static std::vector<int> movimentoFi(const std::vector<int> &cubo);
    static std::vector<int> movimentoB(const std::vector<int> &cubo);
    static std::vector<int> movimentoBi(const std::vector<int> &cubo);

    static void rotacionarFace(std::vector<int> &cubo, int face, bool horario);
};

#endif