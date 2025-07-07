#include "ServicoCarteira.hpp"
#include "../repositorio/RepositorioCarteira.hpp"
#include "../dominio/Perfil.hpp"
#include <algorithm>

Carteira* ServicoCarteira::buscarCarteira(const std::string& codigo) {
    return RepositorioCarteira::buscarCarteira(codigo);
}

std::vector<Carteira*> ServicoCarteira::listarCarteirasPorConta(const std::string& cpfConta) {
    return RepositorioCarteira::listarCarteirasPorConta(cpfConta);
}

bool ServicoCarteira::criarCarteira(const std::string& codigo, const std::string& nome,
                                   const std::string& perfil, const std::string& cpfConta) {
    Perfil perfilEnum;
    if (perfil == "CONSERVADOR") perfilEnum = Perfil::CONSERVADOR;
    else if (perfil == "MODERADO") perfilEnum = Perfil::MODERADO;
    else if (perfil == "AGRESSIVO") perfilEnum = Perfil::AGRESSIVO;
    else return false;

    return RepositorioCarteira::criarCarteira(codigo, nome, perfilEnum, cpfConta);
}

bool ServicoCarteira::editarCarteira(const std::string& codigo, const std::string& nome,
                                    const std::string& perfil) {
    Perfil perfilEnum;
    if (perfil == "CONSERVADOR") perfilEnum = Perfil::CONSERVADOR;
    else if (perfil == "MODERADO") perfilEnum = Perfil::MODERADO;
    else if (perfil == "AGRESSIVO") perfilEnum = Perfil::AGRESSIVO;
    else return false;

    return RepositorioCarteira::editarCarteira(codigo, nome, perfilEnum);
}

bool ServicoCarteira::excluirCarteira(const std::string& codigo) {
    return RepositorioCarteira::excluirCarteira(codigo);
}
