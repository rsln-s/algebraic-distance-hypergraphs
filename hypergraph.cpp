#include "hypergraph.hpp"
using std::cout;

Hypergraph::Hypergraph(MPI_Comm comm, int maxweight, PetscInt number_of_edges, PetscInt number_of_vertices){
    MatCreate(comm, &bipartite_rep);
    MatSetSizes(bipartite_rep, number_of_vertices+number_of_edges, number_of_vertices+number_of_edges, number_of_vertices+number_of_edges, number_of_vertices+number_of_edges); //for now let's keep it sequential
    MatSetUp(bipartite_rep); //using default setup
    
    //awfully inefficiently insert values one at a time 'cause I'm sooo confused by MatSetValues. Also, using stdlib rand() for the same reason. And yes, this is a back-of-the-envelope way to generate bipartite graph
    //adj matrix as seen in https://en.wikipedia.org/wiki/Adjacency_matrix#Adjacency_matrix_of_a_bipartite_graph
    
    for (int v = 1; v < number_of_vertices-1; v++) {
        for (int e = 1; e < number_of_edges-1; e++) {
            if ((rand()%2) > 0)   //superarbitrary treshold, motivated by nothing
                continue;
            PetscInt val = rand()%maxweight;
            MatSetValue(bipartite_rep, v, e+number_of_edges, val, INSERT_VALUES);
            MatSetValue(bipartite_rep, e+number_of_edges, v, val, INSERT_VALUES);
        }
    }
    
    MatAssemblyBegin(bipartite_rep, MAT_FINAL_ASSEMBLY);
    MatAssemblyEnd(bipartite_rep, MAT_FINAL_ASSEMBLY);
    
    cout << "finished generating matrix representation\n";
    
    PetscViewerSetFormat(PETSC_VIEWER_STDOUT_WORLD, PETSC_VIEWER_ASCII_DENSE);
    MatView(bipartite_rep, 	PETSC_VIEWER_STDOUT_WORLD);
};