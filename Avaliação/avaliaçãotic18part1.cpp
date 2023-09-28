#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Cliente
{
    string nome;
    string cpf;
    string Data_N;
    string cnh;
};

struct Veiculo
{
    string modelo;
    string placa;
    string renavan;
    string localizacao;
    string dataRetirada;
    string dataEntrega;
    string lojaRetirada;
};

void incluirCliente(vector<Cliente> &clientes)
{
    Cliente cliente;
    cout << "Digite o nome do cliente: ";
    cin.ignore();
    getline(cin, cliente.nome);
    cout << "Digite o CPF do cliente: ";
    cin >> cliente.cpf;
    cout << "Digite a Data de Nascimento do cliente: ";
    cin.ignore();
    getline(cin, cliente.Data_N);
    cout << "Digite a CNH do Cliente:";
    cin >> cliente.cnh;
    clientes.push_back(cliente);
    cout << "Cliente incluido com sucesso." << endl;
}

void excluirCliente(vector<Cliente> &clientes)
{
    string cpf;
    cout << "Digite o CPF do cliente a ser excluido: ";
    cin >> cpf;
    for (size_t i = 0; i < clientes.size(); i++)
    {
        if (clientes[i].cpf == cpf)
        {
            clientes.erase(clientes.begin() + i);
            cout << "Cliente excluido com sucesso." << endl;
            return;
        }
    }
    cout << "Cliente nao encontrado." << endl;
}

void listarClientes(const vector<Cliente> &clientes)
{
    cout << "Lista de Clientes:" << endl;
    for (const Cliente &cliente : clientes)
    {
        cout << "Nome: " << cliente.nome << endl;
        cout << "CPF: " << cliente.cpf << endl;
        cout << "Data de Nascimento: " << cliente.Data_N << endl;
        cout << "-------------------" << endl;
    }
}

void incluirVeiculo(vector<Veiculo> &veiculos)
{
    Veiculo veiculo;
    cout << "Digite o modelo do veiculo: ";
    cin.ignore();
    getline(cin, veiculo.modelo);
    cout << "Digite a placa do veiculo: ";
    cin >> veiculo.placa;
    cout << "Digite o Renavan do veiculo: ";
    cin.ignore();
    getline(cin, veiculo.renavan);
    cout << "Digite a localizacao do veiculo: ";
    getline(cin, veiculo.localizacao);
    cout << "Digite a data de retirada do veiculo (dd/mm/aaaa): ";
    getline(cin, veiculo.dataRetirada);
    cout << "Digite a data de entrega prevista do veiculo (dd/mm/aaaa): ";
    getline(cin, veiculo.dataEntrega);
    cout << "Digite a loja de retirada do veiculo: ";
    getline(cin, veiculo.lojaRetirada);
    veiculos.push_back(veiculo);
    cout << "Veiculo incluido com sucesso." << endl;
}


void excluirVeiculo(vector<Veiculo> &veiculos)
{
    string placa;
    cout << "Digite a placa do veiculo a ser excluido: ";
    cin >> placa;
    for (size_t i = 0; i < veiculos.size(); i++)
    {
        if (veiculos[i].placa == placa)
        {
            veiculos.erase(veiculos.begin() + i);
            cout << "Veiculo excluido com sucesso." << endl;
            return;
        }
    }
    cout << "Veiculo nao encontrado." << endl;
}


void listarVeiculos(const vector<Veiculo> &veiculos)
{
    cout << "Lista de Veiculos:" << endl;
    for (const Veiculo &veiculo : veiculos)
    {
        cout << "Modelo: " << veiculo.modelo << endl;
        cout << "Placa: " << veiculo.placa << endl;
        cout << "Renavan: " << veiculo.renavan << endl;
        cout << "Localizacao: " << veiculo.localizacao << endl;
        cout << "Data de Retirada: " << veiculo.dataRetirada << endl;
        cout << "Data de Entrega Prevista: " << veiculo.dataEntrega << endl;
        cout << "Loja de Retirada: " << veiculo.lojaRetirada << endl;
        cout << "-------------------" << endl;
    }
}

int main()
{
    vector<Cliente> clientes;
    vector<Veiculo> veiculos;

    int opcao;

    do
    {
        cout << "Menu:" << endl;
        cout << "1. Incluir Cliente" << endl;
        cout << "2. Excluir Cliente" << endl;
        cout << "3. Listar Clientes" << endl;
        cout << "4. Incluir Veiculo" << endl;
        cout << "5. Excluir Veiculo" << endl;
        cout << "6. Listar Veiculos" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            incluirCliente(clientes);
            break;
        case 2:
            excluirCliente(clientes);
            break;
        case 3:
            listarClientes(clientes);
            break;
        case 4:
            incluirVeiculo(veiculos);
            break;
        case 5:
            excluirVeiculo(veiculos);
            break;
        case 6:
            listarVeiculos(veiculos);
            break;
        case 0:
            cout << "Saindo do programa." << endl;
            break;
        default:
            cout << "Opcao invalida. Tente novamente." << endl;
            break;
        }
    } while (opcao != 0);

    return 0;
}