#ifndef IU_ORDEM_HPP
#define IU_ORDEM_HPP

#include <string>

class IUOrdem {
public:
    void menuOrdem();
    
private:
    void criarOrdem();
    void excluirOrdem();
    void listarOrdens();
    void mostrarDetalhesOrdem();
};

#endif