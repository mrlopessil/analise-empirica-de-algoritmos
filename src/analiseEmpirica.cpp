#include "analiseEmpirica.h"
using namespace std;
using namespace std::chrono;

void analiseEmpirica()
{
    ofstream file("dados.csv");     // Arquivo para guardar os resultados para transformar em gráficos
    file << "n,binaria_pior,sequencial_pior,binaria_media,sequencial_media,binaria_melhor,sequencial_melhor,insertion_pior,merge_pior,insertion_media,merge_media,insertion_melhor,merge_melhor\n";

    int tamanhos[] = {5000, 10000, 15000, 20000, 25000};

    for (int n : tamanhos)
    {
        // ANÁLISE BUSCA SEQUENCIAL E BINÁRIA
        const vector<int> busca = gerarVetorCrescente(n);
        const vector<int> buscaAleatorio = gerarVetorAleatorio(n);      // Para testes de caso médio da busca sequencial

        double piorBin = 0;
        double piorSeq = 0;

        double mediaBin = 0;
        double mediaSeq = 0;

        double melhorBin = 0;
        double melhorSeq = 0;

        for (size_t i = 0; i < 50; i++)
        {
            // PIOR CASO: BUSCA ALVO NÃO PRESENTE NO VETOR CRESCENTE -> ALVO = -1
            piorBin += analiseBinaria(busca, 0, n - 1, -1).count();
            piorSeq += analiseSequencial(busca, -1).count();

            // CASO MÉDIO: VETOR ALEATÓRIO PARA BUSCA SEQUENCIAL E ALVO ALEATÓRIO PARA AMBAS AS BUSCAS
            int alvoAleatorio = buscaAleatorio[rand() % n];
            mediaBin += analiseBinaria(busca, 0, n - 1, alvoAleatorio).count();
            mediaSeq += analiseSequencial(buscaAleatorio, alvoAleatorio).count();

            // MELHOR CASO: ALVO É O PRIMEIRO ELEMENTO VERIFICADO
            melhorBin += analiseBinaria(busca, 0, n - 1, busca[(n - 1) / 2]).count();
            melhorSeq += analiseSequencial(busca, busca[0]).count();
        }

        file << n << "," << piorBin / 50 << "," << piorSeq / 50 << "," << mediaBin / 50 << "," << mediaSeq / 50 << "," << melhorBin / 50 << "," << melhorSeq / 50 << ",";

        // ANÁLISE INSERT SORT E MERGE SORT
        double piorInsert = 0;
        double piorMerge = 0;

        double mediaInsert = 0;
        double mediaMerge = 0;

        double melhorInsert = 0;
        double melhorMerge = 0;

        for (size_t i = 0; i < 50; i++)
        {
            vector<int> insertionDecrescente = gerarVetorDecrescente(n);    // Para testes de pior caso do insert sort
            vector<int> mergeDecrescente = insertionDecrescente;

            vector<int> insertionAleatorio = gerarVetorAleatorio(n);        // Para testes de médio caso do insert sort
            vector<int> mergeAleatorio = insertionAleatorio;

            vector<int> insertionCrescente = gerarVetorCrescente(n);        // Para teste de melhor caso do insert sort
            vector<int> mergeCrescente = insertionCrescente;

            // PIOR CASO: INSERTION SORT TEM SEU PIOR CASO QUANDO O VETOR ESTÁ ORDENADO AO CONTRÁRIO
            piorInsert += analiseInsert(insertionDecrescente).count();
            piorMerge += analiseMerge(mergeDecrescente, 0, n - 1).count();

            // CASO MÉDIO: VETOR DESORDENADO ALEATORIAMENTE
            mediaInsert += analiseInsert(insertionAleatorio).count();
            mediaMerge += analiseMerge(mergeAleatorio, 0, n-1).count();


            // MELHOR CASO: INSERTION SORT TEM SEU MELHOR CASO QUANDO O VETOR JÁ ESTÁ ORDENADO
            melhorInsert += analiseInsert(insertionCrescente).count();
            melhorMerge += analiseMerge(mergeCrescente, 0, n - 1).count();
        }

        file << piorInsert / 50 << "," << piorMerge / 50 << "," << mediaInsert / 50 << "," << mediaMerge / 50 << "," << melhorInsert / 50 << "," << melhorMerge / 50 << "\n";
    }

    file.close();
}


// ABAIXO FUNÇÕES AUXILIARES RESPONSÁVEIS POR RETORNAR O TEMPO DE EXECUÇÃO DOS ALGORITMOS
duration<double> analiseBinaria(const vector<int> &v, int inicio, int fim, int alvo)
{
    auto start = high_resolution_clock::now();
    buscaBinaria(v, inicio, fim, alvo);
    auto end = high_resolution_clock::now();

    return duration<double>(end - start);
}

duration<double> analiseSequencial(const vector<int> &v, int alvo)
{
    auto start = high_resolution_clock::now();
    buscaSequencial(v, alvo);
    auto end = high_resolution_clock::now();

    return duration<double>(end - start);
}

duration<double> analiseInsert(vector<int> &v)
{
    auto start = high_resolution_clock::now();
    insertionSort(v);
    auto end = high_resolution_clock::now();

    return duration<double>(end - start);
}

duration<double> analiseMerge(vector<int> &v, int esquerda, int direita)
{
    auto start = high_resolution_clock::now();
    mergeSort(v, esquerda, direita);
    auto end = high_resolution_clock::now();

    return duration<double>(end - start);
}