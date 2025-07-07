# Compiler settings
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iapresentacao -Iservico -Idominio -Irepositorio -Ivalidacao

# Directory structure
SRC_DIR = .
APRESENTACAO_DIR = apresentacao
SERVICO_DIR = servico
REPOSITORIO_DIR = repositorio
DOMINIO_DIR = dominio
VALIDACAO_DIR = validacao

# Source files
SRCS = \
    $(SRC_DIR)/main.cpp \
    $(APRESENTACAO_DIR)/IUConta.cpp \
    $(APRESENTACAO_DIR)/IUCarteira.cpp \
    $(APRESENTACAO_DIR)/IUOrdem.cpp \
    $(SERVICO_DIR)/ServicoConta.cpp \
    $(SERVICO_DIR)/ServicoCarteira.cpp \
    $(SERVICO_DIR)/ServicoOrdem.cpp \
    $(SERVICO_DIR)/ServicoDadosHistoricos.cpp \
    $(REPOSITORIO_DIR)/RepositorioConta.cpp \
    $(REPOSITORIO_DIR)/RepositorioCarteira.cpp \
    $(REPOSITORIO_DIR)/RepositorioOrdem.cpp \
    $(DOMINIO_DIR)/Conta.cpp \
    $(DOMINIO_DIR)/Carteira.cpp \
    $(DOMINIO_DIR)/Ordem.cpp \
    $(DOMINIO_DIR)/Perfil.cpp \
    $(VALIDACAO_DIR)/Validador.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
TARGET = sistema

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
    $(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

clean:
    rm -f $(TARGET) $(OBJS)