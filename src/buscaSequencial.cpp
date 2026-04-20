#include "buscaSequencial.h"
using namespace std;

int buscaSequencial(const vector<int> &v, int alvo)
{
    int tamanho = v.size();

    for (int i = 0; i < tamanho; i++)
    {
        if (v[i] == alvo)
            return i;
    }

    return -1;
}