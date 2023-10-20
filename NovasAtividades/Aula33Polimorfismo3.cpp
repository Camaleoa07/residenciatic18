#include <iostream>
#include <vector>

template <typename T>
class ListaGenerica
{
private:
    std::vector<T> elementos;

public:
    void adicionar(const T &elemento)
    {
        elementos.push_back(elemento);
    }

    void remover(const T &elemento)
    {
        for (auto it = elementos.begin(); it != elementos.end(); ++it)
        {
            if (*it == elemento)
            {
                elementos.erase(it);
                break;
            }
        }
    }

    void listar()
    {
        for (const T &elemento : elementos)
        {
            std::cout << elemento << " ";
        }
        std::cout << std::endl;
    }
};

int main()
{
    ListaGenerica<int> listaInteiros;
    listaInteiros.adicionar(10);
    listaInteiros.adicionar(20);
    listaInteiros.adicionar(30);

    ListaGenerica<std::string> listaStrings;
    listaStrings.adicionar("Hello");
    listaStrings.adicionar("World");

    ListaGenerica<double> listaDoubles;
    listaDoubles.adicionar(3.14);
    listaDoubles.adicionar(2.71);

    listaInteiros.listar();
    listaStrings.listar();
    listaDoubles.listar();

    return 0;
}
