#include <iostream>
#include <petscksp.h>

class Hypergraph {
    
    Mat bipartite_rep;
    
public:
    
    //At this point this constructor _sequentially_ generates a random weighted hypergraph 
    
    Hypergraph(MPI_Comm comm, int maxweight, PetscInt number_of_edges, PetscInt number_of_vertices);
    
};
