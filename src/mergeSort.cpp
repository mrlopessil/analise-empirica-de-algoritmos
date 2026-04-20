#include "mergeSort.h"
using namespace std;

void merge(vector<int> &v, int inicio1, int inicio2, int fim2)
{
    int fim1 = inicio2 - 1;
    int i = inicio1;
    int j = inicio2;

    vector<int> tmp(fim2 - inicio1 + 1);
    int k = 0;

    while (i <= fim1 && j <= fim2)
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

    while (i <= fim1)
    {
        tmp[k] = v[i];
        i++;
        k++;
    }

    while (j <= fim2)
    {
        tmp[k] = v[j];
        j++;
        k++;
    }

    for (int i = 0; i < tmp.size(); i++)
        v[inicio1 + i] = tmp[i];
}

void mergeSort(vector<int> &v, int esquerda, int direita)
{
    if (esquerda < direita)
    {
        int meio = esquerda + (direita - esquerda) / 2;
        
        mergeSort(v, esquerda, meio);
        mergeSort(v, meio + 1, direita);
        merge(v, esquerda, meio + 1, direita);
    }
}