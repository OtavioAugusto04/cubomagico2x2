#ifndef ESTADO_H
#define ESTADO_H

#include <vector>
#include <string>

class Estado
{
private:
    // Vetor de 24 elementos: 6 faces × 4 posições cada
    // Índices: [0-3: Front, 4-7: Back, 8-11: Right, 12-15: Left, 16-19: Up, 20-23: Down]
    std::vector<int> cubo;
    std::vector<std::string> caminho;                   // Sequência de movimentos do jogador
    std::vector<std::string> movimentos_embaralhamento; // Movimentos do embaralhamento

public:
    Estado();
    Estado(const std::vector<int> &estado_cubo);

    // Getters
    std::vector<int> getCubo() const;
    int getCor(int face, int posicao) const;
    std::vector<std::string> getCaminho() const;
    std::vector<std::string> getMovimentosEmbaralhamento() const;

    // Setters
    void setCubo(const std::vector<int> &novo_cubo);
    void setCor(int face, int posicao, int cor);
    void adicionarMovimento(const std::string &movimento);
    void adicionarMovimentoEmbaralhamento(const std::string &movimento);

    // Operadores para comparação
    bool operator==(const Estado &outro) const;
    bool operator<(const Estado &outro) const;

    // Utilidades
    void resetar();
    void embaralhar(int num_movimentos = 15);
    void limparCaminho();
    Estado copiar() const;
    bool isResolvido() const;

    // Debug
    void imprimir() const;
};

#endif