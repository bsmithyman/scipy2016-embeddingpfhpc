      subroutine stackf()
      write (*,*) "F: in 'stackf'"
      end subroutine

      subroutine stackf_callc()
      write (*,*) "F: in 'stackf_callc'"
      call stackc
      end subroutine
