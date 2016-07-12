      program embed

      integer nelem
      parameter (nelem=100)
      real myarr(nelem)

      do i=1,nelem
          myarr(i) = real(i)
      end do

      write (*,*) 'Values in Fortran (before Python):'
      write (*,'(5f5.1)') (myarr(i), i=1,5)

      call init_py()
      call register_1d_real_array('myarr', myarr, nelem)
      call run_py('myfunction()')

      write (*,*) 'Values in Fortran (after Python):'
      write (*,'(5f5.1)') (myarr(i), i=1,5)

      call dest_py()
      end program
