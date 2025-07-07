#ifndef SERVICO_DADOS_HISTORICOS_HPP
#define SERVICO_DADOS_HISTORICOS_HPP

#include <string>

class ServicoDadosHistoricos {
public:
    static double buscarPrecoMedio(const std::string& codigoNegociacao, const std::string& data);
};

#endif