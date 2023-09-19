#include <iostream>
#include <vector>
#include <string>

struct Cliente
{
    std::string CPF;
    std::string Nome;
    std::string DtNascimento;
    std::string CNH;
};

struct Veiculo
{
    std::string Numero;
    std::string Placa;
    std::string Data_Hora_Retirada_Prevista;
    std::string Data_Hora_Entrega_Prevista;
    std::string Loja_Retirada;
    std::string Loja_Entrega;
};

struct Ocorrencia
{
    std::string Descricao;
    std::string Data_Hora;
    std::string Numero_Apolice;
};

struct Locacao
{
    Cliente cliente;
    Veiculo veiculo;
    bool Realizada;
    std::string Data_Hora_Retirada;
    std::string Data_Hora_Entrega;
    Ocorrencia ocorrencia;
};

void IncluirOcorrencia(std::vector<Locacao> &locacoes)
{
    std::string cpfCliente, placaVeiculo;
    std::cout << "Informe o CPF do Cliente: ";
    std::cin >> cpfCliente;
    std::cout << "Informe a Placa do Veículo: ";
    std::cin >> placaVeiculo;

    bool locacaoEncontrada = false;
    for (Locacao &locacao : locacoes)
    {
        if (locacao.cliente.CPF == cpfCliente && locacao.veiculo.Placa == placaVeiculo)
        {
            std::cout << "Informe a Descrição da Ocorrência: ";
            std::cin.ignore();
            std::getline(std::cin, locacao.ocorrencia.Descricao);
            std::cout << "Informe a Data e Hora da Ocorrência (DD/MM/AAAA HH:MM): ";
            std::getline(std::cin, locacao.ocorrencia.Data_Hora);
            std::cout << "Informe o Número da Apólice: ";
            std::cin >> locacao.ocorrencia.Numero_Apolice;

            std::cout << "Ocorrência registrada com sucesso!" << std::endl;
            locacaoEncontrada = true;
            break;
        }
    }

    if (!locacaoEncontrada)
    {
        std::cout << "Locação não encontrada com o CPF e Placa informados." << std::endl;
    }
}

void ExcluirOcorrencia(std::vector<Locacao> &locacoes)
{
    std::string cpfCliente, placaVeiculo;
    std::cout << "Informe o CPF do Cliente: ";
    std::cin >> cpfCliente;
    std::cout << "Informe a Placa do Veículo: ";
    std::cin >> placaVeiculo;

    bool locacaoEncontrada = false;
    for (Locacao &locacao : locacoes)
    {
        if (locacao.cliente.CPF == cpfCliente && locacao.veiculo.Placa == placaVeiculo)
        {
            locacao.ocorrencia.Descricao = "";
            locacao.ocorrencia.Data_Hora = "";
            locacao.ocorrencia.Numero_Apolice = "";

            std::cout << "Ocorrência excluída com sucesso!" << std::endl;
            locacaoEncontrada = true;
            break;
        }
    }

    if (!locacaoEncontrada)
    {
        std::cout << "Locação não encontrada com o CPF e Placa informados." << std::endl;
    }
}

void AlterarOcorrencia(std::vector<Locacao> &locacoes)
{
    std::string cpfCliente, placaVeiculo;
    std::cout << "Informe o CPF do Cliente: ";
    std::cin >> cpfCliente;
    std::cout << "Informe a Placa do Veículo: ";
    std::cin >> placaVeiculo;

    bool locacaoEncontrada = false;
    for (Locacao &locacao : locacoes)
    {
        if (locacao.cliente.CPF == cpfCliente && locacao.veiculo.Placa == placaVeiculo)
        {

            std::cout << "Descrição atual da Ocorrência: " << locacao.ocorrencia.Descricao << std::endl;
            std::cout << "Deseja alterar a Descrição? (S/N): ";
            char alterarDescricao;
            std::cin >> alterarDescricao;
            if (alterarDescricao == 'S' || alterarDescricao == 's')
            {
                std::cout << "Informe a nova Descrição da Ocorrência: ";
                std::cin.ignore();
                std::getline(std::cin, locacao.ocorrencia.Descricao);
            }

            std::cout << "Data/Hora atual da Ocorrência: " << locacao.ocorrencia.Data_Hora << std::endl;
            std::cout << "Deseja alterar a Data/Hora? (S/N): ";
            char alterarDataHora;
            std::cin >> alterarDataHora;
            if (alterarDataHora == 'S' || alterarDataHora == 's')
            {
                std::cout << "Informe a nova Data e Hora da Ocorrência (DD/MM/AAAA HH:MM): ";
                std::cin.ignore();
                std::getline(std::cin, locacao.ocorrencia.Data_Hora);
            }

            std::cout << "Número da Apólice atual: " << locacao.ocorrencia.Numero_Apolice << std::endl;
            std::cout << "Deseja alterar o Número da Apólice? (S/N): ";
            char alterarApolice;
            std::cin >> alterarApolice;
            if (alterarApolice == 'S' || alterarApolice == 's')
            {
                std::cout << "Informe o novo Número da Apólice: ";
                std::cin >> locacao.ocorrencia.Numero_Apolice;
            }

            std::cout << "Ocorrência alterada com sucesso!" << std::endl;
            locacaoEncontrada = true;
            break;
        }
    }

    if (!locacaoEncontrada)
        if (!locacaoEncontrada)
        {
            std::cout << "Locação não encontrada com o CPF e Placa informados." << std::endl;
        }
}

void ListarOcorrenciasPorCliente(const std::vector<Locacao> &locacoes)
{
    std::string cpfCliente;
    std::cout << "Informe o CPF do Cliente: ";
    std::cin >> cpfCliente;

    bool ocorrenciasEncontradas = false;

    for (const Locacao &locacao : locacoes)
    {
        if (locacao.cliente.CPF == cpfCliente && !locacao.ocorrencia.Descricao.empty())
        {
            std::cout << "Descrição da Ocorrência: " << locacao.ocorrencia.Descricao << std::endl;
            std::cout << "Data/Hora da Ocorrência: " << locacao.ocorrencia.Data_Hora << std::endl;
            std::cout << "Número da Apólice: " << locacao.ocorrencia.Numero_Apolice << std::endl;
            std::cout << "-----------------------------" << std::endl;
            ocorrenciasEncontradas = true;
        }
    }

    if (!ocorrenciasEncontradas)
    {
        std::cout << "Nenhuma ocorrência encontrada para o CPF informado." << std::endl;
    }
}

void ListarOcorrenciasPorVeiculo(const std::vector<Locacao> &locacoes)
{
    std::string placaVeiculo;
    std::cout << "Informe a Placa do Veículo: ";
    std::cin >> placaVeiculo;

    bool ocorrenciasEncontradas = false;

    for (const Locacao &locacao : locacoes)
    {
        if (locacao.veiculo.Placa == placaVeiculo && !locacao.ocorrencia.Descricao.empty())
        {
            std::cout << "Descrição da Ocorrência: " << locacao.ocorrencia.Descricao << std::endl;
            std::cout << "Data/Hora da Ocorrência: " << locacao.ocorrencia.Data_Hora << std::endl;
            std::cout << "Número da Apólice: " << locacao.ocorrencia.Numero_Apolice << std::endl;
            std::cout << "-----------------------------" << std::endl;
            ocorrenciasEncontradas = true;
        }
    }

    if (!ocorrenciasEncontradas)
    {
        std::cout << "Nenhuma ocorrência encontrada para a Placa do Veículo informada." << std::endl;
    }
}

int main()
{
    std::vector<Locacao> locacoes;

    int escolha;
    do
    {
        std::cout << "Menu Principal:" << std::endl;
        std::cout << "1. Gestão de Clientes" << std::endl;
        std::cout << "2. Gestão de Veículos" << std::endl;
        std::cout << "3. Gestão de Locações" << std::endl;
        std::cout << "4. Gestão de Ocorrências" << std::endl;
        std::cout << "0. Sair do Programa" << std::endl;
        std::cout << "Escolha uma opção: ";
        std::cin >> escolha;

        switch (escolha)
        {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:
            int escolhaOcorrencia;
            do
            {
                std::cout << "Menu de Gestão de Ocorrências:" << std::endl;
                std::cout << "1. Incluir Ocorrência" << std::endl;
                std::cout << "2. Excluir Ocorrência" << std::endl;
                std::cout << "3. Alterar Ocorrência" << std::endl;
                std::cout << "4. Listar Ocorrências por Cliente" << std::endl;
                std::cout << "5. Listar Ocorrências por Veículo" << std::endl;
                std::cout << "0. Voltar ao Menu Principal" << std::endl;
                std::cout << "Escolha uma opção: ";
                std::cin >> escolhaOcorrencia;

                switch (escolhaOcorrencia)
                {
                case 1:
                    IncluirOcorrencia(locacoes);
                    break;
                case 2:
                    ExcluirOcorrencia(locacoes);
                    break;
                case 3:
                    AlterarOcorrencia(locacoes);
                    break;
                case 4:
                    ListarOcorrenciasPorCliente(locacoes);
                    break;
                case 5:
                    ListarOcorrenciasPorVeiculo(locacoes);
                    break;
                case 0:
                    std::cout << "Voltando ao Menu Principal." << std::endl;
                    break;
                default:
                    std::cout << "Opção inválida. Tente novamente." << std::endl;
                }
            } while (escolhaOcorrencia != 0);
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