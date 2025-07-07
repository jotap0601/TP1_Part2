#include "Carteira.hpp"

Carteira::Carteira(const std::string& codigo, const std::string& nome, Perfil perfil) 
    : codigo(codigo), nome(nome), perfil(perfil), saldo(0.0) {}

std::string Carteira::getCodigo() const {
    return codigo;
}

std::string Carteira::getNome() const {
    return nome;
}

Perfil Carteira::getPerfil() const {
    return perfil;
}

double Carteira::getSaldo() const {
    return saldo;
}

void Carteira::setNome(const std::string& nome) {
    this->nome = nome;
}

void Carteira::setPerfil(Perfil perfil) {
    this->perfil = perfil;
}

void Carteira::atualizarSaldo(double valor) {
    saldo += valor;
}