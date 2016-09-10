!
! 1st step of Velocity Verlet time integration
!############################################################
subroutine verlet_1(dt)
  use md
  implicit none
  integer(di):: i
  real   (dp):: dt
  !
  do i=1_di, Npt
     q(i)%xx(:) = q(i)%xx(:) + dt*q(i)%vv(:) + 0.5_dp*dt*dt*q(i)%ff(:)/q(i)%xm
     q(i)%xx(:) = q(i)%xx(:) - l_box*dnint(q(i)%xx(:)/l_box)
     q(i)%vv(:) = q(i)%vv(:) + 0.5_dp*dt*q(i)%ff(:)/q(i)%xm
  end do
  return
end subroutine verlet_1
!
! 2nd step of Velocity Verlet time integration
!############################################################
subroutine verlet_2(dt)
  use md
  implicit none
  integer(di):: i
  real   (dp):: dt
  !
  do i=1_di, Npt
     q(i)%vv(:) = q(i)%vv(:) + 0.5_dp*dt*q(i)%ff(:)/q(i)%xm
  end do
  return
end subroutine verlet_2

