#include <iostream>
#include <cmath>

using namespace std;

class Forma
{
public:
    virtual double calcularArea() const = 0;
};

class Retangulo : public Forma
{
private:
    double comprimento;
    double largura;

public:
    Retangulo(double c, double l) : comprimento(c), largura(l) {}

    double calcularArea() const override
    {
        return comprimento * largura;
    }
};

class Circulo : public Forma
{
private:
    double raio;

public:
    Circulo(double r) : raio(r) {}

    double calcularArea() const override
    {
        return M_PI * pow(raio, 2);
    }
};

int main()
{
    double comprimento, largura, raio;

    cout << "Digite o comprimento do retângulo: ";
    cin >> comprimento;
    cout << "Digite a largura do retângulo: ";
    cin >> largura;

    Retangulo retangulo(comprimento, largura);

    cout << "Digite o raio do círculo: ";
    cin >> raio;

    Circulo circulo(raio);

    cout << "Área do Retângulo: " << retangulo.calcularArea() << endl;
    cout << "Área do Círculo: " << circulo.calcularArea() << endl;

    return 0;
}