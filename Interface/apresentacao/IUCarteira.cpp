#include "IUCarteira.hpp"
#include "../servico/ServicoCarteira.hpp"
#include <iostream>
#include <cctype> // Necessário para ::toupper

using namespace std;

void IUCarteira::menuCarteira() {
    int opcao;
    do {
        cout << "\n===== MENU CARTEIRA =====" << endl;
        cout << "1. Criar Carteira" << endl;
        cout << "2. Editar Carteira" << endl;
        cout << "3. Excluir Carteira" << endl;
        cout << "4. Listar Carteiras" << endl;
        cout << "5. Detalhes da Carteira" << endl;
        cout << "6. Voltar" << endl;
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1: criarCarteira(); break;
            case 2: editarCarteira(); break;
            case 3: excluirCarteira(); break;
            case 4: listarCarteiras(); break;
            case 5: mostrarDetalhesCarteira(); break;
        }
    } while (opcao != 6);
}

void IUCarteira::criarCarteira() {
    string codigo, nome, perfil;
    cout << "\n===== CRIAR CARTEIRA =====" << endl;
    cout << "Codigo (5 digitos): ";
    cin >> codigo;
    cout << "Nome: ";
    cin.ignore();
    getline(cin, nome);
    cout << "Perfil (CONSERVADOR, MODERADO, AGRESSIVO): ";
    cin >> perfil;

    // Transforma perfil para maiúsculas
    transform(perfil.begin(), perfil.end(), perfil.begin(), ::toupper);

    if (ServicoCarteira::criarCarteira(codigo, nome, perfil, "")) { // "" representa o CPF da conta (a ser implementado)
        cout << "Carteira criada com sucesso!" << endl;
    } else {
        cout << "Erro ao criar carteira. Verifique os dados." << endl;
    }
}

void IUCarteira::editarCarteira() {
    string codigo, nome, perfil;
    cout << "\n===== EDITAR CARTEIRA =====" << endl;
    cout << "Codigo da carteira a editar: ";
    cin >> codigo;
    cout << "Novo nome: ";
    cin.ignore();
    getline(cin, nome);
    cout << "Novo perfil (CONSERVADOR, MODERADO, AGRESSIVO): ";
    cin >> perfil;

    transform(perfil.begin(), perfil.end(), perfil.begin(), ::toupper);

    if (ServicoCarteira::editarCarteira(codigo, nome, perfil)) {
        cout << "Carteira editada com sucesso!" << endl;
    } else {
        cout << "Erro ao editar carteira. Verifique os dados." << endl;
    }
}

void IUCarteira::excluirCarteira() {
    string codigo;
    cout << "\n===== EXCLUIR CARTEIRA =====" << endl;
    cout << "Codigo da carteira a excluir: ";
    cin >> codigo;

    if (ServicoCarteira::excluirCarteira(codigo)) {
        cout << "Carteira excluida com sucesso!" << endl;
    } else {
        cout << "Erro ao excluir carteira. Verifique o codigo." << endl;
    }
}

void IUCarteira::listarCarteiras() {
    cout << "\n===== LISTA DE CARTEIRAS =====" << endl;
    vector<Carteira*> carteiras = ServicoCarteira::listarCarteirasPorConta(""); // "" representa o CPF da conta

    if (carteiras.empty()) {
        cout << "Nenhuma carteira cadastrada." << endl;
    } else {
        for (auto carteira : carteiras) {
            cout << "Codigo: " << carteira->getCodigo() << endl;
            cout << "Nome: " << carteira->getNome() << endl;
            cout << "Perfil: ";
            switch (carteira->getPerfil()) {
                case Perfil::CONSERVADOR: cout << "CONSERVADOR"; break;
                case Perfil::MODERADO: cout << "MODERADO"; break;
                case Perfil::AGRESSIVO: cout << "AGRESSIVO"; break;
            }
            cout << "\nSaldo: " << carteira->getSaldo() << endl;
            cout << "---------------------" << endl;
        }
    }
}

void IUCarteira::mostrarDetalhesCarteira() {
    string codigo;
    cout << "\n===== DETALHES DA CARTEIRA =====" << endl;
    cout << "Codigo da carteira: ";
    cin >> codigo;

    Carteira* carteira = ServicoCarteira::buscarCarteira(codigo);
    if (carteira) {
        cout << "Codigo: " << carteira->getCodigo() << endl;
        cout << "Nome: " << carteira->getNome() << endl;
        cout << "Perfil: ";
        switch (carteira->getPerfil()) {
            case Perfil::CONSERVADOR: cout << "CONSERVADOR"; break;
            case Perfil::MODERADO: cout << "MODERADO"; break;
            case Perfil::AGRESSIVO: cout << "AGRESSIVO"; break;
        }
        cout << "\nSaldo: " << carteira->getSaldo() << endl;
    } else {
        cout << "Carteira nao encontrada." << endl;
    }
}
