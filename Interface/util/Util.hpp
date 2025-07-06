
#ifndef UTIL_HPP
#define UTIL_HPP

#include <iostream>
#include <cstdlib>
using namespace std;

void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pause() {
#ifdef _WIN32
    system("pause");
#else
    cout << "Pressione Enter para continuar...";
    cin.ignore();
    cin.get();
#endif
}

void exibirTitulo(const string& titulo) {
    limparTela();
    cout << "\033[1;34m===============================" << endl;
    cout << titulo << endl;
    cout << "===============================\033[0m" << endl;
}

#endif
