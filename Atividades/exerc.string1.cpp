#include <iostream>
#include <cstring>

using namespace std;

int main()
{

    string nome1;
    string nome2;
    cin >> nome1 >> nome2;

    string nomeCompleto = nome1 + " " + nome2;
    cout << nomeCompleto;

    return 0;
}