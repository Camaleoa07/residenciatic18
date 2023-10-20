#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

double calcularDesvioPadrao(double array[], int tamanho) {
    double soma = 0.0, media, desvioPadrao = 0.0;

    for(int i = 0; i < tamanho; i++) {
        soma += array[i];
    }

    media = soma / tamanho;

    for(int i = 0; i < tamanho; i++) {
        desvioPadrao += pow(array[i] - media, 2);
    }

    return sqrt(desvioPadrao / tamanho);
}

int main() {
    int numElementos, valorMinimo, valorMaximo;

    cout << "Insira o número de elementos: ";
    cin >> numElementos;

    cout << "Insira o valor mínimo: ";
    cin >> valorMinimo;

    cout << "Insira o valor máximo: ";
    cin >> valorMaximo;

    double numeros[numElementos];

    
    srand(time(0));

    for(int i = 0; i < numElementos; i++) {
        numeros[i] = valorMinimo + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (valorMaximo - valorMinimo)));
    }

    
    double desvioPadrao = calcularDesvioPadrao(numeros, numElementos);

    cout << "O desvio padrão dos números gerados é: " << desvioPadrao << endl;

    return 0;
}