#include "RepositorioCarteira.hpp"
#include <algorithm>

// Inicialização da variável estática
std::vector<Carteira*> RepositorioCarteira::carteiras;

Carteira* RepositorioCarteira::buscarCarteira(const std::string& codigo) {
    auto it = std::find_if(carteiras.begin(), carteiras.end(),
        [&codigo](Carteira* c) { return c->getCodigo() == codigo; });

    return it != carteiras.end() ? *it : nullptr;
}

std::vector<Carteira*> RepositorioCarteira::listarCarteirasPorConta(const std::string& cpfConta) {
    // Implementação simplificada - na prática, precisaria associar carteiras a contas
    std::vector<Carteira*> resultado;
    for (auto carteira : carteiras) {
        // Aqui deveria haver um filtro real por CPF se Carteira tivesse essa info
        resultado.push_back(carteira);
    }
    return resultado;
}

bool RepositorioCarteira::criarCarteira(const std::string& codigo, const std::string& nome,
                                       Perfil perfil, const std::string& cpfConta) {
    if (buscarCarteira(codigo)) return false;

    carteiras.push_back(new Carteira(codigo, nome, perfil));
    return true;
}

bool RepositorioCarteira::editarCarteira(const std::string& codigo, const std::string& nome, Perfil perfil) {
    Carteira* carteira = buscarCarteira(codigo);
    if (!carteira) return false;

    carteira->setNome(nome);
    carteira->setPerfil(perfil);
    return true;
}

bool RepositorioCarteira::excluirCarteira(const std::string& codigo) {
    auto it = std::find_if(carteiras.begin(), carteiras.end(),
        [&codigo](Carteira* c) { return c->getCodigo() == codigo; });

    if (it == carteiras.end()) return false;

    delete *it;
    carteiras.erase(it);
    return true;
}
