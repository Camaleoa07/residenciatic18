#include <iostream>
#include <string>
using namespace std;

struct Cliente {
    string nome;
    string cpf;
};

void lerDadosCliente(Cliente& c) {
    cout << "Digite o nome do cliente: ";
    getline(cin, c.nome);
    cout << "Digite o cpf do cliente: ";
    getline(cin, c.cpf);
}

void mostrarDadosCliente(Cliente c) {
    cout << "Nome: " << c.nome << endl;
    cout << "cpf: " << c.cpf << endl;
}

int main() {
    Cliente cliente1;
    lerDadosCliente(cliente1);
    mostrarDadosCliente(cliente1);
    return 0;
}

