#include "dilatacion.cpp"
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#define MASTER	0

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	int nodes = 1;
	char *img_path = "/home/cesar/Resultado/messi.jpg";

	if (argc > 1)
		img_path = argv[1]; 
	
	int num_tasks, rank, rc;
	char out_msg, in_msg;
	
	MPI_Status status;
	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &num_tasks);
	nodes = num_tasks;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if (rank == MASTER)
	{
		char processor_name[MPI_MAX_PROCESSOR_NAME];
    	int name_len;
    	MPI_Get_processor_name(processor_name, &name_len);
		printf("Master: %s\n", processor_name);

		rc = AbrirImagen(img_path);
		if (!rc)
			return -1;
		
		DivideImagen(nodes);

		out_msg = 'S';
		clock_t start = clock();

		for (int i = 1; i < num_tasks; i++)
			rc = MPI_Send(&out_msg, 1, MPI_CHAR, i, 1, MPI_COMM_WORLD);

        EjecutaDilatacion(MASTER);

		for (int i = 1; i < num_tasks; i++)
			rc = MPI_Recv(&in_msg, 1, MPI_CHAR, i, 1, MPI_COMM_WORLD, &status);
		

		CombinaImagen(nodes);

		clock_t end = clock();
    	double elapsed = (end - start) / (double) CLOCKS_PER_SEC;
		
		printf("\nTiempo de duracion = %f seg\n", elapsed);
		
		double bw = AnchoBanda(nodes, img_path, elapsed);
		printf("Ancho de banda =  %f MB/seg\n", bw);
		
	}
	else
	{
		char processor_name[MPI_MAX_PROCESSOR_NAME];
		int name_len;
		MPI_Get_processor_name(processor_name, &name_len);

		printf("El proceso  #%d corresponde a %s\n", rank, processor_name);

		rc = MPI_Recv(&in_msg, 1, MPI_CHAR, MASTER, 1, MPI_COMM_WORLD, &status);

		EjecutaDilatacion(rank);

		out_msg = 'R';
		rc = MPI_Send(&out_msg, 1, MPI_CHAR, MASTER, 1, MPI_COMM_WORLD);
	}

	MPI_Finalize();
}