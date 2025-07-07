#ifndef SERVICO_CARTEIRA_HPP
#define SERVICO_CARTEIRA_HPP

#include <vector>
#include <string>
#include "../dominio/Carteira.hpp"

class ServicoCarteira {
public:
    static Carteira* buscarCarteira(const std::string& codigo);
    static std::vector<Carteira*> listarCarteirasPorConta(const std::string& cpfConta);
    static bool criarCarteira(const std::string& codigo, const std::string& nome, 
                             const std::string& perfil, const std::string& cpfConta);
    static bool editarCarteira(const std::string& codigo, const std::string& nome, 
                              const std::string& perfil);
    static bool excluirCarteira(const std::string& codigo);
};

#endif