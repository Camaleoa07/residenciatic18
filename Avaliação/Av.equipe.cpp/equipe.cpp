#include <iostream>
#include <vector>

struct Cliente
{
    std::string CPF;
    std::string Nome;
    std::string Dt_nascimento;
    std::string CNH;
};

struct Veiculo
{
    std::string Renavan;
    std::string Placa;
    std::string Data_Hora_Retirada_Prevista;
    std::string Data_Hora_Entrega_Prevista;
    std::string Loja_Retirada;
};

struct Locacao
{
    Cliente cliente;
    Veiculo veiculo;
    bool Realizada;
    std::string Data_Hora_Retirada;
    std::string Data_Hora_Entrega;
};

void IncluirLocacao(std::vector<Locacao> &locacoes)
{
    Locacao novaLocacao;

    std::cout << "Informe o CPF do Cliente: ";
    std::cin >> novaLocacao.cliente.CPF;
    std::cout << "Informe o Nome do Cliente: ";
    std::cin.ignore();
    std::getline(std::cin, novaLocacao.cliente.Nome);
    std::cout << "Informe a Data de Nascimento do Cliente (DD/MM/AAAA): ";
    std::cin >> novaLocacao.cliente.Dt_nascimento;
    std::cout << "Informe a CNH do Cliente: ";
    std::cin >> novaLocacao.cliente.CNH;

    std::cout << "Informe o Renavan do Veículo: ";
    std::cin >> novaLocacao.veiculo.Renavan;
    std::cout << "Informe a Placa do Veículo: ";
    std::cin >> novaLocacao.veiculo.Placa;
    std::cout << "Informe a Data e Hora de Retirada Prevista (DD/MM/AAAA HH:MM): ";
    std::cin.ignore();
    std::getline(std::cin, novaLocacao.veiculo.Data_Hora_Retirada_Prevista);
    std::cout << "Informe a Data e Hora de Entrega Prevista (DD/MM/AAAA HH:MM): ";
    std::getline(std::cin, novaLocacao.veiculo.Data_Hora_Entrega_Prevista);
    std::cout << "Informe a Loja de Retirada: ";
    std::getline(std::cin, novaLocacao.veiculo.Loja_Retirada);

    std::cout << "Informe a Data e Hora de Retirada (DD/MM/AAAA HH:MM): ";
    std::getline(std::cin, novaLocacao.Data_Hora_Retirada);
    std::cout << "A Retirada já aconteceu? (S/N): ";
    char retiradaAconteceu;
    std::cin >> retiradaAconteceu;
    novaLocacao.Realizada = (retiradaAconteceu == 'S' || retiradaAconteceu == 's');

    locacoes.push_back(novaLocacao);

    std::cout << "Locação registrada com sucesso!" << std::endl;
}

void ExcluirLocacao(std::vector<Locacao> &locacoes)
{
    std::string cpfCliente;
    std::cout << "Informe o CPF do Cliente da locação a ser excluída: ";
    std::cin >> cpfCliente;
    std::vector<Locacao>::iterator it = locacoes.begin();
    bool encontrada = false;

    while (it != locacoes.end())
    {
        if (it->cliente.CPF == cpfCliente)
        {
            it = locacoes.erase(it);
            encontrada = true;
        }
        else
        {
            ++it;
        }
    }

    if (encontrada)
    {
        std::cout << "Locação(s) excluída(s) com sucesso!" << std::endl;
    }
    else
    {
        std::cout << "Nenhuma locação encontrada com o CPF informado." << std::endl;
    }
}

void AlterarLocacao(std::vector<Locacao> &locacoes)
{
    std::string cpfCliente;
    std::cout << "Informe o CPF do Cliente da locação a ser alterada: ";
    std::cin >> cpfCliente;

    for (Locacao &locacao : locacoes)
    {
        if (locacao.cliente.CPF == cpfCliente)
        {
            std::cout << "Informe a nova Data e Hora de Retirada (DD/MM/AAAA HH:MM): ";
            std::cin.ignore();
            std::getline(std::cin, locacao.Data_Hora_Retirada);
            std::cout << "A Retirada já aconteceu? (S/N): ";
            char retiradaAconteceu;
            std::cin >> retiradaAconteceu;
            locacao.Realizada = (retiradaAconteceu == 'S' || retiradaAconteceu == 's');

            std::cout << "Locação alterada com sucesso!" << std::endl;
            return;
        }
    }

    std::cout << "Nenhuma locação encontrada com o CPF informado." << std::endl;
}

void ListarLocacoes(const std::vector<Locacao> &locacoes)
{
    if (locacoes.empty())
    {
        std::cout << "Nenhuma locação cadastrada." << std::endl;
        return;
    }

    std::cout << "Lista de Locações:" << std::endl;
    for (const Locacao &locacao : locacoes)
    {
        std::cout << "Cliente: " << locacao.cliente.Nome << " (CPF: " << locacao.cliente.CPF << ")" << std::endl;
        std::cout << "Veículo: " << locacao.veiculo.Placa << std::endl;
        std::cout << "Data e Hora de Retirada: " << locacao.Data_Hora_Retirada << std::endl;
        std::cout << "Locação Realizada: " << (locacao.Realizada ? "Sim" : "Não") << std::endl;
        std::cout << "-----------------------------" << std::endl;
    }
}

int main()
{
    std::vector<Locacao> locacoes;

    int escolha;
    do
    {
        std::cout << "Menu de Gestão de Locações:" << std::endl;
        std::cout << "1. Incluir Locação" << std::endl;
        std::cout << "2. Excluir uma Locação" << std::endl;
        std::cout << "3. Alterar Locação" << std::endl;
        std::cout << "4. Listar todas as Locações" << std::endl;
        std::cout << "0. Sair" << std::endl;
        std::cout << "Escolha uma opção: ";
        std::cin >> escolha;

        switch (escolha)
        {
        case 1:
            IncluirLocacao(locacoes);
            break;
        case 2:
            ExcluirLocacao(locacoes);
            break;
        case 3:
            AlterarLocacao(locacoes);
            break;
        case 4:
            ListarLocacoes(locacoes);
            break;
        case 0:
            std::cout << "Saindo do programa." << std::endl;
            break;
        default:
            std::cout << "Opção inválida. Tente novamente." << std::endl;
        }
    } while (escolha != 0);

    return 0;
}
