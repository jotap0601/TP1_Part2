
#include "Conta.hpp"
#include "../validacao/Validador.hpp"
#include <iostream>
using namespace std;

void Conta::preencherConta() {
    do {
        cout << "Digite o CPF: ";
        cin >> cpf;
    } while (!Validador::validarCpf(cpf));

    cout << "Digite o Nome: ";
    cin.ignore();
    getline(cin, nome);

    do {
        cout << "Digite a Senha (min 6 caracteres): ";
        cin >> senha;
    } while (!Validador::validarSenha(senha));

    saldo = 1000.0;
    cout << "Conta criada com sucesso com saldo inicial de R$1000.00!" << endl;
}
