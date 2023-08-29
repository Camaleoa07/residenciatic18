//trio: Thais, Ticiana e Dan

#include <iostream>
#include <iomanip>


using namespace std;
int main()

{
    char caractere[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    for (int i = 0; i <= 9; i++)
    {
        std::cout << "Decimal: " << ((int)caractere[i]) << endl;
        std::cout << "Octal: " << std::oct << ((int)caractere[i]) << endl;
        std::cout << "Hexadecimal: " << std::hex << ((int)caractere[i]) << endl;
    }

    return 0;
}
