#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Veiculo
{
public:
    string Placa;
    string Modelo;
    string Ano;

    Veiculo(string placa, string modelo, string ano)
        : Placa(placa), Modelo(modelo), Ano(ano) {}
};

int main()
{
    vector<Veiculo> veiculos;

    while (true)
    {
        cout << "Menu de Opções:" << endl;
        cout << "1. Incluir" << endl;
        cout << "2. Excluir" << endl;
        cout << "3. Alterar" << endl;
        cout << "4. Listar" << endl;
        cout << "5. Localizar" << endl;
        cout << "0. Sair" << endl;

        int escolha;
        cin >> escolha;

        switch (escolha)
        {
        case 1:
        {
            string placa, modelo, ano;
            cout << "Informe a Placa: ";
            cin >> placa;
            cout << "Informe o Modelo: ";
            cin.ignore();
            getline(cin, modelo);
            cout << "Informe o Ano: ";
            cin >> ano;

            Veiculo novoVeiculo(placa, modelo, ano);
            veiculos.push_back(novoVeiculo);
            cout << "Veículo incluído com sucesso!" << endl;
        }
        break;

        case 2:
        {
            string placa;
            cout << "Informe a Placa do veículo a ser excluído: ";
            cin >> placa;

            for (auto it = veiculos.begin(); it != veiculos.end(); ++it)
            {
                if (it->Placa == placa)
                {
                    veiculos.erase(it);
                    cout << "Veículo excluído com sucesso!" << endl;
                    break;
                }
            }
        }
        break;

        case 3:
        {
            string placa;
            cout << "Informe a Placa do veículo a ser alterado: ";
            cin >> placa;

            for (auto &veiculo : veiculos)
            {
                if (veiculo.Placa == placa)
                {
                    cout << "Dados atuais do veículo:" << endl;
                    cout << "Placa: " << veiculo.Placa << endl;
                    cout << "Modelo: " << veiculo.Modelo << endl;
                    cout << "Ano: " << veiculo.Ano << endl;

                    int opcao;
                    cout << "Deseja alterar o Modelo? (1 para Sim, 0 para Não): ";
                    cin >> opcao;
                    if (opcao == 1)
                    {
                        cout << "Novo Modelo: ";
                        cin.ignore();
                        getline(cin, veiculo.Modelo);
                    }

                    cout << "Deseja alterar o Ano? (1 para Sim, 0 para Não): ";
                    cin >> opcao;
                    if (opcao == 1)
                    {
                        cout << "Novo Ano: ";
                        cin >> veiculo.Ano;
                    }

                    cout << "Veículo alterado com sucesso!" << endl;
                    break;
                }
            }
        }
        break;

        case 4:
            if (veiculos.empty())
            {
                cout << "Nenhum veículo disponível." << endl;
            }
            else
            {
                cout << "Lista de Veículos:" << endl;
                for (const auto &veiculo : veiculos)
                {
                    cout << "Placa: " << veiculo.Placa << endl;
                    cout << "Modelo: " << veiculo.Modelo << endl;
                    cout << "Ano: " << veiculo.Ano << endl;
                    cout << "-----------------------" << endl;
                }
            }
            break;

        case 5:
        {
            string placa;
            cout << "Informe a Placa do veículo a ser localizado: ";
            cin >> placa;

            for (const auto &veiculo : veiculos)
            {
                if (veiculo.Placa == placa)
                {
                    cout << "Placa: " << veiculo.Placa << endl;
                    cout << "Modelo: " << veiculo.Modelo << endl;
                    cout << "Ano: " << veiculo.Ano << endl;
                    break;
                }
            }
        }
        break;

        case 0:
            cout << "Encerrando o programa." << endl;
            return 0;

        default:
            cout << "Opção inválida. Tente novamente." << endl;
            break;
        }
    }

    return 0;
}
