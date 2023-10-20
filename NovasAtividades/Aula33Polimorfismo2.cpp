#include <iostream>

class Desenhavel
{
public:
    virtual void desenhar() const = 0;
    virtual ~Desenhavel() {}
};

class Circulo : public Desenhavel
{
public:
    void desenhar() const override
    {
        std::cout << "Desenhando um círculo." << std::endl;
    }
};

class Retangulo : public Desenhavel
{
public:
    void desenhar() const override
    {
        std::cout << "Desenhando um retângulo." << std::endl;
    }
};

class Triangulo : public Desenhavel
{
public:
    void desenhar() const override
    {
        std::cout << "Desenhando um triângulo." << std::endl;
    }
};

int main()
{
    Circulo circulo;
    Retangulo retangulo;
    Triangulo triangulo;

    const Desenhavel *objetos[] = {&circulo, &retangulo, &triangulo};

    for (const Desenhavel *objeto : objetos)
    {
        objeto->desenhar();
    }

    return 0;
}
