#include <iostream>
#include <string>
#include <vector>

class Aluno
{
public:
    Aluno(const std::string &nome, int id)
        : nome(nome), id(id) {}

    void exibirDetalhes() const
    {
        std::cout << "Nome: " << nome << ", ID: " << id << std::endl;
    }

private:
    std::string nome;
    int id;
};

class Turma
{
public:
    void adicionarAluno(const Aluno &aluno)
    {
        alunos.push_back(aluno);
    }

    void listarAlunos() const
    {
        std::cout << "Lista de Alunos na Turma:" << std::endl;
        for (const Aluno &aluno : alunos)
        {
            aluno.exibirDetalhes();
        }
    }

private:
    std::vector<Aluno> alunos;
};

int main()
{
    int escolha;
    std::vector<Turma> turmas;

    while (true)
    {
        std::cout << "\n------------ Menu: ------------\n";
        std::cout << "1. Criar Turma\n";
        std::cout << "2. Adicionar Aluno a Turma\n";
        std::cout << "3. Listar Alunos de Turma\n";
        std::cout << "4. Sair\n";
        std::cout << "--------------------------------\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> escolha;

        switch (escolha)
        {
        case 1:
        {
            Turma turma;
            turmas.push_back(turma);
            std::cout << "Turma criada com sucesso!" << std::endl;
            break;
        }
        case 2:
        {
            if (turmas.empty())
            {
                std::cout << "Crie uma turma antes de adicionar alunos." << std::endl;
            }
            else
            {
                int turmaIndex;
                std::cout << "Escolha a turma (digite o número da turma):" << std::endl;
                for (size_t i = 0; i < turmas.size(); ++i)
                {
                    std::cout << i + 1 << ". Turma " << i + 1 << std::endl;
                }
                std::cin >> turmaIndex;

                if (turmaIndex >= 1 && turmaIndex <= static_cast<int>(turmas.size()))
                {
                    std::string nome;
                    int id;
                    std::cout << "Digite o nome do aluno: ";
                    std::cin >> nome;
                    std::cout << "Digite o ID do aluno: ";
                    std::cin >> id;
                    Aluno aluno(nome, id);
                    turmas[turmaIndex - 1].adicionarAluno(aluno);
                    std::cout << "Aluno adicionado à Turma " << turmaIndex << "." << std::endl;
                }
                else
                {
                    std::cout << "Escolha de turma inválida." << std::endl;
                }
            }
            break;
        }
        case 3:
        {
            if (turmas.empty())
            {
                std::cout << "Crie uma turma e adicione alunos antes de listar." << std::endl;
            }
            else
            {
                int turmaIndex;
                std::cout << "Escolha a turma (digite o número da turma):" << std::endl;
                for (size_t i = 0; i < turmas.size(); ++i)
                {
                    std::cout << i + 1 << ". Turma " << i + 1 << std::endl;
                }
                std::cin >> turmaIndex;

                if (turmaIndex >= 1 && turmaIndex <= static_cast<int>(turmas.size()))
                {
                    turmas[turmaIndex - 1].listarAlunos();
                }
                else
                {
                    std::cout << "Escolha de turma inválida." << std::endl;
                }
            }
            break;
        }
        case 4:
            std::cout << "\n----------- FIM DO PROGRAMA -------------\n"
                      << std::endl;
            return 0;
        default:
            std::cout << "Opção inválida. Tente novamente." << std::endl;
        }
    }

    return 0;
}
