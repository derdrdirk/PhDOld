!     Initialise the dependent coefficients cVA0(n,k,nf)
      module cVA0_depen
         implicit none

      contains

      subroutine init_cVA0nk(n,cV0)
      use num_const
      use rge_const

      implicit none
      integer,                intent(in) :: n
      real(dp), dimension(0:12,1:12,3:6) :: cV0

      if (n < 2) return
         cV0(2,2,:) = -be_1(:)*cV0(1,1,:)/4.d0
      if (n < 3) return
         cV0(3,2,:) = (-be_2(:)*cV0(1,1,:)-2.d0*be_1(:)*cV0(2,1,:))/4.d0
         cV0(3,3,:) = be_1(:)**2*cV0(1,1,:)/12.d0
      if (n < 4) return
         cV0(4,2,:) = (-be_3(:)*cV0(1,1,:)-2.d0*be_2(:)*cV0(2,1,:)-&
                      &3.d0*be_1(:)*cV0(3,1,:))/4.d0
         cV0(4,3,:) = (5.d0*be_1(:)*be_2(:)*cV0(1,1,:)+&
                      &6.d0*be_1(:)**2*cV0(2,1,:))/24.d0
         cV0(4,4,:) = -be_1(:)**3*cV0(1,1,:)/32.d0
      if (n < 5) return
         cV0(5,2,:) = (-be_4(:)*cV0(1,1,:)-2.d0*be_3(:)*cV0(2,1,:)-&
                  &3.d0*be_2(:)*cV0(3,1,:)-4.d0*be_1(:)*cV0(4,1,:))/4.d0
         cV0(5,3,:) = (3.d0*be_2(:)**2*cV0(1,1,:)+6.d0*be_1(:)*be_3(:)*&
                      &cV0(1,1,:)+14.d0*be_1(:)*be_2(:)*cV0(2,1,:)+&
                      &12.d0*be_1(:)**2*cV0(3,1,:))/24.d0
         cV0(5,4,:) = (-13.d0*be_1(:)**2*be_2(:)*cV0(1,1,:)-&
                      &12.d0*be_1(:)**3*cV0(2,1,:))/96.d0
         cV0(5,5,:) = be_1(:)**4*cV0(1,1,:)/80.d0
      if (n < 6) return
         cV0(6,2,:) = (-2.d0*be_4(:)*cV0(2,1,:)-3.d0*be_3(:)*cV0(3,1,:)&
                      &-4.d0*be_2(:)*cV0(4,1,:)-5.d0*be_1(:)*cV0(5,1,:)&
                      &)/4.d0
         cV0(6,3,:) = (7.d0*be_2(:)*be_3(:)*cV0(1,1,:)+7.d0*be_1(:)*&
                      &be_4(:)*cV0(1,1,:)+8.d0*be_2(:)**2*cV0(2,1,:)+&
                      &16.d0*be_1(:)*be_3(:)*cV0(2,1,:)+27.d0*be_1(:)*&
                      &be_2(:)*cV0(3,1,:)+20.d0*be_1(:)**2*cV0(4,1,:))&
                      &/24.d0
         cV0(6,4,:) = (-35.d0*be_1(:)*be_2(:)**2*cV0(1,1,:)-36.d0*&
                      &be_1(:)**2*be_3(:)*cV0(1,1,:)-94.d0*be_1(:)**2*&
                      &be_2(:)*cV0(2,1,:)-60.d0*be_1(:)**3*cV0(3,1,:))&
                      &/192.d0
         cV0(6,5,:) = (77.d0*be_1(:)**3*be_2(:)*cV0(1,1,:)+60.d0*&
                      &be_1(:)**4*cV0(2,1,:))/960.d0
         cV0(6,6,:) = -be_1(:)**5*cV0(1,1,:)/192.d0
      if (n < 7) return
         cV0(7,2,:) = (-3.d0*be_4(:)*cV0(3,1,:)-4.d0*be_3(:)*cV0(4,1,:)&
                      &-5.d0*be_2(:)*cV0(5,1,:)-6.d0*be_1(:)*cV0(6,1,:)&
                      &)/4.d0
         cV0(7,3,:) = (4.d0*be_3(:)**2*cV0(1,1,:)+8.d0*be_2(:)*be_4(:)*&
                      &cV0(1,1,:)+18.d0*be_2(:)*be_3(:)*cV0(2,1,:)+&
                      &18.d0*be_1(:)*be_4(:)*cV0(2,1,:)+15.d0*&
                      &be_2(:)**2*cV0(3,1,:)+30.d0*be_1(:)*be_3(:)*&
                      &cV0(3,1,:)+44.d0*be_1(:)*be_2(:)*cV0(4,1,:)+&
                      &30.d0*be_1(:)**2*cV0(5,1,:))/24.d0
         cV0(7,4,:) = (-15.d0*be_2(:)**3*cV0(1,1,:)-92.d0*be_1(:)*&
                      &be_2(:)*be_3(:)*cV0(1,1,:)-48.d0*be_1(:)**2*&
                      &be_4(:)*cV0(1,1,:)-118.d0*be_1(:)*be_2(:)**2*&
                      &cV0(2,1,:)-120.d0*be_1(:)**2*be_3(:)*cV0(2,1,:)-&
                      &222.d0*be_1(:)**2*be_2(:)*cV0(3,1,:)-120.d0*&
                      &be_1(:)**3*cV0(4,1,:))/192.d0
         cV0(7,5,:) = (85.d0*be_1(:)**2*be_2(:)**2*cV0(1,1,:)+60.d0*&
                      &be_1(:)**3*be_3(:)*cV0(1,1,:)+171.d0*be_1(:)**3&
                      &*be_2(:)*cV0(2,1,:)+90.d0*be_1(:)**4*cV0(3,1,:)&
                      &)/480.d0
         cV0(7,6,:) = (-29.d0*be_1(:)**4*be_2(:)*cV0(1,1,:)-20.d0*&
                      &be_1(:)**5*cV0(2,1,:))/640.d0
         cV0(7,7,:) = be_1(:)**6*cV0(1,1,:)/448.d0
      if (n < 8) return
         cV0(8,2,:) = (-4.d0*be_4(:)*cV0(4,1,:)-5.d0*be_3(:)*cV0(5,1,:)&
                      &-6.d0*be_2(:)*cV0(6,1,:)-7.d0*be_1(:)*cV0(7,1,:)&
                      &)/4.d0
         cV0(8,3,:) = (9.d0*be_3(:)*be_4(:)*cV0(1,1,:)+10.d0*be_3(:)**2&
                      &*cV0(2,1,:)+20.d0*be_2(:)*be_4(:)*cV0(2,1,:)+&
                      &33.d0*be_2(:)*be_3(:)*cV0(3,1,:)+33.d0*be_1(:)*&
                      &be_4(:)*cV0(3,1,:)+24.d0*be_2(:)**2*cV0(4,1,:)+&
                      &48.d0*be_1(:)*be_3(:)*cV0(4,1,:)+65.d0*be_1(:)*&
                      &be_2(:)*cV0(5,1,:)+42.d0*be_1(:)**2*cV0(6,1,:))&
                      &/24.d0
         cV0(8,4,:) = (-57.d0*be_2(:)**2*be_3(:)*cV0(1,1,:)-58.d0*&
                      &be_1(:)*be_3(:)**2*cV0(1,1,:)-118.d0*be_1(:)*&
                      &be_2(:)*be_4(:)*cV0(1,1,:)-48.d0*be_2(:)**3*&
                      &cV0(2,1,:)-292.d0*be_1(:)*be_2(:)*be_3(:)*&
                      &cV0(2,1,:)-150.d0*be_1(:)**2*be_4(:)*cV0(2,1,:)-&
                      &267.d0*be_1(:)*be_2(:)**2*cV0(3,1,:)-270.d0*&
                      &be_1(:)**2*be_3(:)*cV0(3,1,:)-428.d0*be_1(:)**2*&
                      &be_2(:)*cV0(4,1,:)-210.d0*be_1(:)**3*cV0(5,1,:))&
                      &/192.d0
         cV0(8,5,:) = (315.d0*be_1(:)*be_2(:)**3*cV0(1,1,:)+990.d0*&
                      &be_1(:)**2*be_2(:)*be_3(:)*cV0(1,1,:)+360.d0*&
                      &be_1(:)**3*be_4(:)*cV0(1,1,:)+1390.d0*be_1(:)**2&
                      &*be_2(:)**2*cV0(2,1,:)+960.d0*be_1(:)**3*&
                      &be_3(:)*cV0(2,1,:)+1914.d0*be_1(:)**3*be_2(:)*&
                      &cV0(3,1,:)+840.d0*be_1(:)**4*cV0(4,1,:))/1920.d0
         cV0(8,6,:) = (-826.d0*be_1(:)**3*be_2(:)**2*cV0(1,1,:)-450.d0&
                      &*be_1(:)**4*be_3(:)*cV0(1,1,:)-1377.d0*&
                      &be_1(:)**4*be_2(:)*cV0(2,1,:)-630.d0*be_1(:)**5&
                      &*cV0(3,1,:))/5760.d0
         cV0(8,7,:) = (223.d0*be_1(:)**5*be_2(:)*cV0(1,1,:)+140.d0*&
                      &be_1(:)**6*cV0(2,1,:))/8960.d0
         cV0(8,8,:) = -be_1(:)**7*cV0(1,1,:)/1024.d0
      if (n < 9) return
         cV0(9,2,:) = (-5.d0*be_4(:)*cV0(5,1,:)-6.d0*be_3(:)*cV0(6,1,:)&
                      &-7.d0*be_2(:)*cV0(7,1,:)-8.d0*be_1(:)*cV0(8,1,:)&
                      &)/4.d0
         cV0(9,3,:) = (5.d0*be_4(:)**2*cV0(1,1,:)+22.d0*be_3(:)*be_4(:)&
                      &*cV0(2,1,:)+18.d0*be_3(:)**2*cV0(3,1,:)+36.d0*&
                      &be_2(:)*be_4(:)*cV0(3,1,:)+52.d0*be_2(:)*be_3(:)&
                      &*cV0(4,1,:)+52.d0*be_1(:)*be_4(:)*cV0(4,1,:)+&
                      &35.d0*be_2(:)**2*cV0(5,1,:)+70.d0*be_1(:)*&
                      &be_3(:)*cV0(5,1,:)+90.d0*be_1(:)*be_2(:)*&
                      &cV0(6,1,:)+56.d0*be_1(:)**2*cV0(7,1,:))/24.d0
         cV0(9,4,:) = (-70.d0*be_2(:)*be_3(:)**2*cV0(1,1,:)-71.d0*&
                      &be_2(:)**2*be_4(:)*cV0(1,1,:)-144.d0*be_1(:)*&
                      &be_3(:)*be_4(:)*cV0(1,1,:)-174.d0*be_2(:)**2*&
                      &be_3(:)*cV0(2,1,:)-176.d0*be_1(:)*be_3(:)**2*&
                      &cV0(2,1,:)-356.d0*be_1(:)*be_2(:)*be_4(:)*&
                      &cV0(2,1,:)-105.d0*be_2(:)**3*cV0(3,1,:)-636.d0*&
                      &be_1(:)*be_2(:)*be_3(:)*cV0(3,1,:)-324.d0*&
                      &be_1(:)**2*be_4(:)*cV0(3,1,:)-500.d0*be_1(:)*&
                      &be_2(:)**2*cV0(4,1,:)-504.d0*be_1(:)**2*be_3(:)*&
                      &cV0(4,1,:)-730.d0*be_1(:)**2*be_2(:)*cV0(5,1,:)-&
                      &336.d0*be_1(:)**3*cV0(6,1,:))/192.d0
         cV0(9,5,:) = (105.d0*be_2(:)**4*cV0(1,1,:)+1310.d0*be_1(:)*&
                      &be_2(:)**2*be_3(:)*cV0(1,1,:)+680.d0*be_1(:)**2*&
                      &be_3(:)**2*cV0(1,1,:)+1410.d0*be_1(:)**2*be_2(:)&
                      &*be_4(:)*cV0(1,1,:)+1210.d0*be_1(:)*be_2(:)**3*&
                      &cV0(2,1,:)+3740.d0*be_1(:)**2*be_2(:)*be_3(:)*&
                      &cV0(2,1,:)+1320.d0*be_1(:)**3*be_4(:)*cV0(2,1,:)&
                      &+3690.d0*be_1(:)**2*be_2(:)**2*cV0(3,1,:)+&
                      &2520.d0*be_1(:)**3*be_3(:)*cV0(3,1,:)+4264.d0*&
                      &be_1(:)**3*be_2(:)*cV0(4,1,:)+1680.d0*be_1(:)**4&
                      &*cV0(5,1,:))/1920.d0
         cV0(9,6,:) = (-1225.d0*be_1(:)**2*be_2(:)**3*cV0(1,1,:)-&
                      &2631.d0*be_1(:)**3*be_2(:)*be_3(:)*cV0(1,1,:)-&
                      &750.d0*be_1(:)**4*be_4(:)*cV0(1,1,:)-3977.d0*&
                      &be_1(:)**3*be_2(:)**2*cV0(2,1,:)-2100.d0*&
                      &be_1(:)**4*be_3(:)*cV0(2,1,:)-4458.d0*be_1(:)**4&
                      &*be_2(:)*cV0(3,1,:)-1680.d0*be_1(:)**5*&
                      &cV0(4,1,:))/5760.d0
         cV0(9,7,:) = (8435.d0*be_1(:)**4*be_2(:)**2*cV0(1,1,:)+3780.d0&
                      &*be_1(:)**5*be_3(:)*cV0(1,1,:)+12276.d0*&
                      &be_1(:)**5*be_2(:)*cV0(2,1,:)+5040.d0*be_1(:)**6&
                      &*cV0(3,1,:))/80640.d0
         cV0(9,8,:) = (-481.d0*be_1(:)**6*be_2(:)*cV0(1,1,:)-280.d0*&
                      &be_1(:)**7*cV0(2,1,:))/35840.d0
         cV0(9,9,:) = be_1(:)**8*cV0(1,1,:)/2304.d0
      if (n < 10) return
        cV0(10,2,:) = (-6.d0*be_4(:)*cV0(6,1,:)-7.d0*be_3(:)*cV0(7,1,:)&
                      &-8.d0*be_2(:)*cV0(8,1,:)-9.d0*be_1(:)*cV0(9,1,:)&
                      &)/4.d0
        cV0(10,3,:) = (12.d0*be_4(:)**2*cV0(2,1,:)+39.d0*be_3(:)*&
                      &be_4(:)*cV0(3,1,:)+28.d0*be_3(:)**2*cV0(4,1,:)+&
                      &56.d0*be_2(:)*be_4(:)*cV0(4,1,:)+75.d0*be_2(:)*&
                      &be_3(:)*cV0(5,1,:)+75.d0*be_1(:)*be_4(:)*&
                      &cV0(5,1,:)+48.d0*be_2(:)**2*cV0(6,1,:)+96.d0*&
                      &be_1(:)*be_3(:)*cV0(6,1,:)+119.d0*be_1(:)*&
                      &be_2(:)*cV0(7,1,:)+72.d0*be_1(:)**2*cV0(8,1,:))&
                      &/24.d0
        cV0(10,4,:) = (-28.d0*be_3(:)**3*cV0(1,1,:)-170.d0*be_2(:)*&
                      &be_3(:)*be_4(:)*cV0(1,1,:)-87.d0*be_1(:)*&
                      &be_4(:)**2*cV0(1,1,:)-206.d0*be_2(:)*be_3(:)**2&
                      &*cV0(2,1,:)-208.d0*be_2(:)**2*be_4(:)*cV0(2,1,:)&
                      &-420.d0*be_1(:)*be_3(:)*be_4(:)*cV0(2,1,:)-&
                      &369.d0*be_2(:)**2*be_3(:)*cV0(3,1,:)-372.d0*&
                      &be_1(:)*be_3(:)**2*cV0(3,1,:)-750.d0*be_1(:)*&
                      &be_2(:)*be_4(:)*cV0(3,1,:)-192.d0*be_2(:)**3*&
                      &cV0(4,1,:)-1160.d0*be_1(:)*be_2(:)*be_3(:)*&
                      &cV0(4,1,:)-588.d0*be_1(:)**2*be_4(:)*cV0(4,1,:)-&
                      &835.d0*be_1(:)*be_2(:)**2*cV0(5,1,:)-840.d0*&
                      &be_1(:)**2*be_3(:)*cV0(5,1,:)-1146.d0*be_1(:)**2&
                      &*be_2(:)*cV0(6,1,:)-504.d0*be_1(:)**3*cV0(7,1,:)&
                      &)/192.d0
        cV0(10,5,:) = (561.d0*be_2(:)**3*be_3(:)*cV0(1,1,:)+1738.d0*&
                      &be_1(:)*be_2(:)*be_3(:)**2*cV0(1,1,:)+1793.d0*&
                      &be_1(:)*be_2(:)**2*be_4(:)*cV0(1,1,:)+1848.d0*&
                      &be_1(:)**2*be_3(:)*be_4(:)*cV0(1,1,:)+384.d0*&
                      &be_2(:)**4*cV0(2,1,:)+4728.d0*be_1(:)*be_2(:)**2&
                      &*be_3(:)*cV0(2,1,:)+2424.d0*be_1(:)**2*&
                      &be_3(:)**2*cV0(2,1,:)+4968.d0*be_1(:)**2*be_2(:)&
                      &*be_4(:)*cV0(2,1,:)+3081.d0*be_1(:)*be_2(:)**3*&
                      &cV0(3,1,:)+9438.d0*be_1(:)**2*be_2(:)*be_3(:)*&
                      &cV0(3,1,:)+3276.d0*be_1(:)**3*be_4(:)*cV0(3,1,:)&
                      &+7924.d0*be_1(:)**2*be_2(:)**2*cV0(4,1,:)+&
                      &5376.d0*be_1(:)**3*be_3(:)*cV0(4,1,:)+8250.d0*&
                      &be_1(:)**3*be_2(:)*cV0(5,1,:)+3024.d0*be_1(:)**4&
                      &*cV0(6,1,:))/1920.d0
        cV0(10,6,:) = (-3465.d0*be_1(:)*be_2(:)**4*cV0(1,1,:)-22090.d0*&
                      &be_1(:)**2*be_2(:)**2*be_3(:)*cV0(1,1,:)-7800.d0&
                      &*be_1(:)**3*be_3(:)**2*cV0(1,1,:)-16494.d0*&
                      &be_1(:)**3*be_2(:)*be_4(:)*cV0(1,1,:)-22010.d0*&
                      &be_1(:)**2*be_2(:)**3*cV0(2,1,:)-46128.d0*&
                      &be_1(:)**3*be_2(:)*be_3(:)*cV0(2,1,:)-12600.d0*&
                      &be_1(:)**4*be_4(:)*cV0(2,1,:)-48522.d0*&
                      &be_1(:)**3*be_2(:)**2*cV0(3,1,:)-25200.d0*&
                      &be_1(:)**4*be_3(:)*cV0(3,1,:)-45096.d0*&
                      &be_1(:)**4*be_2(:)*cV0(4,1,:)-15120.d0*&
                      &be_1(:)**5*cV0(5,1,:))/23040.d0
        cV0(10,7,:) = (17633.d0*be_1(:)**3*be_2(:)**3*cV0(1,1,:)+&
                      &29106.d0*be_1(:)**4*be_2(:)*be_3(:)*cV0(1,1,:)+&
                      &6930.d0*be_1(:)**5*be_4(:)*cV0(1,1,:)+46809.d0*&
                      &be_1(:)**4*be_2(:)**2*cV0(2,1,:)+20160.d0*&
                      &be_1(:)**5*be_3(:)*cV0(2,1,:)+45162.d0*&
                      &be_1(:)**5*be_2(:)*cV0(3,1,:)+15120.d0*&
                      &be_1(:)**6*cV0(4,1,:))/80640.d0
        cV0(10,8,:) = (-10219.d0*be_1(:)**5*be_2(:)**2*cV0(1,1,:)-&
                      &3920.d0*be_1(:)**6*be_3(:)*cV0(1,1,:)-13396.d0*&
                      &be_1(:)**6*be_2(:)*cV0(2,1,:)-5040.d0*be_1(:)**7&
                      &*cV0(3,1,:))/143360.d0
        cV0(10,9,:) = (4609.d0*be_1(:)**7*be_2(:)*cV0(1,1,:)+2520.d0*&
                      &be_1(:)**8*cV0(2,1,:))/645120.d0
        cV0(10,10,:)= -be_1(:)**9*cV0(1,1,:)/5120.d0
      if (n < 11) return
        cV0(11,2,:) = (-7.d0*be_4(:)*cV0(7,1,:)-8.d0*be_3(:)*cV0(8,1,:)&
                      &-9.d0*be_2(:)*cV0(9,1,:)-10.d0*be_1(:)*&
                      &cV0(10,1,:))/4.d0
        cV0(11,3,:) = (21.d0*be_4(:)**2*cV0(3,1,:)+60.d0*be_3(:)*&
                      &be_4(:)*cV0(4,1,:)+40.d0*be_3(:)**2*cV0(5,1,:)+&
                      &80.d0*be_2(:)*be_4(:)*cV0(5,1,:)+102.d0*be_2(:)*&
                      &be_3(:)*cV0(6,1,:)+102.d0*be_1(:)*be_4(:)*&
                      &cV0(6,1,:)+63.d0*be_2(:)**2*cV0(7,1,:)+126.d0*&
                      &be_1(:)*be_3(:)*cV0(7,1,:)+152.d0*be_1(:)*&
                      &be_2(:)*cV0(8,1,:)+90.d0*be_1(:)**2*cV0(9,1,:))&
                      &/24.d0
        cV0(11,4,:) = (-100.d0*be_3(:)**2*be_4(:)*cV0(1,1,:)-101.d0*&
                      &be_2(:)*be_4(:)**2*cV0(1,1,:)-80.d0*be_3(:)**3*&
                      &cV0(2,1,:)-484.d0*be_2(:)*be_3(:)*be_4(:)*&
                      &cV0(2,1,:)-246.d0*be_1(:)*be_4(:)**2*cV0(2,1,:)-&
                      &426.d0*be_2(:)*be_3(:)**2*cV0(3,1,:)-429.d0*&
                      &be_2(:)**2*be_4(:)*cV0(3,1,:)-864.d0*be_1(:)*&
                      &be_3(:)*be_4(:)*cV0(3,1,:)-660.d0*be_2(:)**2*&
                      &be_3(:)*cV0(4,1,:)-664.d0*be_1(:)*be_3(:)**2*&
                      &cV0(4,1,:)-1336.d0*be_1(:)*be_2(:)*be_4(:)*&
                      &cV0(4,1,:)-315.d0*be_2(:)**3*cV0(5,1,:)-1900.d0*&
                      &be_1(:)*be_2(:)*be_3(:)*cV0(5,1,:)-960.d0*&
                      &be_1(:)**2*be_4(:)*cV0(5,1,:)-1290.d0*be_1(:)*&
                      &be_2(:)**2*cV0(6,1,:)-1296.d0*be_1(:)**2*be_3(:)&
                      &*cV0(6,1,:)-1694.d0*be_1(:)**2*be_2(:)*&
                      &cV0(7,1,:)-720.d0*be_1(:)**3*cV0(8,1,:))/192.d0
        cV0(11,5,:) = (1086.d0*be_2(:)**2*be_3(:)**2*cV0(1,1,:)+744.d0*&
                      &be_1(:)*be_3(:)**3*cV0(1,1,:)+744.d0*be_2(:)**3*&
                      &be_4(:)*cV0(1,1,:)+4584.d0*be_1(:)*be_2(:)*&
                      &be_3(:)*be_4(:)*cV0(1,1,:)+1206.d0*be_1(:)**2*&
                      &be_4(:)**2*cV0(1,1,:)+1950.d0*be_2(:)**3*be_3(:)&
                      &*cV0(2,1,:)+5980.d0*be_1(:)*be_2(:)*be_3(:)**2*&
                      &cV0(2,1,:)+6110.d0*be_1(:)*be_2(:)**2*be_4(:)*&
                      &cV0(2,1,:)+6240.d0*be_1(:)**2*be_3(:)*be_4(:)*&
                      &cV0(2,1,:)+945.d0*be_2(:)**4*cV0(3,1,:)+11550.d0&
                      &*be_1(:)*be_2(:)**2*be_3(:)*cV0(3,1,:)+5880.d0*&
                      &be_1(:)**2*be_3(:)**2*cV0(3,1,:)+11970.d0*&
                      &be_1(:)**2*be_2(:)*be_4(:)*cV0(3,1,:)+6420.d0*&
                      &be_1(:)*be_2(:)**3*cV0(4,1,:)+19560.d0*&
                      &be_1(:)**2*be_2(:)*be_3(:)*cV0(4,1,:)+6720.d0*&
                      &be_1(:)**3*be_4(:)*cV0(4,1,:)+14920.d0*&
                      &be_1(:)**2*be_2(:)**2*cV0(5,1,:)+10080.d0*&
                      &be_1(:)**3*be_3(:)*cV0(5,1,:)+14484.d0*&
                      &be_1(:)**3*be_2(:)*cV0(6,1,:)+5040.d0*be_1(:)**4&
                      &*cV0(7,1,:))/1920.d0
        cV0(11,6,:) = (-945.d0*be_2(:)**5*cV0(1,1,:)-19920.d0*be_1(:)*&
                      &be_2(:)**3*be_3(:)*cV0(1,1,:)-31420.d0*&
                      &be_1(:)**2*be_2(:)*be_3(:)**2*cV0(1,1,:)-&
                      &33000.d0*be_1(:)**2*be_2(:)**2*be_4(:)*&
                      &cV0(1,1,:)-23040.d0*be_1(:)**3*be_3(:)*be_4(:)*&
                      &cV0(1,1,:)-14730.d0*be_1(:)*be_2(:)**4*&
                      &cV0(2,1,:)-92060.d0*be_1(:)**2*be_2(:)**2*&
                      &be_3(:)*cV0(2,1,:)-31920.d0*be_1(:)**3*&
                      &be_3(:)**2*cV0(2,1,:)-66348.d0*be_1(:)**3*&
                      &be_2(:)*be_4(:)*cV0(2,1,:)-64020.d0*be_1(:)**2*&
                      &be_2(:)**3*cV0(3,1,:)-132372.d0*be_1(:)**3*&
                      &be_2(:)*be_3(:)*cV0(3,1,:)-35280.d0*be_1(:)**4*&
                      &be_4(:)*cV0(3,1,:)-117616.d0*be_1(:)**3*&
                      &be_2(:)**2*cV0(4,1,:)-60480.d0*be_1(:)**4*&
                      &be_3(:)*cV0(4,1,:)-97620.d0*be_1(:)**4*be_2(:)*&
                      &cV0(5,1,:)-30240.d0*be_1(:)**5*cV0(6,1,:))/&
                      &23040.d0
        cV0(11,7,:) = (39375.d0*be_1(:)**2*be_2(:)**4*cV0(1,1,:)+&
                      &171024.d0*be_1(:)**3*be_2(:)**2*be_3(:)*&
                      &cV0(1,1,:)+46200.d0*be_1(:)**4*be_3(:)**2*&
                      &cV0(1,1,:)+99624.d0*be_1(:)**4*be_2(:)*be_4(:)*&
                      &cV0(1,1,:)+181636.d0*be_1(:)**3*be_2(:)**3*&
                      &cV0(2,1,:)+290472.d0*be_1(:)**4*be_2(:)*&
                      &be_3(:)*cV0(2,1,:)+65520.d0*be_1(:)**5*be_4(:)*&
                      &cV0(2,1,:)+322854.d0*be_1(:)**4*be_2(:)**2*&
                      &cV0(3,1,:)+136080.d0*be_1(:)**5*be_3(:)*&
                      &cV0(3,1,:)+255720.d0*be_1(:)**5*be_2(:)*&
                      &cV0(4,1,:)+75600.d0*be_1(:)**6*cV0(5,1,:))/&
                      &161280.d0
        cV0(11,8,:) = (-252245.d0*be_1(:)**4*be_2(:)**3*cV0(1,1,:)-&
                      &341136.d0*be_1(:)**5*be_2(:)*be_3(:)*cV0(1,1,:)-&
                      &70560.d0*be_1(:)**6*be_4(:)*cV0(1,1,:)-578574.d0&
                      &*be_1(:)**5*be_2(:)**2*cV0(2,1,:)-211680.d0*&
                      &be_1(:)**6*be_3(:)*cV0(2,1,:)-496980.d0*&
                      &be_1(:)**6*be_2(:)*cV0(3,1,:)-151200.d0*&
                      &be_1(:)**7*cV0(4,1,:))/1290240.d0
        cV0(11,9,:) = (59753.d0*be_1(:)**6*be_2(:)**2*cV0(1,1,:)+&
                      &20160.d0*be_1(:)**7*be_3(:)*cV0(1,1,:)+72020.d0*&
                      &be_1(:)**7*be_2(:)*cV0(2,1,:)+25200.d0*&
                      &be_1(:)**8*cV0(3,1,:))/1290240.d0
        cV0(11,10,:)= (-4861.d0*be_1(:)**8*be_2(:)*cV0(1,1,:)-&
                      &2520.d0*be_1(:)**9*cV0(2,1,:))/1290240.d0
        cV0(11,11,:)= be_1(:)**10*cV0(1,1,:)/11264.d0
      if (n < 12) return
        cV0(12,2,:) = (-8.d0*be_4(:)*cV0(8,1,:)-9.d0*be_3(:)*cV0(9,1,:)&
                      &-10.d0*be_2(:)*cV0(10,1,:)-11.d0*be_1(:)*&
                      &cV0(11,1,:))/4.d0
        cV0(12,3,:) = (32.d0*be_4(:)**2*cV0(4,1,:)+85.d0*be_3(:)*&
                      &be_4(:)*cV0(5,1,:)+54.d0*be_3(:)**2*cV0(6,1,:)+&
                      &108.d0*be_2(:)*be_4(:)*cV0(6,1,:)+133.d0*be_2(:)&
                      &*be_3(:)*cV0(7,1,:)+133.d0*be_1(:)*be_4(:)*&
                      &cV0(7,1,:)+80.d0*be_2(:)**2*cV0(8,1,:)+160.d0*&
                      &be_1(:)*be_3(:)*cV0(8,1,:)+189.d0*be_1(:)*&
                      &be_2(:)*cV0(9,1,:)+110.d0*be_1(:)**2*cV0(10,1,:)&
                      &)/24.d0
        cV0(12,4,:) = (-117.d0*be_3(:)*be_4(:)**2*cV0(1,1,:)-278.d0*&
                      &be_3(:)**2*be_4(:)*cV0(2,1,:)-280.d0*be_2(:)*&
                      &be_4(:)**2*cV0(2,1,:)-162.d0*be_3(:)**3*&
                      &cV0(3,1,:)-978.d0*be_2(:)*be_3(:)*be_4(:)*&
                      &cV0(3,1,:)-495.d0*be_1(:)*be_4(:)**2*cV0(3,1,:)-&
                      &748.d0*be_2(:)*be_3(:)**2*cV0(4,1,:)-752.d0*&
                      &be_2(:)**2*be_4(:)*cV0(4,1,:)-1512.d0*be_1(:)*&
                      &be_3(:)*be_4(:)*cV0(4,1,:)-1065.d0*be_2(:)**2*&
                      &be_3(:)*cV0(5,1,:)-1070.d0*be_1(:)*be_3(:)**2*&
                      &cV0(5,1,:)-2150.d0*be_1(:)*be_2(:)*be_4(:)*&
                      &cV0(5,1,:)-480.d0*be_2(:)**3*cV0(6,1,:)-2892.d0*&
                      &be_1(:)*be_2(:)*be_3(:)*cV0(6,1,:)-1458.d0*&
                      &be_1(:)**2*be_4(:)*cV0(6,1,:)-1883.d0*be_1(:)*&
                      &be_2(:)**2*cV0(7,1,:)-1890.d0*be_1(:)**2*&
                      &be_3(:)*cV0(7,1,:)-2392.d0*be_1(:)**2*be_2(:)*&
                      &cV0(8,1,:)-990.d0*be_1(:)**3*cV0(9,1,:))/192.d0
        cV0(12,5,:) = (910.d0*be_2(:)*be_3(:)**3*cV0(1,1,:)+2795.d0*&
                      &be_2(:)**2*be_3(:)*be_4(:)*cV0(1,1,:)+2860.d0*&
                      &be_1(:)*be_3(:)**2*be_4(:)*cV0(1,1,:)+2925.d0*&
                      &be_1(:)*be_2(:)*be_4(:)**2*cV0(1,1,:)+3626.d0*&
                      &be_2(:)**2*be_3(:)**2*cV0(2,1,:)+2464.d0*be_1(:)&
                      &*be_3(:)**3*cV0(2,1,:)+2464.d0*be_2(:)**3*&
                      &be_4(:)*cV0(2,1,:)+15064.d0*be_1(:)*be_2(:)*&
                      &be_3(:)*be_4(:)*cV0(2,1,:)+3906.d0*be_1(:)**2*&
                      &be_4(:)**2*cV0(2,1,:)+4635.d0*be_2(:)**3*be_3(:)&
                      &*cV0(3,1,:)+14130.d0*be_1(:)*be_2(:)*be_3(:)**2*&
                      &cV0(3,1,:)+14355.d0*be_1(:)*be_2(:)**2*be_4(:)*&
                      &cV0(3,1,:)+14580.d0*be_1(:)**2*be_3(:)*be_4(:)*&
                      &cV0(3,1,:)+1920.d0*be_2(:)**4*cV0(4,1,:)+&
                      &23360.d0*be_1(:)*be_2(:)**2*be_3(:)*cV0(4,1,:)+&
                      &11840.d0*be_1(:)**2*be_3(:)**2*cV0(4,1,:)+&
                      &24000.d0*be_1(:)**2*be_2(:)*be_4(:)*cV0(4,1,:)+&
                      &11815.d0*be_1(:)*be_2(:)**3*cV0(5,1,:)+35870.d0*&
                      &be_1(:)**2*be_2(:)*be_3(:)*cV0(5,1,:)+12240.d0*&
                      &be_1(:)**3*be_4(:)*cV0(5,1,:)+25650.d0*&
                      &be_1(:)**2*be_2(:)**2*cV0(6,1,:)+17280.d0*&
                      &be_1(:)**3*be_3(:)*cV0(6,1,:)+23674.d0*&
                      &be_1(:)**3*be_2(:)*cV0(7,1,:)+7920.d0*be_1(:)**4&
                      &*cV0(8,1,:))/1920.d0
        cV0(12,6,:) = (-6555.d0*be_2(:)**4*be_3(:)*cV0(1,1,:)-41116.d0*&
                      &be_1(:)*be_2(:)**2*be_3(:)**2*cV0(1,1,:)-&
                      &14304.d0*be_1(:)**2*be_3(:)**3*cV0(1,1,:)-&
                      &28634.d0*be_1(:)*be_2(:)**3*be_4(:)*cV0(1,1,:)-&
                      &89514.d0*be_1(:)**2*be_2(:)*be_3(:)*be_4(:)*&
                      &cV0(1,1,:)-16146.d0*be_1(:)**3*be_4(:)**2*&
                      &cV0(1,1,:)-3840.d0*be_2(:)**5*cV0(2,1,:)-&
                      &79620.d0*be_1(:)*be_2(:)**3*be_3(:)*cV0(2,1,:)-&
                      &123680.d0*be_1(:)**2*be_2(:)*be_3(:)**2*&
                      &cV0(2,1,:)-128010.d0*be_1(:)**2*be_2(:)**2*&
                      &be_4(:)*cV0(2,1,:)-88200.d0*be_1(:)**3*be_3(:)*&
                      &be_4(:)*cV0(2,1,:)-41205.d0*be_1(:)*be_2(:)**4*&
                      &cV0(3,1,:)-254640.d0*be_1(:)**2*be_2(:)**2*&
                      &be_3(:)*cV0(3,1,:)-87360.d0*be_1(:)**3*&
                      &be_3(:)**2*cV0(3,1,:)-179742.d0*be_1(:)**3*&
                      &be_2(:)*be_4(:)*cV0(3,1,:)-149860.d0*be_1(:)**2*&
                      &be_2(:)**3*cV0(4,1,:)-307296.d0*be_1(:)**3*&
                      &be_2(:)*be_3(:)*cV0(4,1,:)-80640.d0*be_1(:)**4*&
                      &be_4(:)*cV0(4,1,:)-246620.d0*be_1(:)**3*&
                      &be_2(:)**2*cV0(5,1,:)-126000.d0*be_1(:)**4*&
                      &be_3(:)*cV0(5,1,:)-189564.d0*be_1(:)**4*be_2(:)*&
                      &cV0(6,1,:)-55440.d0*be_1(:)**5*cV0(7,1,:))/&
                      &23040.d0
        cV0(12,7,:) = (45045.d0*be_1(:)*be_2(:)**5*cV0(1,1,:)+484120.d0&
                      &*be_1(:)**2*be_2(:)**3*be_3(:)*cV0(1,1,:)+&
                      &518336.d0*be_1(:)**3*be_2(:)*be_3(:)**2*&
                      &cV0(1,1,:)+554372.d0*be_1(:)**3*be_2(:)**2*&
                      &be_4(:)*cV0(1,1,:)+294840.d0*be_1(:)**4*be_3(:)*&
                      &be_4(:)*cV0(1,1,:)+382130.d0*be_1(:)**2*&
                      &be_2(:)**4*cV0(2,1,:)+1617112.d0*be_1(:)**3*&
                      &be_2(:)**2*be_3(:)*cV0(2,1,:)+426720.d0*&
                      &be_1(:)**4*be_3(:)**2*cV0(2,1,:)+899892.d0*&
                      &be_1(:)**4*be_2(:)*be_4(:)*cV0(2,1,:)+1189440.d0&
                      &*be_1(:)**3*be_2(:)**3*cV0(3,1,:)+1868580.d0*&
                      &be_1(:)**4*be_2(:)*be_3(:)*cV0(3,1,:)+408240.d0*&
                      &be_1(:)**5*be_4(:)*cV0(3,1,:)+1744736.d0*&
                      &be_1(:)**4*be_2(:)**2*cV0(4,1,:)+725760.d0*&
                      &be_1(:)**5*be_3(:)*cV0(4,1,:)+1225020.d0*&
                      &be_1(:)**5*be_2(:)*cV0(5,1,:)+332640.d0*&
                      &be_1(:)**6*cV0(6,1,:))/322560.d0
        cV0(12,8,:) = (-785785.d0*be_1(:)**3*be_2(:)**4*cV0(1,1,:)-&
                      &2615214.d0*be_1(:)**4*be_2(:)**2*be_3(:)*&
                      &cV0(1,1,:)-576240.d0*be_1(:)**5*be_3(:)**2*&
                      &cV0(1,1,:)-1266576.d0*be_1(:)**5*be_2(:)*&
                      &be_4(:)*cV0(1,1,:)-2934176.d0*be_1(:)**4*&
                      &be_2(:)**3*cV0(2,1,:)-3819360.d0*be_1(:)**5*&
                      &be_2(:)*be_3(:)*cV0(2,1,:)-740880.d0*be_1(:)**6*&
                      &be_4(:)*cV0(2,1,:)-4454634.d0*be_1(:)**5*&
                      &be_2(:)**2*cV0(3,1,:)-1587600.d0*be_1(:)**6*&
                      &be_3(:)*cV0(3,1,:)-3115320.d0*be_1(:)**6*&
                      &be_2(:)*cV0(4,1,:)-831600.d0*be_1(:)**7*&
                      &cV0(5,1,:))/2580480.d0
        cV0(12,9,:) = (3694405.d0*be_1(:)**5*be_2(:)**3*cV0(1,1,:)+&
                      &4261140.d0*be_1(:)**6*be_2(:)*be_3(:)*&
                      &cV0(1,1,:)+786240.d0*be_1(:)**7*be_4(:)*&
                      &cV0(1,1,:)+7569954.d0*be_1(:)**6*be_2(:)**2*&
                      &cV0(2,1,:)+2419200.d0*be_1(:)**7*be_3(:)*&
                      &cV0(2,1,:)+5920380.d0*be_1(:)**7*be_2(:)*&
                      &cV0(3,1,:)+1663200.d0*be_1(:)**8*cV0(4,1,:))/&
                      &23224320.d0
        cV0(12,10,:)= (-749463.d0*be_1(:)**7*be_2(:)**2*cV0(1,1,:)-&
                      &226800.d0*be_1(:)**8*be_3(:)*cV0(1,1,:)-&
                      &842620.d0*be_1(:)**8*be_2(:)*cV0(2,1,:)-&
                      &277200.d0*be_1(:)**9*cV0(3,1,:))/25804800.d0
        cV0(12,11,:)= (55991.d0*be_1(:)**9*be_2(:)*cV0(1,1,:)+&
                      &27720.d0*be_1(:)**10*cV0(2,1,:))/28385280.d0
        cV0(12,12,:)= -be_1(:)**11*cV0(1,1,:)/24576.d0

      return
      end subroutine init_cVA0nk

      end module cVA0_depen
