#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

void criarHistograma(map<int, int> &histograma)
{
    cout << "Histograma:" << endl;
    for (auto const &elemento : histograma)
    {
        cout << elemento.first << " : ";
        for (int i = 0; i < elemento.second; i++)
        {
            cout << "X";
        }
        cout << endl;
    }
}

int main()
{
    string nomeArquivo;
    cout << "Insira o nome do arquivo com o conjunto de dados: ";
    cin >> nomeArquivo;

    ifstream arquivo(nomeArquivo);
    if (!arquivo)
    {
        cerr << "Não foi possível abrir o arquivo!" << endl;
        return 1;
    }

    map<int, int> histograma;
    int numero;
    while (arquivo >> numero)
    {
        histograma[numero]++;
    }

    criarHistograma(histograma);

    return 0;
}