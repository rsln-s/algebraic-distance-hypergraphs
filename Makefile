include ${PETSC_DIR}/lib/petsc/conf/variables
include ${PETSC_DIR}/lib/petsc/conf/rules

main : main.o hypergraph.o chkopts
	mpicc -o main main.o hypergraph.o ${PETSC_LIB}
	${RM} main.o hypergraph.o 
	mpiexec -np 1 ./main
