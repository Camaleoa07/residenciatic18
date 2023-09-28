#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Aluno
{
private:
    string nome;
    string email;
    int nota1;
    int nota2;

public:
    Aluno(const string &n, const string &e, int n1, int n2)
        : nome(n), email(e), nota1(n1), nota2(n2) {}

    string getNome() const
    {
        return nome;
    }

    string getEmail() const
    {
        return email;
    }

    int getNota1() const
    {
        return nota1;
    }

    int getNota2() const
    {
        return nota2;
    }

    void setNome(const string &novoNome)
    {
        nome = novoNome;
    }

    void setEmail(const string &novoEmail)
    {
        email = novoEmail;
    }

    void setNota1(int novaNota1)
    {
        nota1 = novaNota1;
    }

    void setNota2(int novaNota2)
    {
        nota2 = novaNota2;
    }
};

class BancoDeDados
{
private:
    vector<Aluno> alunos;
    string nomeArquivo;

public:
    BancoDeDados(const string &arquivo) : nomeArquivo(arquivo) {}

    void inserirAluno(const Aluno &aluno)
    {
        alunos.push_back(aluno);
    }

    void alterarAluno(const string &nome, const string &novoEmail, int novaNota1, int novaNota2)
    {
        for (Aluno &aluno : alunos)
        {
            if (aluno.getNome() == nome)
            {
                aluno.setEmail(novoEmail);
                aluno.setNota1(novaNota1);
                aluno.setNota2(novaNota2);
                return;
            }
        }
        cout << "Aluno não encontrado." << endl;
    }

    void excluirAluno(const string &nome)
    {
        alunos.erase(remove_if(alunos.begin(), alunos.end(),
                               [nome](const Aluno &aluno)
                               { return aluno.getNome() == nome; }),
                     alunos.end());
    }

    void salvarDados()
    {
        ofstream arquivo_saida(nomeArquivo);
        if (arquivo_saida.is_open())
        {
            for (const Aluno &aluno : alunos)
            {
                arquivo_saida << aluno.getNome() << "," << aluno.getEmail() << ","
                              << aluno.getNota1() << "," << aluno.getNota2() << endl;
            }
            arquivo_saida.close();
            cout << "Dados salvos com sucesso." << endl;
        }
        else
        {
            cout << "Erro ao abrir o arquivo para salvar dados." << endl;
        }
    }

    void carregarDados()
    {
        ifstream arquivo_entrada(nomeArquivo);
        alunos.clear();

        if (arquivo_entrada.is_open())
        {
            string linha;
            while (getline(arquivo_entrada, linha))
            {
                size_t pos1 = linha.find(",");
                size_t pos2 = linha.find(",", pos1 + 1);
                size_t pos3 = linha.find(",", pos2 + 1);

                string nome = linha.substr(0, pos1);
                string email = linha.substr(pos1 + 1, pos2 - pos1 - 1);
                int nota1 = stoi(linha.substr(pos2 + 1, pos3 - pos2 - 1));
                int nota2 = stoi(linha.substr(pos3 + 1));

                Aluno aluno(nome, email, nota1, nota2);
                alunos.push_back(aluno);
            }
            arquivo_entrada.close();
            cout << "Dados carregados com sucesso." << endl;
        }
        else
        {
            cout << "Erro ao abrir o arquivo para carregar dados." << endl;
        }
    }

    void listarAlunos() const
    {
        cout << "Lista de Alunos:" << endl;
        for (const Aluno &aluno : alunos)
        {
            cout << "Nome: " << aluno.getNome() << ", Email: " << aluno.getEmail()
                 << ", Nota1: " << aluno.getNota1() << ", Nota2: " << aluno.getNota2() << endl;
        }
    }
};

int main()
{
    BancoDeDados banco("turma.txt");
    banco.carregarDados();

    while (true)
    {
        cout << "Menu:" << endl;
        cout << "1 - Inserir Aluno" << endl;
        cout << "2 - Alterar Aluno" << endl;
        cout << "3 - Excluir Aluno" << endl;
        cout << "4 - Listar Alunos" << endl;
        cout << "0 - Sair" << endl;
        cout << "Digite a opção: ";

        int opcao;
        cin >> opcao;

        if (opcao == 0)
        {
            banco.salvarDados();
            break;
        }

        switch (opcao)
        {
        case 1:
        {
            string nome, email;
            int nota1, nota2;
            cout << "Digite o nome do aluno: ";
            cin.ignore();
            getline(cin, nome);
            cout << "Digite o email do aluno: ";
            getline(cin, email);
            cout << "Digite a nota 1 do aluno: ";
            cin >> nota1;
            cout << "Digite a nota 2 do aluno: ";
            cin >> nota2;

            Aluno novoAluno(nome, email, nota1, nota2);
            banco.inserirAluno(novoAluno);
            cout << "Aluno inserido com sucesso!" << endl;
            break;
        }

        case 2:
        {
            string nome, novoEmail;
            int novaNota1, novaNota2;
            cout << "Digite o nome do aluno que deseja alterar: ";
            cin.ignore();
            getline(cin, nome);
            cout << "Digite o novo email: ";
            getline(cin, novoEmail);
            cout << "Digite a nova nota 1: ";
            cin >> novaNota1;
            cout << "Digite a nova nota 2: ";
            cin >> novaNota2;

            banco.alterarAluno(nome, novoEmail, novaNota1, novaNota2);
            break;
        }

        case 3:
        {
            string nomeExcluir;
            cout << "Digite o nome do aluno que deseja excluir: ";
            cin.ignore();
            getline(cin, nomeExcluir);
            banco.excluirAluno(nomeExcluir);
            break;
        }

        case 4:
            banco.listarAlunos();
            break;

        default:
            cout << "Opção inválida. Tente novamente." << endl;
            break;
        }
    }

    return 0;
}