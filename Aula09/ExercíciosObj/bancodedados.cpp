#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class BancoDeDados
{
public:
    static void salvarDados(const vector<string> &dados)
    {
        ofstream arquivo_saida;
        arquivo_saida.open("exemplo.txt", ios_base::out);

        if (arquivo_saida.is_open())
        {
            for (const string &linha : dados)
            {
                arquivo_saida << linha << endl;
            }
            arquivo_saida.close();
            cout << "Dados salvos com sucesso." << endl;
        }
        else
        {
            cout << "Erro ao abrir o arquivo para salvar dados." << endl;
        }
    }

    static vector<string> recuperarDados()
    {
        vector<string> dados;

        ifstream arquivo_entrada;
        arquivo_entrada.open("exemplo.txt", ios_base::in);

        if (arquivo_entrada.is_open())
        {
            string linha;
            while (getline(arquivo_entrada, linha))
            {
                dados.push_back(linha);
            }
            arquivo_entrada.close();
        }
        else
        {
            cout << "Erro ao abrir o arquivo para recuperar dados." << endl;
        }

        return dados;
    }
};

int main()
{
    vector<string> dadosParaSalvar = {"Linha 1", "Linha 2", "Linha 3"};

    BancoDeDados::salvarDados(dadosParaSalvar);

    vector<string> dadosRecuperados = BancoDeDados::recuperarDados();

    cout << "Dados recuperados do arquivo:" << endl;
    for (const string &linha : dadosRecuperados)
    {
        cout << linha << endl;
    }

    return 0;
}