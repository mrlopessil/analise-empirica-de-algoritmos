#include "mergeSort.h"
using namespace std;

void merge(vector<int> &v, vector<int> &tmp, int esquerda, int meio, int direita)
{
    int i = esquerda;
    int j = meio+1;
    int k = esquerda;

    while (i <= meio && j <= direita)
    {
        if (v[i] <= v[j])
        {
            tmp[k] = v[i];
            i++;
        }
        else
        {
            tmp[k] = v[j];
            j++;
        }
        k++;
    }

    while (i <= meio)
    {
        tmp[k] = v[i];
        i++;
        k++;
    }

    while (j <= direita)
    {
        tmp[k] = v[j];
        j++;
        k++;
    }

    for (int x = esquerda; x <= direita; x++)
        v[x] = tmp[x];
}

void mergeSortAux(vector<int> &v, vector<int> &tmp, int esquerda, int direita)
{
    if (esquerda < direita)
    {
        int meio = esquerda + (direita - esquerda) / 2;

        mergeSortAux(v, tmp, esquerda, meio);
        mergeSortAux(v, tmp, meio + 1, direita);
        merge(v, tmp, esquerda, meio, direita);
    }
}

void mergeSort(vector<int> &v, int esquerda, int direita)
{
    vector<int> tmp(v.size());
    mergeSortAux(v, tmp, esquerda, direita);
}