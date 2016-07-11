
#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int ierr, rank;
    ierr = MPI_Init(&argc, &argv);

    ierr = MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    printf("C: Hello World from %i!\n", rank);

    ierr = MPI_Finalize();
    return 0;
}
