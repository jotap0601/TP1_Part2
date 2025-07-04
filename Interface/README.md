\# Sistema Bancário Modular - C++



\## Sobre o Projeto

Este é um projeto simples de sistema bancário feito em \*\*C++\*\*, dividido em módulos para facilitar o aprendizado e a organização do código.  

Com ele, você pode criar contas, acessar contas existentes, transferir dinheiro entre contas, editar e excluir informações, tudo isso através de menus interativos no terminal.



O projeto já está preparado para incluir funcionalidades mais avançadas como \*\*gestão de carteiras de investimento e ordens de compra e venda\*\* (os módulos já foram criados e estão prontos para expansão).



---



\## O que já está funcionando:

\- Criar contas

\- Acessar contas já existentes (login)

\- Consultar saldo

\- Transferir dinheiro entre contas

\- Editar nome da conta

\- Excluir contas

\- Validação de CPF (tamanho correto) e senha (mínimo de 6 caracteres)

\- Módulos de carteiras e ordens criados (funcionalidade ainda a implementar)



---



\## Estrutura do Projeto

```text

Projeto/

├── main.cpp                # Arquivo principal

├── Makefile                # Arquivo para compilar no terminal

├── apresentacao/           # Interface com o usuário

├── servico/                # Lógica das operações

├── repositorio/            # Base de dados em memória

├── dominio/                # Dados da conta (CPF, saldo, etc.)

└── validacao/              # Validações de CPF e senha

```



---



\## Como Compilar e Executar no Terminal

1\. Abra o terminal na pasta `Projeto`.

2\. Digite:

```bash

make

```

3\. Execute o sistema:

```bash

./sistema

```

4\. Para limpar os arquivos compilados:

```bash

make clean

```



---



\## Como Executar no Dev-C++

1\. Crie um \*\*projeto console vazio\*\* no Dev-C++.

2\. Copie todas as pastas (`apresentacao`, `servico`, `repositorio`, `dominio`, `validacao`) para dentro do projeto.

3\. Adicione \*\*todos os arquivos .cpp e .hpp\*\* no projeto.

4\. Compile e execute normalmente.



---



\## Melhorias Futuras

\- Salvar contas em arquivos (para manter os dados ao fechar o programa)

\- Implementar o gerenciamento de carteiras e ordens de investimento

\- Criar uma validação real de CPF (com cálculo dos dígitos verificadores)

\- Criar uma validação de senha mais forte (letras, números e símbolos)

\- Criar uma interface gráfica ou melhorar a apresentação no terminal



---



\## Sobre Contribuição

Caso queira melhorar ou expandir o sistema, sinta-se à vontade para enviar sugestões ou colaborar com o projeto.



---



\## Obrigado por conferir este projeto.

Se tiver dúvidas ou quiser desenvolver mais funcionalidades, estou à disposição para ajudar.

João Pedro de Oliveira Carrijo
RA:232011387


