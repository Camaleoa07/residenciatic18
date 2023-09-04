#include <iostream> 
using namespace std;

int main() {
    int s=0, maior=0, temp=0;
    for (int i = 0; i < 5; i++)
    {
        cout << "Digite a temperatura: ";
        cin >> temp;
        if (temp > maior)
            maior = temp;

    }

    cout << maior << endl;
    
    


    return 0;
}