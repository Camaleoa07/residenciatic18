#include <iostream>
#include <ctime>

struct Data {
    int dia;
    int mes;
    int ano;
};
void limparTela() {
    std::system("clear");
    
}
int main() {
    Data dataAtual;
    
    
    dataAtual.dia = 14;
    dataAtual.mes = 9; 
    dataAtual.ano = 2023;
    
    
    std::cout << "Data atual: " << dataAtual.dia << "/" << dataAtual.mes << "/" << dataAtual.ano << std::endl;
    
    return 0;
}
