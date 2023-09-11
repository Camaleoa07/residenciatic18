#include <iostream>
#include <string.h>
#include <vector>
using namespace std;


struct minhaData
{
    int dia, mes, ano;
};
struct titulo_eleitor
{
    string nome;
    minhaData dt_nasc;
    string num_inscr;
    string zona, secao;
    string municipio, uf;
    minhaData dt_Emiss;
};

void mostra_data(minhaData umaData)
{
    cout << umaData.dia << "/" << umaData.mes << "/" << umaData.ano << endl;
}
void le_data(minhaData *novaData)
{
    cin >> novaData->dia >> novaData->mes >> novaData->ano;
}

int main()
{
    titulo_eleitor el;
    cout << "Digite o nome do eleitor: ";
    getline(cin, el.nome);
    cout << "Digite a data de nascimento: ";
    le_data(&el.dt_nasc);
    cout << endl
         << endl
         << endl;
    cout << "-----Título Eleitoral-----" << endl;
    cout << "Nome: " << el.nome << endl;
    mostra_data(el.dt_nasc);
    cout << endl
         << endl;
    return 0;
}