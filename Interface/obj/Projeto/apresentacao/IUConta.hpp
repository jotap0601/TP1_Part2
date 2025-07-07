
#ifndef IUCONTA_HPP
#define IUCONTA_HPP

class IUConta {
public:
    void executar();
    void menu();
    void criarConta();
    void acessarConta();
    void menuContaLogada(class Conta* conta);
    void transferirDinheiro(class Conta* conta);
    void editarConta(class Conta* conta);
    void excluirConta(class Conta* conta);
};

#endif
