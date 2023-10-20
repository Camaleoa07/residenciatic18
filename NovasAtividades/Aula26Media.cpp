#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int numElementos, valorMinimo, valorMaximo;

    cout << "Digite o número de elementos: ";
    cin >> numElementos;

    cout << "Digite o valor mínimo: ";
    cin >> valorMinimo;

    cout << "Digite o valor máximo: ";
    cin >> valorMaximo;

    srand(static_cast<unsigned>(time(nullptr)));

    int numeros[numElementos];

    int soma = 0;
    for (int i = 0; i < numElementos; i++)
    {
        numeros[i] = std::rand() % (valorMaximo - valorMinimo + 1) + valorMinimo;
        soma += numeros[i];
    }

    double media = static_cast<double>(soma) / numElementos;

    cout << "Os números gerados aleatoriamente são: ";
    for (int i = 0; i < numElementos; i++)
    {
        cout << numeros[i] << " ";
    }
    cout << "\nMédia: " << media << std::endl;

    return 0;
}
