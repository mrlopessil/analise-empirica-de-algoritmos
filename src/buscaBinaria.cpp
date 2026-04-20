#include "buscaBinaria.h"
using namespace std;

int buscaBinaria(const vector<int> &v, int inicio, int fim, int alvo)
{
    if (inicio > fim)
    {
        return -1;
    }

    int meio = inicio + (fim - inicio) / 2;

    if (v[meio] == alvo)
        return meio;
    else if (v[meio] < alvo)
        return buscaBinaria(v, meio + 1, fim, alvo);
    else
        return buscaBinaria(v, inicio, meio - 1, alvo);
}