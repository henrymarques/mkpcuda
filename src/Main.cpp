#include <iostream>
#include <fstream>

#include "Mochila.h"

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

    using namespace mochila;
    using namespace configuracoes;

    qtdIndividuos = atoi(argv[2]);
    qtdGeracoes = atoi(argv[3]);

    file >> qtdItens >> qtdDimensoes >> melhorSolucaoJaEncontrada;

    int* montante = new int[qtdItens];
    int** itens = new int* [qtdItens];

    for (int i = 0; i < qtdItens; i++)
    {
        itens[i] = new int[qtdDimensoes];
    }

    for (int i = 0; i < qtdItens; i++)
    {
        file >> montante[i];
    }

    for (int i = 0; i < qtdDimensoes; i++)
    {
        for (int j = 0; j < qtdItens; j++)
        {
            file >> itens[j][i];
            // itens[j + qtdItens * i] = itens2[j][i];
        }
    }

    capacidades = new int[qtdDimensoes];
    for (int i = 0; i < qtdDimensoes; i++)
    {
        file >> capacidades[i];
    }

    file.close();

    // fluxo vem aqui

    // iniciarPopulacao(qtdIndividuos);
    for (int geracao = 0; geracao < qtdGeracoes; geracao++) {
        // Individuo individuoNovo{};
        // encontrarMelhorIndividuo();
        // do {
        // auto [i1, i2] = selecionarPorTorneio();
        // individuoNovo = cruzar(i1, i2);
        // if (!ehViavel(individuoNovo)) {
        // dropAdd(&individuoNovo);
        // }
        // } while (ehDuplicado(individuoNovo));
        // substituirPiorDaGeracao(&individuoNovo); // referencia?
        // atualizarMelhorSolucao();
    }

    // liberação de memória

    delete[] capacidades;
    delete[] montante;

    for (int i = 0; i < qtdItens; i++)
    {
        delete[] itens[i];
    }
    delete[] itens;

    return 0;
}