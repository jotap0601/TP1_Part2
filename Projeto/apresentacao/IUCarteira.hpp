#ifndef IU_CARTEIRA_HPP
#define IU_CARTEIRA_HPP

#include <string>

class IUCarteira {
public:
    void menuCarteira();
    
private:
    void criarCarteira();
    void editarCarteira();
    void excluirCarteira();
    void listarCarteiras();
    void mostrarDetalhesCarteira();
};

#endif