
all:
	g++ -o sistema main.cpp \
	apresentacao/IUConta.cpp \
	apresentacao/IUCarteira.cpp \
	apresentacao/IUOrdem.cpp \
	servico/ServicoConta.cpp \
	repositorio/RepositorioConta.cpp \
	dominio/Conta.cpp \
	validacao/Validador.cpp \
	-Iapresentacao -Iservico -Idominio -Irepositorio -Ivalidacao

clean:
	rm sistema
