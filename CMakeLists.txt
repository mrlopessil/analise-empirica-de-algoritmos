cmake_minimum_required(VERSION 3.10)

project(AnaliseComplexidade)

set(CMAKE_CXX_STANDARD 17)

add_executable(main
    src/main.cpp
    src/buscaBinaria.cpp
    src/buscaSequencial.cpp
    src/mergeSort.cpp
    src/insertionSort.cpp
    src/analiseEmpirica
    src/gerarVetor.cpp
)

target_include_directories(main PRIVATE include)