#include <iostream>
#include <vector>

class OperacoesBancarias
{
public:
    virtual void deposito(double valor) = 0;
    virtual void retirada(double valor) = 0;
    virtual void extrato() const = 0;
    virtual int getNumero() const = 0; // Adicionando o método getNumero
};

class Conta : public OperacoesBancarias
{
public:
    Conta(int numero, double saldoInicial = 0.0) : numero(numero), saldo(saldoInicial) {}

    void deposito(double valor) override
    {
        saldo += valor;
        std::cout << "Depósito de $" << valor << " realizado. Saldo atual: $" << saldo << std::endl;
    }

    void retirada(double valor) override
    {
        if (valor <= saldo)
        {
            saldo -= valor;
            std::cout << "Retirada de $" << valor << " realizada. Saldo atual: $" << saldo << std::endl;
        }
        else
        {
            std::cout << "Saldo insuficiente para retirada de $" << valor << ". Saldo atual: $" << saldo << std::endl;
        }
    }

    void extrato() const override
    {
        std::cout << "Extrato da Conta #" << numero << ": Saldo atual: $" << saldo << std::endl;
    }

    int getNumero() const override
    {
        return numero;
    }

private:
    int numero;
    double saldo;
};

class ContaPoupanca : public OperacoesBancarias
{
public:
    ContaPoupanca(int numero, double saldoInicial = 0.0, double taxaJuros = 0.02)
        : numero(numero), saldo(saldoInicial), taxaJuros(taxaJuros) {}

    void deposito(double valor) override
    {
        saldo += valor;
        std::cout << "Depósito de $" << valor << " realizado. Saldo atual: $" << saldo << std::endl;
    }

    void retirada(double valor) override
    {
        if (valor <= saldo)
        {
            saldo -= valor;
            std::cout << "Retirada de $" << valor << " realizada. Saldo atual: $" << saldo << std::endl;
        }
        else
        {
            std::cout << "Saldo insuficiente para retirada de $" << valor << ". Saldo atual: $" << saldo << std::endl;
        }
    }

    void extrato() const override
    {
        std::cout << "Extrato da Conta Poupança #" << numero << ": Saldo atual: $" << saldo << std::endl;
    }

    void calcularJuros()
    {
        saldo += saldo * taxaJuros;
        std::cout << "Juros aplicados. Saldo atual: $" << saldo << std::endl;
    }

    int getNumero() const override
    {
        return numero;
    }

private:
    int numero;
    double saldo;
    double taxaJuros;
};

int main()
{
    std::vector<OperacoesBancarias *> contas;

    Conta conta1(101, 1000.0);
    ContaPoupanca poupanca1(201, 500.0);

    contas.push_back(&conta1);
    contas.push_back(&poupanca1);

    int escolha, numeroConta;
    double valor;

    while (true)
    {
        std::cout << "Escolha a operação: " << std::endl;
        std::cout << "1. Depósito" << std::endl;
        std::cout << "2. Retirada" << std::endl;
        std::cout << "3. Extrato" << std::endl;
        std::cout << "4. Sair" << std::endl;
        std::cin >> escolha;

        if (escolha == 4)
        {
            break;
        }

        std::cout << "Digite o número da conta: ";
        std::cin >> numeroConta;

        for (OperacoesBancarias *conta : contas)
        {
            if (conta->getNumero() == numeroConta)
            {
                if (escolha == 1)
                {
                    std::cout << "Digite o valor do depósito: ";
                    std::cin >> valor;
                    conta->deposito(valor);
                }
                else if (escolha == 2)
                {
                    std::cout << "Digite o valor da retirada: ";
                    std::cin >> valor;
                    conta->retirada(valor);
                }
                else if (escolha == 3)
                {
                    conta->extrato();
                }
            }
        }
    }

    return 0;
}
