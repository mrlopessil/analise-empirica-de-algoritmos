#include "gerarVetor.h"
using namespace std;

vector<int> gerarVetorAleatorio(int n)
{
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        v[i] = rand() % 10000;

    return v;
}

vector<int> gerarVetorCrescente(int n)
{
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        v[i] = i;

    return v;
}

vector<int> gerarVetorDecrescente(int n) {
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        v[i] = n-i;

    return v;
}