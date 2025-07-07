#include "Validador.hpp"
#include <cctype>
#include <string>
#include <set>
#include <iostream>

using namespace std;

bool Validador::validarNome(const std::string& nome) {
    if (nome.length() > 20 || nome.empty()) {
        cout << "Erro: O nome deve ter entre 1 e 20 caracteres." << endl;
        return false;
    }

    if (nome.find("  ") != string::npos) {
        cout << "Erro: O nome nao pode conter espacos em branco em sequencia." << endl;
        return false;
    }

    for (char c : nome) {
        if (!isalnum(c) && c != ' ') {
            cout << "Erro: O nome deve conter apenas letras, numeros e espacos." << endl;
            return false;
        }
    }

    return true;
}

bool Validador::validarSenha(const std::string& senha) {
    if (senha.length() <= 6) {
        cout << "Erro: A senha deve ter pelo menos 6 caracteres." << endl;
        return false;
    }

    bool temDigit = false;
    bool temLower = false;
    bool temUpper = false;
    bool temSpecial = false;
    const string specialChars = "!#$%&@";
    set<char> uniqueChars;

    for (char c : senha) {
        if (uniqueChars.count(c)) {
            cout << "Erro: A senha nao pode ter caracteres duplicados." << endl;
            return false;
        }
        uniqueChars.insert(c);

        if (isdigit(c)) temDigit = true;
        else if (islower(c)) temLower = true;
        else if (isupper(c)) temUpper = true;
        else if (specialChars.find(c) != string::npos) temSpecial = true;
        else {
            cout << "Erro: A senha contem caracteres invalidos. Use apenas letras, numeros e os simbolos !,@,#, $, %, &." << endl;
            return false;
        }
    }

    if (!temDigit || !temLower || !temUpper || !temSpecial) {
        cout << "Erro: A senha deve conter pelo menos uma letra maiuscula, uma minuscula, um numero e um caractere especial (!,@,#,$,%,&)." << endl;
        return false;
    }

    return true;
}

bool Validador::validarCpf(const std::string& cpf) {
    if (cpf.length() != 11 || cpf.find_first_not_of("0123456789") != string::npos) {
        cout << "Erro: CPF deve conter 11 digitos numericos." << endl;
        return false;
    }

    if (cpf == "00000000000" || cpf == "11111111111" || cpf == "22222222222" ||
        cpf == "33333333333" || cpf == "44444444444" || cpf == "55555555555" ||
        cpf == "66666666666" || cpf == "77777777777" || cpf == "88888888888" ||
        cpf == "99999999999") {
        cout << "Erro: CPF invalido." << endl;
        return false;
    }

    int sum = 0;
    for (int i = 0; i < 9; ++i) {
        sum += (cpf[i] - '0') * (10 - i);
    }
    int first_digit = (sum % 11 < 2) ? 0 : 11 - (sum % 11);
    if ((cpf[9] - '0') != first_digit) {
        cout << "Erro: Digito verificador do CPF invalido." << endl;
        return false;
    }

    sum = 0;
    for (int i = 0; i < 10; ++i) {
        sum += (cpf[i] - '0') * (11 - i);
    }
    int second_digit = (sum % 11 < 2) ? 0 : 11 - (sum % 11);
    if ((cpf[10] - '0') != second_digit) {
        cout << "Erro: Digito verificador do CPF invalido." << endl;
        return false;
    }

    return true;
}
