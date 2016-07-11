
      program hello
      include 'mpif.h'
      integer ierr, rank

      call MPI_INIT(ierr)
      call MPI_COMM_RANK(MPI_COMM_WORLD, rank, ierr)

      write(*,'(A,I1,A)') "F: Hello World from ", rank, "!"

      call MPI_FINALIZE(ierr)
      end program
