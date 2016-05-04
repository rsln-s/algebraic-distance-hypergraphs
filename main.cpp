#include <iostream>
#include "hypergraph.hpp"

int main(int argc, char **argv){
    PetscInitialize(&argc, &argv, NULL, NULL);
    Hypergraph* test = new Hypergraph(PETSC_COMM_WORLD, 20, 5, 5);
    PetscFinalize();
    return 0;
}