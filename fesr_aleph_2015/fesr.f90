
!     Main program for finite energy sum rules (FESR)
!     Last change: Matthias Jamin,  9.10.2014

!-----------------------------------------------------------------------

      program fesr

      implicit none

!     Write out experimental moments of ALEPH spectral functions
     call writeVAmomAleph()

!     Perform fit of R_tau,V moments
!     call rtauVfit()

!     Perform fit of R_tau,A moments
!     call rtauAfit()

!     Perform fit of R_tau,V and R_tau,A moments simultaneously
!      call rtauVAfit()

!     Perform fit of R_tau,V+A moments
!     call rtauVpAfit()

!     Perform fit of R_tau,V-A moments
!     call rtauVmAfit()

      stop
      end
!-----------------------------------------------------------------------
