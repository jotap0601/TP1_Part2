
#include "RepositorioConta.hpp"

vector<Conta> RepositorioConta::contas;

void RepositorioConta::adicionarConta(const Conta& conta) {
    contas.push_back(conta);
}

Conta* RepositorioConta::buscarConta(const string& cpf, const string& senha) {
    for (auto& conta : contas) {
        if (conta.getCpf() == cpf && conta.getSenha() == senha) {
            return &conta;
        }
    }
    return nullptr;
}

Conta* RepositorioConta::buscarContaPorCpf(const string& cpf) {
    for (auto& conta : contas) {
        if (conta.getCpf() == cpf) {
            return &conta;
        }
    }
    return nullptr;
}

bool RepositorioConta::excluirConta(const string& cpf, const string& senha) {
    for (auto it = contas.begin(); it != contas.end(); ++it) {
        if (it->getCpf() == cpf && it->getSenha() == senha) {
            contas.erase(it);
            return true;
        }
    }
    return false;
}

bool RepositorioConta::editarConta(const string& cpf, const string& senha, const string& novoNome) {
    for (auto& conta : contas) {
        if (conta.getCpf() == cpf && conta.getSenha() == senha) {
            conta.setNome(novoNome);
            return true;
        }
    }
    return false;
}
