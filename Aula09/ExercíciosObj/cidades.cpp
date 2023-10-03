#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Estado
{
public:
    string nome;
    string sigla;

    Estado(const string &n, const string &s) : nome(n), sigla(s) {}
};

class Cidade
{
public:
    string nome;
    Estado *estado;

    Cidade(const string &n, Estado *e) : nome(n), estado(e) {}
};

int main()
{
    vector<Estado *> estados;
    vector<Cidade *> cidades;

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

        Estado *estado = new Estado(nomeEstado, siglaEstado);
        estados.push_back(estado);
    }

    int numCidades;
    cout << "Quantas Cidades deseja criar? ";
    cin >> numCidades;

    for (int i = 0; i < numCidades; i++)
    {
        string nomeCidade;
        int estadoId;

        cout << "Nome da Cidade " << i + 1 << ": ";
        cin >> nomeCidade;
        cout << "ID do Estado ao qual a Cidade " << nomeCidade << " pertence: ";
        cin >> estadoId;

        if (estadoId >= 0 && estadoId < estados.size())
        {
            Cidade *cidade = new Cidade(nomeCidade, estados[estadoId]);
            cidades.push_back(cidade);
        }
        else
        {
            cout << "ID do Estado inválido. Certifique-se de que o ID está dentro do intervalo válido." << endl;
            i--;
        }
    }

    cout << "\nInformações sobre Estados:" << endl;
    for (const Estado *estado : estados)
    {
        cout << "Nome: " << estado->nome << ", Sigla: " << estado->sigla << endl;
    }

    cout << "\nInformações sobre Cidades:" << endl;
    for (const Cidade *cidade : cidades)
    {
        cout << "Nome: " << cidade->nome << ", Estado: " << cidade->estado->nome << " (" << cidade->estado->sigla << ")" << endl;
    }

    for (Estado *estado : estados)
    {
        delete estado;
    }

    for (Cidade *cidade : cidades)
    {
        delete cidade;
    }

    return 0;
}