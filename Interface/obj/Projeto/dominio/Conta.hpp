
#ifndef CONTA_HPP
#define CONTA_HPP

#include <string>
using namespace std;

class Conta {
private:
    string cpf, nome, senha;
    double saldo = 0.0;
public:
    void preencherConta();
    string getCpf() const { return cpf; }
    string getSenha() const { return senha; }
    string getNome() const { return nome; }
    double getSaldo() const { return saldo; }
    void depositar(double valor) { saldo += valor; }
    void sacar(double valor) { saldo -= valor; }
    void setNome(const string& novoNome) { nome = novoNome; }
};

#endif
