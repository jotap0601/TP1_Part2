
#include "ServicoConta.hpp"
#include "../dominio/Conta.hpp"
#include "../repositorio/RepositorioConta.hpp"
#include <iostream>
using namespace std;

void ServicoConta::criarConta() {
    Conta conta;
    conta.preencherConta();
    RepositorioConta::adicionarConta(conta);
}
