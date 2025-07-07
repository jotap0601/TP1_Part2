#include "ServicoOrdem.hpp"
#include "../repositorio/RepositorioOrdem.hpp"

Ordem* ServicoOrdem::buscarOrdem(const std::string& codigo) {
    return RepositorioOrdem::buscarOrdem(codigo);
}

std::vector<Ordem*> ServicoOrdem::listarOrdensPorCarteira(const std::string& codigoCarteira) {
    return RepositorioOrdem::listarOrdensPorCarteira(codigoCarteira);
}

bool ServicoOrdem::criarOrdem(const std::string& codigo, const std::string& codigoNegociacao, 
                             const std::string& data, double preco, int quantidade, 
                             const std::string& codigoCarteira) {
    return RepositorioOrdem::criarOrdem(codigo, codigoNegociacao, data, preco, quantidade, codigoCarteira);
}

bool ServicoOrdem::excluirOrdem(const std::string& codigo) {
    return RepositorioOrdem::excluirOrdem(codigo);
}