#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Cliente
{
    string nome;
    string cpf;
};

void lerDadosCliente(Cliente &c)
{
    cout << "Digite o nome do cliente: ";
    getline(cin, c.nome);
    cout << "Digite o CPF do cliente: ";
    getline(cin, c.cpf);
}

void mostrarDadosCliente(Cliente c)
{
    cout << "Nome: " << c.nome << endl;
    cout << "CPF: " << c.cpf << endl;
}

int main()
{
    vector<Cliente> clientes;
    int opcao;

    while (true)
    {
        cout << "\nMenu de Opções:" << endl;
        cout << "1. Novo Cliente" << endl;
        cout << "2. Encontrar Cliente" << endl;
        cout << "3. Excluir Cliente" << endl;
        cout << "4. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;
        cin.ignore();

        switch (opcao)
        {
        case 1:
        {
            Cliente novoCliente;
            lerDadosCliente(novoCliente);
            clientes.push_back(novoCliente);
            cout << "Cliente adicionado com sucesso!" << endl;
            break;
        }
        case 2:
        {
            string cpfBusca;
            cout << "Digite o CPF do cliente a ser encontrado: ";
            getline(cin, cpfBusca);

            bool encontrado = false;
            for (const Cliente &cliente : clientes)
            {
                if (cliente.cpf == cpfBusca)
                {
                    mostrarDadosCliente(cliente);
                    encontrado = true;
                    break;
                }
            }

            if (!encontrado)
            {
                cout << "Cliente não encontrado." << endl;
            }
            break;
        }
        case 3:
        {
            string cpfExcluir;
            cout << "Digite o CPF do cliente a ser excluído: ";
            getline(cin, cpfExcluir);

            for (auto it = clientes.begin(); it != clientes.end(); ++it)
            {
                if (it->cpf == cpfExcluir)
                {
                    it = clientes.erase(it);
                    cout << "Cliente excluído com sucesso!" << endl;
                    break;
                }
            }
            break;
        }
        case 4:
            cout << "Saindo do programa." << endl;
            return 0;
        default:
            cout << "Opção inválida. Tente novamente." << endl;
            break;
        }
    }

    return 0;
}