#include <iostream>

struct data {
    int dia, mes, ano;

    int anosEntre(const data& outraData) {
        int anosDiferenca = outraData.ano - ano;
        
        if (outraData.mes < mes || (outraData.mes == mes && outraData.dia < dia)) {
            anosDiferenca--;
        }
        
        return anosDiferenca;
    }

    bool DataValida() {
        
        if (mes < 1 || mes > 12 || dia < 1 || dia > 31) {
            return false;
        }

        
        if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) {
            return false;
        }

        
        if (mes == 2) {
            if (dia > 29) {
                return false;
            }
            if (dia == 29 && (ano % 4 != 0 || (ano % 100 == 0 && ano % 400 != 0))) {
                return false;
            }
        }

        return true;
    }

    int diadasemana() {
       
        return 0;  
    }
};

int main() {
    data data1 = {14, 9, 2023};

    if (data1.DataValida()) {
        int anos = data1.anosEntre({14, 9, 2000});
        std::cout << "Anos entre as datas: " << anos << std::endl;

        int diaDaSemana = data1.diadasemana();
        std::cout << "Dia da semana: " << diaDaSemana << std::endl;
    } else {
        std::cout << "Data inválida." << std::endl;
    }

    return 0;
}
