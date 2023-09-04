#include <iostream>

using namespace std;

int main()
{
    int a, resultado;
    cin >> a;
    resultado = a % 2;

    if (resultado == 0)
    {
        cout << "É par";
    }
    else
    {
        cout << "É ímpar";
    }

    return 0;
}