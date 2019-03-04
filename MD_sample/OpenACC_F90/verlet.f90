subroutine verlet_1(dt)
!$acc routine
  use md
  implicit none
  integer(gi):: i, k
  real   (gp):: dt
  !$acc loop gang private(i,k)
  do i=1, N3
     k = i/3 + 1
     xx(i) = xx(i) + dt*vv(i) + 0.5_gp*dt*dt*ff(i)/xm(k)
     xx(i) = xx(i) - l_box*dnint(xx(i)/l_box)
     vv(i) = vv(i) + 0.5_gp*dt*ff(i)/xm(k)
  end do
  return
end subroutine verlet_1
!
!################################################################
subroutine verlet_2(dt)
!$acc routine
  use md
  implicit none
  integer(gi):: i, k
  real   (gp):: dt
  !$acc loop gang private(i,k)
  do i=1, N3
     k = i/3 + 1
     vv(i) = vv(i) + 0.5_gp*dt*ff(i)/xm(k)
  end do
  return
end subroutine verlet_2

