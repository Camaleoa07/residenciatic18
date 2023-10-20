#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

double encontrarMediana(vector<double> &numeros)
{
    int tamanho = numeros.size();
    sort(numeros.begin(), numeros.end());

    if (tamanho % 2 == 0)
    {
        return (numeros[tamanho / 2 - 1] + numeros[tamanho / 2]) / 2.0;
    }
    else
    {
        return numeros[tamanho / 2];
    }
}

int main()
{
    int numElementos, valorMinimo, valorMaximo;

    cout << "Insira o número de elementos: ";
    cin >> numElementos;

    cout << "Insira o valor mínimo: ";
    cin >> valorMinimo;

    cout << "Insira o valor máximo: ";
    cin >> valorMaximo;

    srand(time(0));

    vector<double> numeros;

    for (int i = 0; i < numElementos; i++)
    {
        double numero_aleatorio = valorMinimo + static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (valorMaximo - valorMinimo)));
        numeros.push_back(numero_aleatorio);
    }

    double mediana = encontrarMediana(numeros);

    cout << "A mediana dos números gerados é: " << mediana << endl;

    return 0;
}