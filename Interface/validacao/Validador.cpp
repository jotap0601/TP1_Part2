
#include "Validador.hpp"

bool Validador::validarCpf(const string& cpf) {
    return cpf.length() == 11;
}

bool Validador::validarSenha(const string& senha) {
    return senha.length() >= 6;
}
