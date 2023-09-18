#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Cliente
{
public:
    string CPF;
    string Nome;
    string Endereco;

    Cliente(string cpf, string nome, string endereco)
        : CPF(cpf), Nome(nome), Endereco(endereco) {}
};

int main()
{
    vector<Cliente> clientes;

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
            string cpf, nome, endereco;
            cout << "Informe o CPF: ";
            cin >> cpf;
            cout << "Informe o Nome: ";
            cin.ignore();
            getline(cin, nome);
            cout << "Informe o Endereço: ";
            getline(cin, endereco);

            Cliente novoCliente(cpf, nome, endereco);
            clientes.push_back(novoCliente);
            cout << "Cliente incluído com sucesso!" << endl;
        }
        break;

        case 2:
        {
            string cpf;
            cout << "Informe o CPF do cliente a ser excluído: ";
            cin >> cpf;

            for (auto it = clientes.begin(); it != clientes.end(); ++it)
            {
                if (it->CPF == cpf)
                {
                    clientes.erase(it);
                    cout << "Cliente excluído com sucesso!" << endl;
                    break;
                }
            }
        }
        break;

        case 3:
        {
            string cpf;
            cout << "Informe o CPF do cliente a ser alterado: ";
            cin >> cpf;

            for (auto &cliente : clientes)
            {
                if (cliente.CPF == cpf)
                {
                    cout << "Dados atuais do cliente:" << endl;
                    cout << "CPF: " << cliente.CPF << endl;
                    cout << "Nome: " << cliente.Nome << endl;
                    cout << "Endereço: " << cliente.Endereco << endl;

                    int opcao;
                    cout << "Deseja alterar o Nome? (1 para Sim, 0 para Não): ";
                    cin >> opcao;
                    if (opcao == 1)
                    {
                        cout << "Novo Nome: ";
                        cin.ignore();
                        getline(cin, cliente.Nome);
                    }

                    cout << "Deseja alterar o Endereço? (1 para Sim, 0 para Não): ";
                    cin >> opcao;
                    if (opcao == 1)
                    {
                        cout << "Novo Endereço: ";
                        cin.ignore();
                        getline(cin, cliente.Endereco);
                    }

                    cout << "Cliente alterado com sucesso!" << endl;
                    break;
                }
            }
        }
        break;

        case 4:
            if (clientes.empty())
            {
                cout << "Nenhum cliente cadastrado." << endl;
            }
            else
            {
                cout << "Lista de Clientes:" << endl;
                for (const auto &cliente : clientes)
                {
                    cout << "CPF: " << cliente.CPF << endl;
                    cout << "Nome: " << cliente.Nome << endl;
                    cout << "Endereço: " << cliente.Endereco << endl;
                    cout << "-----------------------" << endl;
                }
            }
            break;

        case 5:
        {
            string cpf;
            cout << "Informe o CPF do cliente a ser localizado: ";
            cin >> cpf;

            for (const auto &cliente : clientes)
            {
                if (cliente.CPF == cpf)
                {
                    cout << "CPF: " << cliente.CPF << endl;
                    cout << "Nome: " << cliente.Nome << endl;
                    cout << "Endereço: " << cliente.Endereco << endl;
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