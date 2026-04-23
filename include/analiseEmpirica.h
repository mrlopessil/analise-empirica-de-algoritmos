#include "buscaBinaria.h"
#include "buscaSequencial.h"
#include "insertionSort.h"
#include "mergeSort.h"
#include "gerarVetor.h"
#include <chrono>
#include <iostream>
#include <fstream>
#include <cstdlib>

void analiseEmpirica();

std::chrono::duration<double> analiseBinaria(const std::vector<int> &v, int inicio, int fim, int alvo);
std::chrono::duration<double> analiseSequencial(const std::vector<int> &v, int n);
std::chrono::duration<double> analiseInsert(std::vector<int> &v);
std::chrono::duration<double> analiseMerge(std::vector<int> &v, int esquerda, int direita);