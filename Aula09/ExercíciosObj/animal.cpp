#include <iostream>
#include <string>

using namespace std;

class Animal
{
protected:
    string nome;
    int idade;

public:
    Animal(const string &n, int id) : nome(n), idade(id) {}

    string getNome() const
    {
        return nome;
    }

    int getIdade() const
    {
        return idade;
    }

    void fazerSom()
    {
        cout << "Animal fazendo som de latido." << endl;
    }
};

class Cachorro : public Animal
{
public:
    Cachorro(const string &n, int id) : Animal(n, id) {}

    void fazerSom()
    {
        cout << "Au Au!" << endl;
    }
};

int main()
{
    Animal animal("Cachorro", 5);
    Cachorro cachorro("Chowchow", 3);

    cout << "Animal: " << animal.getNome() << ", Idade: " << animal.getIdade() << endl;
    animal.fazerSom();

    cout << "Cachorro: " << cachorro.getNome() << ", Idade: " << cachorro.getIdade() << endl;
    cachorro.fazerSom();

    return 0;
}