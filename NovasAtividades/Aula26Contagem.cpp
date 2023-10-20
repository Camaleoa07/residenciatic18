#include <iostream>

int main()
{
    int numElementos, valorProcurado;

    std::cout << "Digite o número de elementos: ";
    std::cin >> numElementos;

    int numeros[numElementos];

    for (int i = 0; i < numElementos; i++)
    {
        std::cout << "Digite o número " << i + 1 << ": ";
        std::cin >> numeros[i];
    }

    std::cout << "Digite o valor que deseja contar: ";
    std::cin >> valorProcurado;

    int contagem = 0;

    for (int i = 0; i < numElementos; i++)
    {
        if (numeros[i] == valorProcurado)
        {
            contagem++;
        }
    }

    std::cout << "O valor " << valorProcurado << " ocorre " << contagem << " vezes nos números inseridos." << std::endl;

    return 0;
}
