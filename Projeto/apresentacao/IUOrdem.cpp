#include "IUOrdem.hpp"
#include "../servico/ServicoOrdem.hpp"
#include <iostream>
using namespace std;

void IUOrdem::menuOrdem() {
    int opcao;
    do {
        cout << "\n===== MENU ORDEM =====" << endl;
        cout << "1. Criar Ordem" << endl;
        cout << "2. Excluir Ordem" << endl;
        cout << "3. Listar Ordens" << endl;
        cout << "4. Detalhes da Ordem" << endl;
        cout << "5. Voltar" << endl;
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1: criarOrdem(); break;
            case 2: excluirOrdem(); break;
            case 3: listarOrdens(); break;
            case 4: mostrarDetalhesOrdem(); break;
        }
    } while (opcao != 5);
}

void IUOrdem::criarOrdem() {
    string codigo, codigoNegociacao, data, codigoCarteira;
    int quantidade;
    
    cout << "\n===== CRIAR ORDEM =====" << endl;
    cout << "Codigo da carteira: ";
    cin >> codigoCarteira;
    cout << "Codigo da ordem (5 digitos): ";
    cin >> codigo;
    cout << "Codigo de negociacao: ";
    cin >> codigoNegociacao;
    cout << "Data (AAAAMMDD): ";
    cin >> data;
    cout << "Quantidade: ";
    cin >> quantidade;
    
    // Busca preço médio nos dados históricos
    double precoMedio = ServicoDadosHistoricos::buscarPrecoMedio(codigoNegociacao, data);
    if (precoMedio == 0.0) {
        cout << "Papel nao encontrado na data especificada." << endl;
        return;
    }
    
    double precoTotal = precoMedio * quantidade;
    
    cout << "Preco medio: " << precoMedio << endl;
    cout << "Preco total: " << precoTotal << endl;
    
    if (ServicoOrdem::criarOrdem(codigo, codigoNegociacao, data, precoTotal, quantidade, codigoCarteira)) {
        cout << "Ordem criada com sucesso!" << endl;
    } else {
        cout << "Erro ao criar ordem. Verifique os dados." << endl;
    }
}

void IUOrdem::excluirOrdem() {
    string codigo;
    cout << "\n===== EXCLUIR ORDEM =====" << endl;
    cout << "Codigo da ordem a excluir: ";
    cin >> codigo;
    
    if (ServicoOrdem::excluirOrdem(codigo)) {
        cout << "Ordem excluida com sucesso!" << endl;
    } else {
        cout << "Erro ao excluir ordem. Verifique o codigo." << endl;
    }
}

void IUOrdem::listarOrdens() {
    string codigoCarteira;
    cout << "\n===== LISTA DE ORDENS =====" << endl;
    cout << "Codigo da carteira: ";
    cin >> codigoCarteira;
    
    vector<Ordem*> ordens = ServicoOrdem::listarOrdensPorCarteira(codigoCarteira);
    
    if (ordens.empty()) {
        cout << "Nenhuma ordem cadastrada para esta carteira." << endl;
    } else {
        for (auto ordem : ordens) {
            cout << "Codigo: " << ordem->getCodigo() << endl;
            cout << "Codigo negociacao: " << ordem->getCodigoNegociacao() << endl;
            cout << "Data: " << ordem->getData() << endl;
            cout << "Preco: " << ordem->getPreco() << endl;
            cout << "Quantidade: " << ordem->getQuantidade() << endl;
            cout << "---------------------" << endl;
        }
    }
}

void IUOrdem::mostrarDetalhesOrdem() {
    string codigo;
    cout << "\n===== DETALHES DA ORDEM =====" << endl;
    cout << "Codigo da ordem: ";
    cin >> codigo;
    
    Ordem* ordem = ServicoOrdem::buscarOrdem(codigo);
    if (ordem) {
        cout << "Codigo: " << ordem->getCodigo() << endl;
        cout << "Codigo negociacao: " << ordem->getCodigoNegociacao() << endl;
        cout << "Data: " << ordem->getData() << endl;
        cout << "Preco: " << ordem->getPreco() << endl;
        cout << "Quantidade: " << ordem->getQuantidade() << endl;
    } else {
        cout << "Ordem nao encontrada." << endl;
    }
}