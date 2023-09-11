#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

struct titulo_eleitor
{
    string nome;
    int dia_nasc, mes_nasc, ano_nasc;
    string num_inscr;
    string zona, secao;
    string municipio, uf;
    int dia_emiss, mes_emiss, ano_emiss;
};

int main()
{
    titulo_eleitor el;
    cout << "Digite o nome do eleitor: ";
    getline(cin, el.nome);
    cout << "Digite a data de nascimento: ";
    cin >> el.dia_nasc >> el.mes_nasc >> el.ano_nasc;
    cout << endl
         << endl
         << endl;
    cout << "-----Título Eleitoral-----" << endl;
    cout << "Nome: " << el.nome << endl;
    cout << "Data de Nascimento: " << el.dia_nasc << "/" << el.ano_nasc << endl;
    cout << endl
         << endl;
    return 0;
}