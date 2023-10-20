#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

int main()
{
    std::string nomeArquivo;
    std::cout << "Informe o nome do arquivo com as notas e pesos: ";
    std::cin >> nomeArquivo;

    std::ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open())
    {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        return 1;
    }

    std::vector<double> notas;
    std::vector<double> pesos;
    std::string linha;

    while (std::getline(arquivo, linha))
    {
        std::istringstream stream(linha);
        std::string notaStr, pesoStr;

        if (std::getline(stream, notaStr, ';') && std::getline(stream, pesoStr, ';'))
        {
            double nota = std::stod(notaStr);
            double peso = std::stod(pesoStr);
            notas.push_back(nota);
            pesos.push_back(peso);
        }
    }

    arquivo.close();

    if (notas.empty() || notas.size() != pesos.size())
    {
        std::cerr << "Arquivo de entrada inválido." << std::endl;
        return 1;
    }

    double somaProdutos = 0.0;
    double somaPesos = 0.0;

    for (size_t i = 0; i < notas.size(); i++)
    {
        somaProdutos += notas[i] * pesos[i];
        somaPesos += pesos[i];
    }

    if (somaPesos == 0)
    {
        std::cerr << "Não é possível calcular a média ponderada com soma de pesos igual a zero." << std::endl;
        return 1;
    }

    double mediaPonderada = somaProdutos / somaPesos;

    std::cout << "A média ponderada das notas é: " << mediaPonderada << std::endl;

    return 0;
}
