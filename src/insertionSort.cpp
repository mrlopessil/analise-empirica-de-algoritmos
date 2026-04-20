#include "insertionSort.h"
using namespace std;

void insertionSort(vector<int> &v) {
    int tamanho = v.size();
    int novo, j;

    for (size_t i = 1; i < tamanho-1; i++)
    {
        novo = v[i];
        j = i - 1;
        while (j>= 0 && novo < v[j]) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = novo;
    }
    
}