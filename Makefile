CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
TARGET = cubo_magico
SOURCES = main.cpp estado.cpp funcao_sucessora.cpp funcao_avaliadora.cpp estrutura_dados.cpp interface.cpp motor_busca.cpp jogo.cpp busca_dfs_iterativa.cpp

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)

.PHONY: clean