#ifndef REPOSITORIO_CARTEIRA_HPP
#define REPOSITORIO_CARTEIRA_HPP

#include <vector>
#include <string>
#include "../dominio/Carteira.hpp"

class RepositorioCarteira {
private:
    static std::vector<Carteira*> carteiras;

public:
    static Carteira* buscarCarteira(const std::string& codigo);
    static std::vector<Carteira*> listarCarteirasPorConta(const std::string& cpfConta);
    static bool criarCarteira(const std::string& codigo, const std::string& nome, 
                             Perfil perfil, const std::string& cpfConta);
    static bool editarCarteira(const std::string& codigo, const std::string& nome, Perfil perfil);
    static bool excluirCarteira(const std::string& codigo);
};

#endif