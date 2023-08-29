#include <iostream>
//trio: Thais, Ticiana e Dan

#include <iomanip>
using namespace std;
int main()

{
    char caractere;

    cout << "Digite o caractere: "; 
    cin >> caractere;

    std::cout << "Decimal: " << ((int)caractere) << endl;
    std::cout << "Octal: " << std::oct << ((int)caractere) << endl;
    std::cout << "Hexadecimal: " << std::hex << ((int)caractere) << endl;

    return 0;
}
