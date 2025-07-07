#include "Conta.hpp"
#include "../validacao/Validador.hpp"
#include <iostream>
#include <limits>
using namespace std;

void Conta::preencherConta() {
    do {
        cout << "Digite o CPF (11 digitos, somente numeros): ";
        cin >> cpf;
    } while (!Validador::validarCpf(cpf));

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    do {
        cout << "Digite o Nome (ate 20 caracteres): ";
        getline(cin, nome);
    } while (!Validador::validarNome(nome));

    do {
        cout << "Digite a Senha (6 caracteres, com maiuscula, minuscula, numero e especial (#,$,%,&), sem repeticao): ";
        cin >> senha;
    } while (!Validador::validarSenha(senha));

    saldo = 1000.0;
    cout << "Conta criada com sucesso com saldo inicial de R$1000.00!" << endl;
}
