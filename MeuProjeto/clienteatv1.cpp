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
    cin.ignore();
    getline(cin, c.nome);
    cout << "Digite o CPF do cliente: ";
    getline(cin, c.cpf);
}

void mostrarDadosCliente(Cliente c)
{
    cout << "Nome: " << c.nome << endl;
    cout << "CPF: " << c.cpf << endl;
}

void deleteClient(vector<Cliente> &customers)
{
    string name;

    cout << endl;
    cout << "Digite o nome: ";
    cin.ignore();
    getline(cin, name);

    for (auto it = customers.begin(); it != customers.end(); ++it)
    {
        if (it->nome == name)
        {
            customers.erase(it);
            cout << "Cliente excluído com sucesso!" << endl;
            return;
        }
    }
    cout << "Cliente não encontrado." << endl;
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
        cout << "4. Listar Clientes" << endl;
        cout << "5. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;
        cin.ignore(); // Limpa o caractere de nova linha deixado pelo cin

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
            cin.ignore(); 
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
            deleteClient(clientes);   
            break;
        }
        case 4:
        {
            if (clientes.empty())
            {
                cout << "Nenhum cliente cadastrado ainda." << endl;
            }
            else
            {
                cout << "\nClientes Cadastrados:" << endl;
                for (const Cliente &cliente : clientes)
                {
                    mostrarDadosCliente(cliente);
                    cout << "------------------------" << endl;
                }
            }
            break;
        }
        case 5:
            cout << "Saindo do programa." << endl;
            return 0;
        default:
            cout << "Opção inválida. Tente novamente." << endl;
            break;
        }
    }

    return 0;
}