#include "ServicoDadosHistoricos.hpp"
#include <fstream>
#include <sstream>

double ServicoDadosHistoricos::buscarPrecoMedio(const std::string& codigoNegociacao, const std::string& data) {
    std::ifstream arquivo("DADOS_HISTORICOS.TXT");
    std::string linha;
    
    while (std::getline(arquivo, linha)) {
        if (linha.substr(0, 12).find(codigoNegociacao) != std::string::npos) {
            if (linha.substr(13, 8) == data) {
                double precoMedio = std::stod(linha.substr(21, 10)) / 100.0;
                arquivo.close();
                return precoMedio;
            }
        }
    }
    
    arquivo.close();
    return 0.0; // Retorna 0 se não encontrar
}