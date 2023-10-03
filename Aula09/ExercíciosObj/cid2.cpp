#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Cidade
{
public:
    string nome;

    Cidade(const string &n) : nome(n) {}
};

class Estado
{
public:
    string nome;
    string sigla;
    vector<Cidade> cidades;

    Estado(const string &n, const string &s) : nome(n), sigla(s) {}

    void adicionarCidade(const string &nomeCidade)
    {
        cidades.push_back(Cidade(nomeCidade));
    }
};

int main()
{
    vector<Estado> estados;

    int numEstados;
    cout << "Quantos Estados deseja criar? ";
    cin >> numEstados;

    for (int i = 0; i < numEstados; i++)
    {
        string nomeEstado, siglaEstado;
        cout << "Nome do Estado " << i + 1 << ": ";
        cin >> nomeEstado;
        cout << "Sigla do Estado " << i + 1 << ": ";
        cin >> siglaEstado;

        estados.push_back(Estado(nomeEstado, siglaEstado));
    }

    for (Estado &estado : estados)
    {
        int numCidades;
        cout << "Quantas Cidades deseja criar para o Estado " << estado.nome << "? ";
        cin >> numCidades;

        for (int i = 0; i < numCidades; i++)
        {
            string nomeCidade;
            cout << "Nome da Cidade " << i + 1 << ": ";
            cin >> nomeCidade;

            estado.adicionarCidade(nomeCidade);
        }
    }

    cout << "\nInformações sobre Estados e Cidades:" << endl;
    for (const Estado &estado : estados)
    {
        cout << "Estado: " << estado.nome << " (" << estado.sigla << ")" << endl;
        for (const Cidade &cidade : estado.cidades)
        {
            cout << "  Cidade: " << cidade.nome << endl;
        }
    }

    return 0;
}