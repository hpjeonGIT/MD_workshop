subroutine force
!$acc routine
  use md
  implicit none
  !
  integer(gi):: i, j, ierr
  real   (gp):: r2, dx,dy,dz, df, x, dE, dfx,dfy,dfz
  !
  ff(:) = 0.0_gp
  dE = 0.0_gp
  !
  !$acc loop gang private(i,j,r2,x,dx,dy,dz,df,dfx,dfy,dfz) reduction(+:dE)
  do i=1, N3,3
     !
     dfx = 0.0_gp; dfy = 0.0_gp; dfz = 0.0_gp
     !$acc loop vector reduction(+:dfx,dfy,dfz, dE)
     do j=1, N3,3
        !
        if (i /= j) then
           dx = xx(i-1) - xx(j-1)
           dx = dx - l_box * dnint(dx/l_box)
           dy = xx(i) - xx(j)
           dy = dy - l_box * dnint(dy/l_box)
           dz = xx(i+1) - xx(j+1)
           dz = dz - l_box * dnint(dz/l_box)
           r2 = dx*dx + dy*dy + dz*dz
           df = 1./r2**4
           dE = dE + 0.5/r2**3
           !
           dfx = dfx + df*dx
           dfy = dfy + df*dy
           dfz = dfz + df*dz
           !dE = dE + dz
           !print *, xx(i-1), xx(j-1), i-1,j-1
        end if
     end do
     ff(i-1)   = dfx
     ff(i+0) = dfy
     ff(i+1) = dfz
  end do
  sys_energy = dE
  !print*, dE
  return
end subroutine force
