#include <iostream>
#include <cstdlib> 
#include <ctime>   
using namespace std;

int main() {
    int numElementos, valorMinimo, valorMaximo;

    cout << "Digite o número de elementos: ";
    cin >> numElementos;

    cout << "Digite o valor mínimo: ";
    cin >> valorMinimo;

    cout << "Digite o valor máximo: ";
    cin >> valorMaximo;

    
    std::srand(static_cast<unsigned>(std::time(nullptr)));

   
    int numeros[numElementos];

    
    int maior = valorMinimo;
    int menor = valorMaximo;
    for (int i = 0; i < numElementos; i++) {
        numeros[i] = std::rand() % (valorMaximo - valorMinimo + 1) + valorMinimo;
        if (numeros[i] > maior) {
            maior = numeros[i];
        }
        if (numeros[i] < menor) {
            menor = numeros[i];
        }
    }

    cout << "Os números gerados aleatoriamente são: ";
    for (int i = 0; i < numElementos; i++) {
        cout << numeros[i] << " ";
    }
    cout << "\nMaior valor: " << maior << "\nMenor valor: " << menor << std::endl;

    return 0;
}
