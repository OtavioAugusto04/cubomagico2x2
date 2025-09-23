#include "funcao_sucessora.h"

std::vector<Estado> FuncaoSucessora::gerarSucessores(const Estado &estado_atual)
{
    std::vector<Estado> sucessores;
    std::vector<std::string> movimentos = getTodosMovimentos();

    for (const auto &movimento : movimentos)
    {
        Estado novo_estado = aplicarMovimento(estado_atual, movimento);
        sucessores.push_back(novo_estado);
    }

    return sucessores;
}

std::vector<std::string> FuncaoSucessora::getTodosMovimentos()
{
    return {"R", "R'", "L", "L'", "U", "U'", "D", "D'", "F", "F'", "B", "B'"};
}
Estado FuncaoSucessora::aplicarMovimento(const Estado &estado, const std::string &movimento)
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

    // PRESERVAR TODAS AS INFORMACOES DO ESTADO ANTERIOR
    Estado novo_estado = estado.copiar(); // Usar copiar() em vez de construtor
    novo_estado.setCubo(novo_cubo);
    novo_estado.adicionarMovimento(movimento);
    return novo_estado;
}

void FuncaoSucessora::rotacionarFace(std::vector<int> &cubo, int face, bool horario)
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

// MOVIMENTOS DIREITA (R e R')
std::vector<int> FuncaoSucessora::movimentoR(const std::vector<int> &cubo)
{
    std::vector<int> novo_cubo = cubo;
    rotacionarFace(novo_cubo, 2, true); // Rotaciona face Right

    // Troca arestas: Front[1,3] -> Down[1,3] -> Back[0,2] -> Up[1,3] -> Front[1,3]
    int temp1 = novo_cubo[1], temp2 = novo_cubo[3];
    novo_cubo[1] = novo_cubo[21];
    novo_cubo[3] = novo_cubo[23]; // Front <- Down
    novo_cubo[21] = novo_cubo[4];
    novo_cubo[23] = novo_cubo[6]; // Down <- Back
    novo_cubo[4] = novo_cubo[17];
    novo_cubo[6] = novo_cubo[19]; // Back <- Up
    novo_cubo[17] = temp1;
    novo_cubo[19] = temp2; // Up <- Front

    return novo_cubo;
}

std::vector<int> FuncaoSucessora::movimentoRi(const std::vector<int> &cubo)
{
    std::vector<int> novo_cubo = cubo;
    for (int i = 0; i < 3; i++)
    {
        novo_cubo = movimentoR(novo_cubo);
    }
    return novo_cubo;
}

// MOVIMENTOS ESQUERDA (L e L')
std::vector<int> FuncaoSucessora::movimentoL(const std::vector<int> &cubo)
{
    std::vector<int> novo_cubo = cubo;
    rotacionarFace(novo_cubo, 3, true); // Rotaciona face Left

    // Troca arestas: Front[0,2] -> Up[0,2] -> Back[3,1] -> Down[0,2] -> Front[0,2]
    int temp1 = novo_cubo[0], temp2 = novo_cubo[2];
    novo_cubo[0] = novo_cubo[16];
    novo_cubo[2] = novo_cubo[18]; // Front <- Up
    novo_cubo[16] = novo_cubo[7];
    novo_cubo[18] = novo_cubo[5]; // Up <- Back
    novo_cubo[7] = novo_cubo[22];
    novo_cubo[5] = novo_cubo[20]; // Back <- Down
    novo_cubo[22] = temp1;
    novo_cubo[20] = temp2; // Down <- Front

    return novo_cubo;
}

std::vector<int> FuncaoSucessora::movimentoLi(const std::vector<int> &cubo)
{
    std::vector<int> novo_cubo = cubo;
    for (int i = 0; i < 3; i++)
    {
        novo_cubo = movimentoL(novo_cubo);
    }
    return novo_cubo;
}
// MOVIMENTOS SUPERIOR (U e U')
std::vector<int> FuncaoSucessora::movimentoU(const std::vector<int> &cubo)
{
    std::vector<int> novo_cubo = cubo;
    rotacionarFace(novo_cubo, 4, true); // Rotaciona face Up

    // Troca arestas superiores: Front[0,1] -> Right[0,1] -> Back[0,1] -> Left[0,1] -> Front[0,1]
    int temp1 = novo_cubo[0], temp2 = novo_cubo[1];
    novo_cubo[0] = novo_cubo[8];
    novo_cubo[1] = novo_cubo[9]; // Front <- Right
    novo_cubo[8] = novo_cubo[4];
    novo_cubo[9] = novo_cubo[5]; // Right <- Back
    novo_cubo[4] = novo_cubo[12];
    novo_cubo[5] = novo_cubo[13]; // Back <- Left
    novo_cubo[12] = temp1;
    novo_cubo[13] = temp2; // Left <- Front

    return novo_cubo;
}

std::vector<int> FuncaoSucessora::movimentoUi(const std::vector<int> &cubo)
{
    std::vector<int> novo_cubo = cubo;
    for (int i = 0; i < 3; i++)
    {
        novo_cubo = movimentoU(novo_cubo);
    }
    return novo_cubo;
}

// MOVIMENTOS INFERIOR (D e D')
std::vector<int> FuncaoSucessora::movimentoD(const std::vector<int> &cubo)
{
    std::vector<int> novo_cubo = cubo;
    rotacionarFace(novo_cubo, 5, true); // Rotaciona face Down

    // Troca arestas inferiores: Front[2,3] -> Left[2,3] -> Back[2,3] -> Right[2,3] -> Front[2,3]
    int temp1 = novo_cubo[2], temp2 = novo_cubo[3];
    novo_cubo[2] = novo_cubo[14];
    novo_cubo[3] = novo_cubo[15]; // Front <- Left
    novo_cubo[14] = novo_cubo[6];
    novo_cubo[15] = novo_cubo[7]; // Left <- Back
    novo_cubo[6] = novo_cubo[10];
    novo_cubo[7] = novo_cubo[11]; // Back <- Right
    novo_cubo[10] = temp1;
    novo_cubo[11] = temp2; // Right <- Front

    return novo_cubo;
}

std::vector<int> FuncaoSucessora::movimentoDi(const std::vector<int> &cubo)
{
    std::vector<int> novo_cubo = cubo;
    for (int i = 0; i < 3; i++)
    {
        novo_cubo = movimentoD(novo_cubo);
    }
    return novo_cubo;
}

// MOVIMENTOS FRONTAL (F e F')
std::vector<int> FuncaoSucessora::movimentoF(const std::vector<int> &cubo)
{
    std::vector<int> novo_cubo = cubo;
    rotacionarFace(novo_cubo, 0, true); // Rotaciona face Front

    // Troca arestas frontais: Up[2,3] -> Left[3,1] -> Down[1,0] -> Right[0,2] -> Up[2,3]
    int temp1 = novo_cubo[18], temp2 = novo_cubo[19];
    novo_cubo[18] = novo_cubo[15];
    novo_cubo[19] = novo_cubo[13]; // Up <- Left
    novo_cubo[15] = novo_cubo[21];
    novo_cubo[13] = novo_cubo[20]; // Left <- Down
    novo_cubo[21] = novo_cubo[8];
    novo_cubo[20] = novo_cubo[10]; // Down <- Right
    novo_cubo[8] = temp1;
    novo_cubo[10] = temp2; // Right <- Up

    return novo_cubo;
}

std::vector<int> FuncaoSucessora::movimentoFi(const std::vector<int> &cubo)
{
    std::vector<int> novo_cubo = cubo;
    for (int i = 0; i < 3; i++)
    {
        novo_cubo = movimentoF(novo_cubo);
    }
    return novo_cubo;
}

// MOVIMENTOS TRASEIRA (B e B')
std::vector<int> FuncaoSucessora::movimentoB(const std::vector<int> &cubo)
{
    std::vector<int> novo_cubo = cubo;
    rotacionarFace(novo_cubo, 1, true); // Rotaciona face Back

    // Troca arestas traseiras: Up[0,1] -> Right[1,3] -> Down[3,2] -> Left[2,0] -> Up[0,1]
    int temp1 = novo_cubo[16], temp2 = novo_cubo[17];
    novo_cubo[16] = novo_cubo[9];
    novo_cubo[17] = novo_cubo[11]; // Up <- Right
    novo_cubo[9] = novo_cubo[23];
    novo_cubo[11] = novo_cubo[22]; // Right <- Down
    novo_cubo[23] = novo_cubo[14];
    novo_cubo[22] = novo_cubo[12]; // Down <- Left
    novo_cubo[14] = temp1;
    novo_cubo[12] = temp2; // Left <- Up

    return novo_cubo;
}

std::vector<int> FuncaoSucessora::movimentoBi(const std::vector<int> &cubo)
{
    std::vector<int> novo_cubo = cubo;
    for (int i = 0; i < 3; i++)
    {
        novo_cubo = movimentoB(novo_cubo);
    }
    return novo_cubo;
}