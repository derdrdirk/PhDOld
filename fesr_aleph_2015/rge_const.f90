      ! Definition of renormalisation group constants
      module rge_const
         use num_const

         implicit none
         integer :: f  !  Number of flavours
!     beta-function coefficients beta_1 to beta_4
         real(dp), dimension(3:6), parameter ::&
            &be_1 = (/ (5.5d0 - f/3.d0, f=3,6) /),&
            &be_2 = (/ (12.75d0 - 19.d0/12.d0*f, f=3,6) /),&
            &be_3 = (/ (2857.d0/64.d0 - 5033.d0/576.d0*f +&
                       &325.d0/1728.d0*f*f, f=3,6) /),&
            &be_4 = (/ (149753.d0/768.d0 + 891.d0/32.d0*z3 -&
                       &(1078361.d0/20736.d0 + 1627.d0/864.d0*z3)*f +&
                       &(50065.d0/20736.d0 + 809.d0/1296.d0*z3)*f*f +&
                       &1093.d0/93312.d0*f**3, f=3,6) /)

!     Auxiliary constants for running alpha_s
         real(dp), dimension(3:6), parameter ::&
            &be_ratio_21 = (/ (be_2(f)/be_1(f), f=3,6) /),&
            &be_ratio_31 = (/ (be_3(f)/be_1(f), f=3,6) /),&
            &be_ratio_41 = (/ (be_4(f)/be_1(f), f=3,6) /)

         real(dp), dimension(3:6), parameter ::&
            &be_ratio_14 = (/ (be_1(f)/be_4(f), f=3,6) /),&
            &be_ratio_24 = (/ (be_2(f)/be_4(f), f=3,6) /),&
            &be_ratio_34 = (/ (be_3(f)/be_4(f), f=3,6) /)

         real(dp), dimension(3:6), parameter ::&
            &pp = (/ (be_ratio_24(f)-be_ratio_34(f)**2/3.d0, f=3,6) /),&
            &qq = (/ (be_ratio_14(f)-be_ratio_24(f)*be_ratio_34(f)/&
                     &3.d0+2.d0*be_ratio_34(f)**3/27.d0, f=3,6) /)

         real(dp), dimension(3:6), parameter ::&
            &dis = (/ ((qq(f)/2.d0)**2+(pp(f)/3.d0)**3, f=3,6) /)

         real(dp), dimension(3:6), parameter ::&
            &qr_1 = (/ ( exp(log(sqrt(dis(f))-qq(f)/2.d0)/3.d0),&
                      & f=3,6) /),&
            &qr_2 = (/ (-exp(log(sqrt(dis(f))+qq(f)/2.d0)/3.d0),&
                      & f=3,6) /)

         real(dp), dimension(3:6) ::&
            &qw_1 = (/ (qr_1(f)+qr_2(f)+2.d0*be_ratio_34(f)/3.d0,&
                      &f=3,6) /),&
            &qw_2 = (/ (qr_1(f)**2+qr_2(f)**2-qr_1(f)*qr_2(f)+(qr_1(f)&
                       &+qr_2(f))*be_ratio_34(f)/3.d0+be_ratio_34(f)**2&
                       &/9.d0, f=3,6) /),&
            &qw_3 = (/ (be_ratio_34(f)/3.d0-qr_1(f)-qr_2(f), f=3,6) /)

!     mass anomalous dimension coefficients gamma_1 to gamma_4
         real(dp), dimension(3:6), parameter ::&
            &ga_1 = (/ (2.d0, f=3,6) /),&
            &ga_2 = (/ (101.d0/12.d0 - 5.d0/18.d0*f, f=3,6) /),&
            &ga_3 = (/ (1249.d0/32.d0 - (277.d0/108.d0+5.d0/3.d0*z3)*f&
                       &- 35.d0/648.d0*f*f, f=3,6) /),&
            &ga_4 = (/ (4603055.d0/20736.d0+1060.d0/27.d0*z3-275.d0/&
                       &4.d0*z5 + (11.d0/144.d0*pi**4-91723.d0/3456.d0-&
                       &2137.d0/72.d0*z3+575.d0/36.d0*z5)*f + (2621.d0/&
                       &15552.d0-pi**4/216.d0+25.d0/36.d0*z3)*f*f -&
                       &(83.d0/7776.d0-z3/54.d0)*f**3, f=3,6) /)

!     Auxiliary constants for running quark mass
         real(dp), dimension(3:6), parameter ::&
            &gg_0 = (/ (ga_1(f)/be_1(f), f=3,6) /),&
            &gg_1 = (/ (ga_2(f)/be_1(f)-be_2(f)*ga_1(f)/be_1(f)**2,&
                       &f=3,6) /),&
            &gg_2 = (/ (ga_3(f)/be_1(f)-be_2(f)*ga_2(f)/be_1(f)**2+&
                       &ga_1(f)/be_1(f)**2*(be_2(f)**2/be_1(f)-&
                       &be_3(f)), f=3,6) /),&
            &gg_3 = (/ (ga_4(f)/be_1(f)-be_2(f)*ga_3(f)/be_1(f)**2+&
                       &ga_2(f)/be_1(f)**2*(be_2(f)**2/be_1(f)-&
                       &be_3(f))+ga_1(f)/be_1(f)**2*(be_2(f)*be_3(f)/&
                       &be_1(f)-be_2(f)/be_1(f)*(be_2(f)**2/be_1(f)-&
                       &be_3(f))-be_4(f)), f=3,6) /)

         real(dp), dimension(3:6), parameter ::&
            &ggg_2 = (/ ((gg_2(f)+gg_1(f)**2)/2.d0, f=3,6) /),&
            &ggg_3 = (/ ((gg_3(f)+1.5d0*gg_1(f)*gg_2(f)+&
                         &gg_1(f)**3/2.d0)/3.d0, f=3,6) /)

         real(dp), dimension(3:6), parameter ::&
            &qm_1 = (/ (ga_1(f)/ga_4(f)-be_ratio_14(f), f=3,6) /),&
            &qm_2 = (/ (ga_2(f)/ga_4(f)-be_ratio_24(f), f=3,6) /),&
            &qm_3 = (/ (ga_3(f)/ga_4(f)-be_ratio_34(f), f=3,6) /)

      end module rge_const
