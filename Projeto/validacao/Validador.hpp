
#ifndef VALIDADOR_HPP
#define VALIDADOR_HPP

#include <string>
using namespace std;

class Validador {
public:
    static bool validarCpf(const string& cpf);
    static bool validarSenha(const string& senha);
    static bool validarNome(const string& nome);
};

#endif
