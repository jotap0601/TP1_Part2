#ifndef CARTEIRA_HPP
#define CARTEIRA_HPP

#include <string>
#include "Perfil.hpp"

class Carteira {
private:
    std::string codigo;
    std::string nome;
    Perfil perfil;
    double saldo;

public:
    Carteira(const std::string& codigo, const std::string& nome, Perfil perfil);
    
    std::string getCodigo() const;
    std::string getNome() const;
    Perfil getPerfil() const;
    double getSaldo() const;
    
    void setNome(const std::string& nome);
    void setPerfil(Perfil perfil);
    void atualizarSaldo(double valor);
};

#endif