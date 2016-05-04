#include <stdlib.h>
#include <iostream>

class Hypergraph {
    
    int hidden;
    
public:
    
    //At this point this constructor _sequentially_ generates a random weighted hypergraph 
    
    Hypergraph(int _hidden);
    
};

Hypergraph::Hypergraph(int _hidden){
	hidden = _hidden;
	std::cout << hidden <<'\n';
}

int main(){
	Hypergraph test = Hypergraph(10);
	return 0;
}
