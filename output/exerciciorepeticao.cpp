#include <iostream>

using namespace std;

int main()
{
    int x;
    do
    {

        cout << "Digite um valor: ";
        cin >> x;
        cout << "O valor digitado foi: " << x << endl;

    } while (x >= 0);

    return 0;
}