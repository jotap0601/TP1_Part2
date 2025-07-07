#include "Ordem.hpp"

Ordem::Ordem(const std::string& codigo, const std::string& codigoNegociacao, 
             const std::string& data, double preco, int quantidade)
    : codigo(codigo), codigoNegociacao(codigoNegociacao), 
      data(data), preco(preco), quantidade(quantidade) {}

std::string Ordem::getCodigo() const {
    return codigo;
}

std::string Ordem::getCodigoNegociacao() const {
    return codigoNegociacao;
}

std::string Ordem::getData() const {
    return data;
}

double Ordem::getPreco() const {
    return preco;
}

int Ordem::getQuantidade() const {
    return quantidade;
}