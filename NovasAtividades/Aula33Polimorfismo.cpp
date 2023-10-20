#include <iostream>

class FormaGeometrica
{
public:
    virtual ~FormaGeometrica() {}

    virtual double area() const = 0;
};

class Circulo : public FormaGeometrica
{
private:
    double raio;

public:
    Circulo(double r) : raio(r) {}

    double area() const override
    {
        return 3.14159265 * raio * raio;
    }
};

class Retangulo : public FormaGeometrica
{
private:
    double largura;
    double altura;

public:
    Retangulo(double w, double h) : largura(w), altura(h) {}

    double area() const override
    {
        return largura * altura;
    }
};

int main()
{
    FormaGeometrica *formas[2];

    formas[0] = new Circulo(5.0);
    formas[1] = new Retangulo(4.0, 6.0);

    for (int i = 0; i < 2; i++)
    {
        std::cout << "Área da forma " << i + 1 << ": " << formas[i]->area() << std::endl;
        delete formas[i];
    }

    return 0;
}
