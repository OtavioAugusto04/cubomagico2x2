#ifndef ESTADO_H
#define ESTADO_H

#include <vector>
#include <string>

// Representacao do Estado do cubo como vetor explicito
class Estado
{
private:
    // Vetor de 24 elementos: 6 faces x 4 posicoes cada
    // Indices: [0-3: Front, 4-7: Back, 8-11: Right, 12-15: Left, 16-19: Up, 20-23: Down]
    std::vector<int> cubo;
    std::vector<std::string> caminho;                   // Sequencia de movimentos para chegar neste estado
    std::vector<std::string> movimentos_embaralhamento; // Movimentos do embaralhamento (separado)
    int estados_visitados;

public:
    Estado();
    Estado(const std::vector<int> &estado_cubo);
    Estado(const std::vector<int> &estado_cubo, const std::vector<std::string> &caminho_ate_aqui);

    // Getters
    std::vector<int> getCubo() const;
    int getCor(int face, int posicao) const;
    std::vector<std::string> getCaminho() const;
    std::vector<std::string> getMovimentosEmbaralhamento() const;
    int getEstadosVisitados() const;

    // Setters
    void setCubo(const std::vector<int> &novo_cubo);
    void setCor(int face, int posicao, int cor);
    void adicionarMovimento(const std::string &movimento);
    void adicionarMovimentoEmbaralhamento(const std::string &movimento);
    void setEstadosVisitados(int estados);

    // Operadores para comparacao e estruturas de dados
    bool operator==(const Estado &outro) const;
    bool operator<(const Estado &outro) const;

    // Utilidades
    void resetar();
    void embaralhar(int num_movimentos = 15);
    void limparCaminho(); // Limpa apenas o caminho do jogador, mantem embaralhamento
    Estado copiar() const;

    // Debug
    void imprimir() const;
};

#endif