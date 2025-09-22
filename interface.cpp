#include "interface.h"
#include <iostream>
#include <iomanip>

// Para a interface ficar mais bonitinha
#ifdef _WIN32
#define CLEAR_COMMAND "cls"
#else
#define CLEAR_COMMAND "clear"
#endif

void Interface::limparTela()
{
    system(CLEAR_COMMAND);
}

char Interface::corParaChar(int cor)
{
    switch (cor)
    {
    case 0:
        return 'W'; // Branco (Front)
    case 1:
        return 'Y'; // Amarelo (Back)
    case 2:
        return 'R'; // Vermelho (Right)
    case 3:
        return 'O'; // Laranja (Left)
    case 4:
        return 'G'; // Verde (Up)
    case 5:
        return 'B'; // Azul (Down)
    default:
        return '?';
    }
}

std::string Interface::corParaNome(int cor)
{
    switch (cor)
    {
    case 0:
        return "Branco";
    case 1:
        return "Amarelo";
    case 2:
        return "Vermelho";
    case 3:
        return "Laranja";
    case 4:
        return "Verde";
    case 5:
        return "Azul";
    default:
        return "Desconhecido";
    }
}

void Interface::mostrarCuboDesenrolado(const std::vector<int> &cubo)
{
    std::cout << "\n    +---+    " << std::endl;
    std::cout << "    |" << corParaChar(cubo[16]) << " " << corParaChar(cubo[17]) << "| CIMA " << std::endl;
    std::cout << "    +---+    " << std::endl;
    std::cout << "    |" << corParaChar(cubo[18]) << " " << corParaChar(cubo[19]) << "|    " << std::endl;
    std::cout << "+---+---+---+" << std::endl;
    std::cout << "|" << corParaChar(cubo[12]) << " " << corParaChar(cubo[13]) << "|" << corParaChar(cubo[0]) << " " << corParaChar(cubo[1]) << "|" << corParaChar(cubo[8]) << " " << corParaChar(cubo[9]) << "|" << std::endl;
    std::cout << "+---+---+---+" << std::endl;
    std::cout << "|" << corParaChar(cubo[14]) << " " << corParaChar(cubo[15]) << "|" << corParaChar(cubo[2]) << " " << corParaChar(cubo[3]) << "|" << corParaChar(cubo[10]) << " " << corParaChar(cubo[11]) << "|" << std::endl;
    std::cout << "+---+---+---+" << std::endl;
    std::cout << "    |" << corParaChar(cubo[20]) << " " << corParaChar(cubo[21]) << "|    " << std::endl;
    std::cout << "    +---+    " << std::endl;
    std::cout << "    |" << corParaChar(cubo[22]) << " " << corParaChar(cubo[23]) << "|BAIXO" << std::endl;
    std::cout << "    +---+    " << std::endl;
    std::cout << "    +---+    " << std::endl;
    std::cout << "    |" << corParaChar(cubo[4]) << " " << corParaChar(cubo[5]) << "|TRÁS" << std::endl;
    std::cout << "    +---+    " << std::endl;
    std::cout << "    |" << corParaChar(cubo[6]) << " " << corParaChar(cubo[7]) << "|    " << std::endl;
    std::cout << "    +---+    " << std::endl;

    std::cout << "\nESQ  FRENTE  DIR" << std::endl;
}

void Interface::mostrarCubo(const Estado &estado)
{
    mostrarCuboDesenrolado(estado.getCubo());

    auto caminho = estado.getCaminho();
    if (!caminho.empty())
    {
        std::cout << "\nSeus movimentos: ";
        for (const auto &mov : caminho)
        {
            std::cout << mov << " ";
        }
        std::cout << "\nTotal de movimentos: " << caminho.size() << std::endl;
    }

    auto embaralhamento = estado.getMovimentosEmbaralhamento();
    if (!embaralhamento.empty())
    {
        std::cout << "\n[O cubo foi embaralhado com " << embaralhamento.size() << " movimentos]" << std::endl;
    }

    bool tem_movimentos = !caminho.empty() || !embaralhamento.empty();
    if (!tem_movimentos)
    {
        std::cout << "\n[Estado inicial - pode embaralhar manualmente ou usar opcao 2]" << std::endl;
    }
}

void Interface::mostrarMenu()
{
    std::cout << "\n=== SIMULADOR CUBO MAGICO 2x2x2 ===" << std::endl;
    std::cout << "1. Jogar" << std::endl;
    std::cout << "2. Embaralhar cubo automaticamente" << std::endl;
    std::cout << "3. Resetar cubo" << std::endl;
    std::cout << "4. Mostrar comandos" << std::endl;
    std::cout << "5. Ver movimentos de embaralhamento" << std::endl;
    std::cout << "6. Sair" << std::endl;
    std::cout << "Escolha uma opcao: ";
}

void Interface::mostrarComandos()
{
    std::cout << "\n=== MOVIMENTOS DISPONIVEIS ===" << std::endl;
    std::cout << "R  - Rotacionar face DIREITA (sentido horario)" << std::endl;
    std::cout << "R' - Rotacionar face DIREITA (sentido anti-horario)" << std::endl;
    std::cout << "L  - Rotacionar face ESQUERDA (sentido horario)" << std::endl;
    std::cout << "L' - Rotacionar face ESQUERDA (sentido anti-horario)" << std::endl;
    std::cout << "U  - Rotacionar face SUPERIOR (sentido horario)" << std::endl;
    std::cout << "U' - Rotacionar face SUPERIOR (sentido anti-horario)" << std::endl;
    std::cout << "D  - Rotacionar face INFERIOR (sentido horario)" << std::endl;
    std::cout << "D' - Rotacionar face INFERIOR (sentido anti-horario)" << std::endl;
    std::cout << "F  - Rotacionar face FRONTAL (sentido horario)" << std::endl;
    std::cout << "F' - Rotacionar face FRONTAL (sentido anti-horario)" << std::endl;
    std::cout << "B  - Rotacionar face TRASEIRA (sentido horario)" << std::endl;
    std::cout << "B' - Rotacionar face TRASEIRA (sentido anti-horario)" << std::endl;
    std::cout << "sair - Sair do modo jogo" << std::endl;
    std::cout << "\nCores: W=Branco, Y=Amarelo, R=Vermelho, O=Laranja, G=Verde, B=Azul" << std::endl;
    std::cout << "\nTotal: 12 movimentos possiveis para todas as faces do cubo" << std::endl;
}

void Interface::mostrarSolucao(const Estado &estado_final)
{
    std::cout << "\n----- CUBO RESOLVIDO! -----" << std::endl;
    auto caminho = estado_final.getCaminho();
    std::cout << "Voce resolveu com " << caminho.size() << " movimentos:" << std::endl;
    for (const auto &movimento : caminho)
    {
        std::cout << movimento << " ";
    }
    std::cout << std::endl;
}

void Interface::mostrarEmbaralhamento(const Estado &estado)
{
    auto embaralhamento = estado.getMovimentosEmbaralhamento();
    if (embaralhamento.empty())
    {
        std::cout << "\nO cubo nao foi embaralhado automaticamente ainda." << std::endl;
        std::cout << "Voce pode embaralhar manualmente no modo jogo ou usar a opcao 2." << std::endl;
    }
    else
    {
        std::cout << "\n=== MOVIMENTOS DO EMBARALHAMENTO AUTOMATICO ===" << std::endl;
        std::cout << "Movimentos usados (" << embaralhamento.size() << " total): ";
        for (const auto &movimento : embaralhamento)
        {
            std::cout << movimento << " ";
        }
        std::cout << "\n\nPara desfazer, faca os movimentos INVERSOS na ORDEM CONTRARIA:" << std::endl;
        std::cout << "Inversos: R<->R', L<->L', U<->U', D<->D', F<->F', B<->B'" << std::endl;
    }
}