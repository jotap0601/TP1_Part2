#ifndef ORDEM_HPP
#define ORDEM_HPP

#include <string>

class Ordem {
private:
    std::string codigo;
    std::string codigoNegociacao;
    std::string data;
    double preco;
    int quantidade;

public:
    Ordem(const std::string& codigo, const std::string& codigoNegociacao, 
          const std::string& data, double preco, int quantidade);
    
    std::string getCodigo() const;
    std::string getCodigoNegociacao() const;
    std::string getData() const;
    double getPreco() const;
    int getQuantidade() const;
};

#endif