#include <iostream>
using namespace std;

void resto10(int &k)
{
    if (k >= 10)
        k = k % 10;
    cout << "Valor de k " << k;
}

int main()
{
    int A;
    cout << "Digite um valor ";
    cin >> A;
    resto10 (A);
    cout << "O novo valor " << A;


    return 0;
}