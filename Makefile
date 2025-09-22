CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
TARGET = cubo_magico
SOURCES = main.cpp estado.cpp movimentos.cpp interface.cpp jogo.cpp

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)

.PHONY: clean