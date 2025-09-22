#include "movimentos.h"

std::vector<std::string> Movimentos::getTodosMovimentos()
{
    return {"R", "R'", "L", "L'", "U", "U'", "D", "D'", "F", "F'", "B", "B'"};
}

Estado Movimentos::aplicarMovimento(const Estado &estado, const std::string &movimento)
{
    std::vector<int> novo_cubo = estado.getCubo();

    if (movimento == "R")
    {
        novo_cubo = movimentoR(novo_cubo);
    }
    else if (movimento == "R'")
    {
        novo_cubo = movimentoRi(novo_cubo);
    }
    else if (movimento == "L")
    {
        novo_cubo = movimentoL(novo_cubo);
    }
    else if (movimento == "L'")
    {
        novo_cubo = movimentoLi(novo_cubo);
    }
    else if (movimento == "U")
    {
        novo_cubo = movimentoU(novo_cubo);
    }
    else if (movimento == "U'")
    {
        novo_cubo = movimentoUi(novo_cubo);
    }
    else if (movimento == "D")
    {
        novo_cubo = movimentoD(novo_cubo);
    }
    else if (movimento == "D'")
    {
        novo_cubo = movimentoDi(novo_cubo);
    }
    else if (movimento == "F")
    {
        novo_cubo = movimentoF(novo_cubo);
    }
    else if (movimento == "F'")
    {
        novo_cubo = movimentoFi(novo_cubo);
    }
    else if (movimento == "B")
    {
        novo_cubo = movimentoB(novo_cubo);
    }
    else if (movimento == "B'")
    {
        novo_cubo = movimentoBi(novo_cubo);
    }

    Estado novo_estado = estado.copiar();
    novo_estado.setCubo(novo_cubo);
    novo_estado.adicionarMovimento(movimento);
    return novo_estado;
}

void Movimentos::rotacionarFace(std::vector<int> &cubo, int face, bool horario)
{
    int base = face * 4;
    if (horario)
    {
        int temp = cubo[base];
        cubo[base] = cubo[base + 2];
        cubo[base + 2] = cubo[base + 3];
        cubo[base + 3] = cubo[base + 1];
        cubo[base + 1] = temp;
    }
    else
    {
        int temp = cubo[base];
        cubo[base] = cubo[base + 1];
        cubo[base + 1] = cubo[base + 3];
        cubo[base + 3] = cubo[base + 2];
        cubo[base + 2] = temp;
    }
}

std::vector<int> Movimentos::movimentoR(const std::vector<int> &cubo)
{
    std::vector<int> novo_cubo = cubo;
    rotacionarFace(novo_cubo, 2, true);

    int temp1 = novo_cubo[1], temp2 = novo_cubo[3];
    novo_cubo[1] = novo_cubo[21];
    novo_cubo[3] = novo_cubo[23];
    novo_cubo[21] = novo_cubo[4];
    novo_cubo[23] = novo_cubo[6];
    novo_cubo[4] = novo_cubo[17];
    novo_cubo[6] = novo_cubo[19];
    novo_cubo[17] = temp1;
    novo_cubo[19] = temp2;

    return novo_cubo;
}

std::vector<int> Movimentos::movimentoRi(const std::vector<int> &cubo)
{
    std::vector<int> novo_cubo = cubo;
    for (int i = 0; i < 3; i++)
    {
        novo_cubo = movimentoR(novo_cubo);
    }
    return novo_cubo;
}

std::vector<int> Movimentos::movimentoL(const std::vector<int> &cubo)
{
    std::vector<int> novo_cubo = cubo;
    rotacionarFace(novo_cubo, 3, true);

    int temp1 = novo_cubo[0], temp2 = novo_cubo[2];
    novo_cubo[0] = novo_cubo[16];
    novo_cubo[2] = novo_cubo[18];
    novo_cubo[16] = novo_cubo[7];
    novo_cubo[18] = novo_cubo[5];
    novo_cubo[7] = novo_cubo[22];
    novo_cubo[5] = novo_cubo[20];
    novo_cubo[22] = temp1;
    novo_cubo[20] = temp2;

    return novo_cubo;
}

std::vector<int> Movimentos::movimentoLi(const std::vector<int> &cubo)
{
    std::vector<int> novo_cubo = cubo;
    for (int i = 0; i < 3; i++)
    {
        novo_cubo = movimentoL(novo_cubo);
    }
    return novo_cubo;
}

std::vector<int> Movimentos::movimentoU(const std::vector<int> &cubo)
{
    std::vector<int> novo_cubo = cubo;
    rotacionarFace(novo_cubo, 4, true);

    int temp1 = novo_cubo[0], temp2 = novo_cubo[1];
    novo_cubo[0] = novo_cubo[8];
    novo_cubo[1] = novo_cubo[9];
    novo_cubo[8] = novo_cubo[4];
    novo_cubo[9] = novo_cubo[5];
    novo_cubo[4] = novo_cubo[12];
    novo_cubo[5] = novo_cubo[13];
    novo_cubo[12] = temp1;
    novo_cubo[13] = temp2;

    return novo_cubo;
}

std::vector<int> Movimentos::movimentoUi(const std::vector<int> &cubo)
{
    std::vector<int> novo_cubo = cubo;
    for (int i = 0; i < 3; i++)
    {
        novo_cubo = movimentoU(novo_cubo);
    }
    return novo_cubo;
}

std::vector<int> Movimentos::movimentoD(const std::vector<int> &cubo)
{
    std::vector<int> novo_cubo = cubo;
    rotacionarFace(novo_cubo, 5, true);

    int temp1 = novo_cubo[2], temp2 = novo_cubo[3];
    novo_cubo[2] = novo_cubo[14];
    novo_cubo[3] = novo_cubo[15];
    novo_cubo[14] = novo_cubo[6];
    novo_cubo[15] = novo_cubo[7];
    novo_cubo[6] = novo_cubo[10];
    novo_cubo[7] = novo_cubo[11];
    novo_cubo[10] = temp1;
    novo_cubo[11] = temp2;

    return novo_cubo;
}

std::vector<int> Movimentos::movimentoDi(const std::vector<int> &cubo)
{
    std::vector<int> novo_cubo = cubo;
    for (int i = 0; i < 3; i++)
    {
        novo_cubo = movimentoD(novo_cubo);
    }
    return novo_cubo;
}

std::vector<int> Movimentos::movimentoF(const std::vector<int> &cubo)
{
    std::vector<int> novo_cubo = cubo;
    rotacionarFace(novo_cubo, 0, true);

    int temp1 = novo_cubo[18], temp2 = novo_cubo[19];
    novo_cubo[18] = novo_cubo[15];
    novo_cubo[19] = novo_cubo[13];
    novo_cubo[15] = novo_cubo[21];
    novo_cubo[13] = novo_cubo[20];
    novo_cubo[21] = novo_cubo[8];
    novo_cubo[20] = novo_cubo[10];
    novo_cubo[8] = temp1;
    novo_cubo[10] = temp2;

    return novo_cubo;
}

std::vector<int> Movimentos::movimentoFi(const std::vector<int> &cubo)
{
    std::vector<int> novo_cubo = cubo;
    for (int i = 0; i < 3; i++)
    {
        novo_cubo = movimentoF(novo_cubo);
    }
    return novo_cubo;
}

std::vector<int> Movimentos::movimentoB(const std::vector<int> &cubo)
{
    std::vector<int> novo_cubo = cubo;
    rotacionarFace(novo_cubo, 1, true);

    int temp1 = novo_cubo[16], temp2 = novo_cubo[17];
    novo_cubo[16] = novo_cubo[9];
    novo_cubo[17] = novo_cubo[11];
    novo_cubo[9] = novo_cubo[23];
    novo_cubo[11] = novo_cubo[22];
    novo_cubo[23] = novo_cubo[14];
    novo_cubo[22] = novo_cubo[12];
    novo_cubo[14] = temp1;
    novo_cubo[12] = temp2;

    return novo_cubo;
}

std::vector<int> Movimentos::movimentoBi(const std::vector<int> &cubo)
{
    std::vector<int> novo_cubo = cubo;
    for (int i = 0; i < 3; i++)
    {
        novo_cubo = movimentoB(novo_cubo);
    }
    return novo_cubo;
}