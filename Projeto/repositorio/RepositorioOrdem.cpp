#include "RepositorioOrdem.hpp"
#include <algorithm>

std::vector<Ordem*> RepositorioOrdem::ordens;

Ordem* RepositorioOrdem::buscarOrdem(const std::string& codigo) {
    auto it = std::find_if(ordens.begin(), ordens.end(), 
        [&codigo](Ordem* o) { return o->getCodigo() == codigo; });
    
    return it != ordens.end() ? *it : nullptr;
}

std::vector<Ordem*> RepositorioOrdem::listarOrdensPorCarteira(const std::string& codigoCarteira) {
    // Implementação simplificada - na prática, precisaria associar ordens a carteiras
    std::vector<Ordem*> resultado;
    for (auto ordem : ordens) {
        resultado.push_back(ordem);
    }
    return resultado;
}

bool RepositorioOrdem::criarOrdem(const std::string& codigo, const std::string& codigoNegociacao, 
                                 const std::string& data, double preco, int quantidade, 
                                 const std::string& codigoCarteira) {
    if (buscarOrdem(codigo)) return false;
    
    ordens.push_back(new Ordem(codigo, codigoNegociacao, data, preco, quantidade));
    return true;
}

bool RepositorioOrdem::excluirOrdem(const std::string& codigo) {
    auto it = std::find_if(ordens.begin(), ordens.end(), 
        [&codigo](Ordem* o) { return o->getCodigo() == codigo; });
    
    if (it == ordens.end()) return false;
    
    delete *it;
    ordens.erase(it);
    return true;
}