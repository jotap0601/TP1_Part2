#ifndef REPOSITORIO_ORDEM_HPP
#define REPOSITORIO_ORDEM_HPP

#include <vector>
#include <string>
#include "../dominio/Ordem.hpp"

class RepositorioOrdem {
private:
    static std::vector<Ordem*> ordens;

public:
    static Ordem* buscarOrdem(const std::string& codigo);
    static std::vector<Ordem*> listarOrdensPorCarteira(const std::string& codigoCarteira);
    static bool criarOrdem(const std::string& codigo, const std::string& codigoNegociacao, 
                          const std::string& data, double preco, int quantidade, 
                          const std::string& codigoCarteira);
    static bool excluirOrdem(const std::string& codigo);
};

#endif