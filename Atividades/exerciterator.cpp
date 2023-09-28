#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
    int i = 5, position = 0;
    vector<string> students;
    string word;

    while (i)
    {
        cout << "Digite o nome do aluno: ";
        getline(cin, word);
        students.push_back(word);
        i--;
    }

    cout << "Alunos" << endl
         << endl;

    for (auto it = students.begin(); it != students.end(); it++)
        cout << *it << endl;

    cout << "Digite a posição do aluno: ";
    cin >> position;
    cout << "Nome: " << students[position] << endl
         << endl;

    return 0;
}