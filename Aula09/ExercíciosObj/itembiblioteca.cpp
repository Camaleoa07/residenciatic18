#include <iostream>
#include <string>

using namespace std;

class ItemBiblioteca
{
protected:
    string titulo;
    string autor;
    int copiasDisponiveis;

public:
    ItemBiblioteca(const string &t, const string &a, int copias) : titulo(t), autor(a), copiasDisponiveis(copias) {}

    void exibirInfo() const
    {
        cout << "Título: " << titulo << endl;
        cout << "Autor: " << autor << endl;
        cout << "Cópias Disponíveis: " << copiasDisponiveis << endl;
    }
};

class Livro : public ItemBiblioteca
{
private:
    int numeroPaginas;

public:
    Livro(const string &t, const string &a, int copias, int paginas) : ItemBiblioteca(t, a, copias), numeroPaginas(paginas) {}

    void exibirInfo() const
    {
        ItemBiblioteca::exibirInfo();
        cout << "Número de Páginas: " << numeroPaginas << endl;
    }
};

class DVD : public ItemBiblioteca
{
private:
    int duracaoMinutos;

public:
    DVD(const string &t, const string &a, int copias, int duracao) : ItemBiblioteca(t, a, copias), duracaoMinutos(duracao) {}

    void exibirInfo() const
    {
        ItemBiblioteca::exibirInfo();
        cout << "Duração (minutos): " << duracaoMinutos << endl;
    }
};

int main()
{
    Livro livro("Pedra Filosofal", "J.K.Rowling", 50, 208);
    DVD dvd("Filme Harry Potter", "J.K.Rowling", 600, 120);

    cout << "Informações do Livro:" << endl;
    livro.exibirInfo();

    cout << "\nInformações do DVD:" << endl;
    dvd.exibirInfo();

    return 0;
}