#include <iostream>
#include <fstream>

int main(int argc, char** argv)
{
#ifdef _MSC_VER
    std::locale::global(std::locale(".utf8"));
#endif

    if (argc < 3)
    {
        std::cerr << "mkp [arquivo] [tamanho-população] [numero-gerações]" << '\n';
        return EXIT_FAILURE;
    }

    std::ifstream file{argv[1]};
    if (!file.is_open())
    {
        std::cerr << argv[1] << " não pode ser aberto";
        return EXIT_FAILURE;
    }

    int qtdItens{};
    int qtdDimensoes{};
    int melhorSolucaoJaEncontrada{};

    file >> qtdItens >> qtdDimensoes >> melhorSolucaoJaEncontrada;

    int* montante = new int[qtdItens];
    int* medidas = new int[qtdItens * qtdDimensoes];

    for (int i = 0; i < qtdItens; i++)
    {
        file >> montante[i];
    }

    for (int i = 0; i < qtdItens * qtdDimensoes; i++)
    {

    }

    delete[] montante;
    delete[] medidas;

    return 0;
}