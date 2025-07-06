
#include "IUConta.hpp"
#include "../servico/ServicoConta.hpp"
#include "../repositorio/RepositorioConta.hpp"
#include "../dominio/Conta.hpp"
#include "../apresentacao/IUCarteira.hpp"
#include "../apresentacao/IUOrdem.hpp"
#include <iostream>
using namespace std;

void IUConta::executar() {
    menu();
}

void IUConta::menu() {
    int opcao;
    do {
        cout << "\n===== MENU CONTA =====" << endl;
        cout << "1. Criar Conta" << endl;
        cout << "2. Acessar Conta" << endl;
        cout << "3. Sair" << endl;
        cout << "Opcao: ";
        cin >> opcao;

        if (opcao == 1) criarConta();
        else if (opcao == 2) acessarConta();
    } while (opcao != 3);
}

void IUConta::criarConta() {
    ServicoConta servicoConta;
    servicoConta.criarConta();
}

void IUConta::acessarConta() {
    string cpf, senha;
    cout << "\n===== ACESSAR CONTA =====" << endl;
    cout << "CPF: ";
    cin >> cpf;
    cout << "Senha: ";
    cin >> senha;

    Conta* conta = RepositorioConta::buscarConta(cpf, senha);
    if (conta != nullptr) {
        cout << "Bem-vindo(a), " << conta->getNome() << "!" << endl;
        menuContaLogada(conta);
    } else {
        cout << "CPF ou senha inválidos!" << endl;
    }
}

void IUConta::menuContaLogada(Conta* conta) {
    int opcao;
    do {
        cout << "\n===== MENU CONTA LOGADA =====" << endl;
        cout << "1. Consultar Saldo" << endl;
        cout << "2. Transferir Dinheiro" << endl;
        cout << "3. Editar Conta" << endl;
        cout << "4. Excluir Conta" << endl;
        cout << "5. Carteiras" << endl;
        cout << "6. Ordens" << endl;
        cout << "7. Sair" << endl;
        cout << "Opcao: ";
        cin >> opcao;

        if (opcao == 1) {
            cout << "Saldo atual: " << conta->getSaldo() << endl;
        } else if (opcao == 2) {
            transferirDinheiro(conta);
        } else if (opcao == 3) {
            editarConta(conta);
        } else if (opcao == 4) {
            excluirConta(conta);
            break;
        } else if (opcao == 5) {
            IUCarteira carteira;
            carteira.menuCarteira();
        } else if (opcao == 6) {
            IUOrdem ordem;
            ordem.menuOrdem();
        }
    } while (opcao != 7);
}

void IUConta::transferirDinheiro(Conta* conta) {
    string cpfDestino;
    double valor;
    cout << "\n===== TRANSFERIR DINHEIRO =====" << endl;
    cout << "CPF de destino: ";
    cin >> cpfDestino;
    cout << "Valor a transferir: ";
    cin >> valor;

    Conta* destino = RepositorioConta::buscarContaPorCpf(cpfDestino);
    if (destino != nullptr) {
        if (conta->getSaldo() >= valor) {
            conta->sacar(valor);
            destino->depositar(valor);
            cout << "Transferencia realizada com sucesso!" << endl;
        } else {
            cout << "Saldo insuficiente!" << endl;
        }
    } else {
        cout << "Conta de destino nao encontrada!" << endl;
    }
}

void IUConta::editarConta(Conta* conta) {
    string novoNome;
    cout << "\n===== EDITAR CONTA =====" << endl;
    cout << "Digite o novo nome: ";
    cin.ignore();
    getline(cin, novoNome);

    RepositorioConta::editarConta(conta->getCpf(), conta->getSenha(), novoNome);
    cout << "Conta editada com sucesso!" << endl;
}

void IUConta::excluirConta(Conta* conta) {
    cout << "\n===== EXCLUIR CONTA =====" << endl;
    if (RepositorioConta::excluirConta(conta->getCpf(), conta->getSenha())) {
        cout << "Conta excluida com sucesso!" << endl;
    } else {
        cout << "Erro ao excluir conta!" << endl;
    }
}
