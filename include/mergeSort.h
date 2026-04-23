#include <vector>

void merge(std::vector<int> &v, int inicio1, int inicio2, int fim2);
void mergeSortAux(std::vector<int> &v, std::vector<int> &tmp, int esquerda, int direita);
void mergeSort(std::vector<int> &v, int esquerda, int direita);