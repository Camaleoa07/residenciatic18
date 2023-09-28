#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Paciente
{
private:
    string nome;
    string dt_dead;

public:
    Paciente(const string &n, const string &dt) : nome(n), dt_dead(dt) {}

    string getNome() const
    {
        return nome;
    }

    void setNome(const string &novoNome)
    {
        nome = novoNome;
    }

    string getDtDead() const
    {
        return dt_dead;
    }

    void setDtDead(const string &novaDtDead)
    {
        dt_dead = novaDtDead;
    }
};

class Mausoleu
{
private:
    static int totalMausoleus;
    int id;
    string localizacao;
    vector<Paciente> pacientes;

public:
    Mausoleu(const string &loc) : id(++totalMausoleus), localizacao(loc) {}

    int getId() const
    {
        return id;
    }

    string getLocalizacao() const
    {
        return localizacao;
    }

    void setLocalizacao(const string &novaLocalizacao)
    {
        localizacao = novaLocalizacao;
    }

    void incluirPaciente(const Paciente &paciente)
    {
        pacientes.push_back(paciente);
    }

    void listarPacientes() const
    {
        cout << "Pacientes no Mausoléu " << id << ":" << endl;
        for (const Paciente &paciente : pacientes)
        {
            cout << "Nome: " << paciente.getNome() << ", Data de Falecimento: " << paciente.getDtDead() << endl;
        }
    }

    static int getTotalMausoleus()
    {
        return totalMausoleus;
    }
};

int Mausoleu::totalMausoleus = 0;

int main()
{
    vector<Mausoleu> mausoleus;

    while (true)
    {
        cout << "Menu:" << endl;
        cout << "1 - Incluir Paciente" << endl;
        cout << "2 - Listar Pacientes em um Mausoléu" << endl;
        cout << "3 - Recepcionar em um Mausoléu" << endl;
        cout << "0 - Sair" << endl;
        cout << "Digite a opção: ";

        int opcao;
        cin >> opcao;

        if (opcao == 0)
        {
            break;
        }
        
        switch (opcao)
        {
        case 1:
        {
            string nome, dt_dead;
            cout << "Digite o nome do paciente: ";
            cin.ignore();
            getline(cin, nome);
            cout << "Digite a data de falecimento: ";
            getline(cin, dt_dead);

            Paciente novoPaciente(nome, dt_dead);

            cout << "Em qual Mausoléu deseja incluir o paciente? (1-" << Mausoleu::getTotalMausoleus() << "): ";
            int mausoleuEscolhido;
            cin >> mausoleuEscolhido;

            if (mausoleuEscolhido >= 1 && mausoleuEscolhido <= Mausoleu::getTotalMausoleus())
            {
                mausoleus[mausoleuEscolhido - 1].incluirPaciente(novoPaciente);
                cout << "Paciente incluído com sucesso!" << endl;
            }
            else
            {
                cout << "Mausoléu escolhido não existe." << endl;
            }
            break;
        }

        case 2:
        {
            cout << "Listar pacientes em qual Mausoléu? (1-" << Mausoleu::getTotalMausoleus() << "): ";
            int mausoleuEscolhido;
            cin >> mausoleuEscolhido;

            if (mausoleuEscolhido >= 1 && mausoleuEscolhido <= Mausoleu::getTotalMausoleus())
            {
                mausoleus[mausoleuEscolhido - 1].listarPacientes();
            }
            else
            {
                cout << "Mausoléu escolhido não existe." << endl;
            }
            break;
        }

        case 3:
        {

            break;
        }

        default:
            cout << "Opção inválida. Tente novamente." << endl;
            break;
        }
    }

    return 0;
}