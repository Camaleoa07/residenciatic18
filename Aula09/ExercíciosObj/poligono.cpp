#include <iostream>
#include <vector>

using namespace std;

class Ponto
{
public:
    int x, y;

    Ponto(int xCoord, int yCoord) : x(xCoord), y(yCoord) {}

    bool operator==(const Ponto &outro) const
    {
        return (x == outro.x && y == outro.y);
    }
};

class Poligono
{
private:
    vector<Ponto> pontos;

public:
    Poligono(const vector<Ponto> &pts) : pontos(pts) {}

    Poligono &operator=(const Poligono &outro)
    {
        if (this == &outro)
        {
            return *this;
        }

        pontos.clear();

        for (const Ponto &ponto : outro.pontos)
        {
            pontos.push_back(ponto);
        }

        return *this;
    }

    bool operator==(const Poligono &outro) const
    {
        if (pontos.size() != outro.pontos.size())
        {
            return false;
        }

        for (size_t i = 0; i < pontos.size(); ++i)
        {
            if (!(pontos[i] == outro.pontos[i]))
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{

    Ponto ponto1(1, 2);
    Ponto ponto2(3, 4);
    Ponto ponto3(1, 2);

    vector<Ponto> pontosPoligono1 = {ponto1, ponto2};
    vector<Ponto> pontosPoligono2 = {ponto1, ponto2};
    vector<Ponto> pontosPoligono3 = {ponto2, ponto3};

    Poligono poligono1(pontosPoligono1);
    Poligono poligono2(pontosPoligono2);
    Poligono poligono3(pontosPoligono3);

    if (poligono1 == poligono2)
    {
        cout << "poligono1 e poligono2 são iguais." << endl;
    }
    else
    {
        cout << "poligono1 e poligono2 não são iguais." << endl;
    }

    if (poligono1 == poligono3)
    {
        cout << "poligono1 e poligono3 são iguais." << endl;
    }
    else
    {
        cout << "poligono1 e poligono3 não são iguais." << endl;
    }

    poligono1 = poligono2;

    return 0;
}