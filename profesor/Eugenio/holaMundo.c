#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mpi.h"


void master(int rank, int nproc) {

	char* msg = (char *) malloc(100 * sizeof(char));
	sprintf(msg, "Hola mundo desde el master\n");

	int tag = 0;

	for(int i = 1; i < nproc; ++i)
	{
		MPI_Send(msg, strlen(msg) + 1, MPI_CHAR, i, tag, MPI_COMM_WORLD);
		printf ("Sending message: %d\n", i);
	}
}


void slave(int rank, int nproc) {
	char* msg = (char *) malloc(100 * sizeof(char));
	MPI_Status * status;

	int tag = 0;

	MPI_Recv(msg, 100, MPI_CHAR, 0, tag, MPI_COMM_WORLD, status);
	printf("Esclavo %d: msg del master: %s\n", rank, msg);
}



int main (int argc, char **argv) {

	int rank;
	int nproc;

	

	
	
	MPI_Init(&argc, &argv);

	MPI_Comm_size(MPI_COMM_WORLD, &nproc);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if (rank == 0) {
		printf("Configuración: %d procesos\n", nproc);

		master(rank, nproc);
	} else {
		slave(rank, nproc);
	}

	MPI_Finalize();

	while(1)
		getc(stdin);

	return 0;

}
