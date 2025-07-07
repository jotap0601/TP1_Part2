
#ifndef REPOSITORIOCONTA_HPP
#define REPOSITORIOCONTA_HPP

#include "../dominio/Conta.hpp"
#include <vector>
using namespace std;

class RepositorioConta {
private:
    static vector<Conta> contas;
public:
    static void adicionarConta(const Conta& conta);
    static Conta* buscarConta(const string& cpf, const string& senha);
    static Conta* buscarContaPorCpf(const string& cpf);
    static bool excluirConta(const string& cpf, const string& senha);
    static bool editarConta(const string& cpf, const string& senha, const string& novoNome);
};

#endif
