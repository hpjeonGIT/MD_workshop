!
! Serial force-field routine
!##################################################
subroutine force
  use md
  implicit none
  !
  integer(di):: i, j
  real   (dp):: r2, dx(3), coef
  !
  ! Initialization of force components
  do i=1_di, Npt
     q(i)%ff(:) = 0.0_dp
  end do
  !
  ! Force update
  do i=1_di, Npt-1_di
     do j=i+1_di, Npt
        !
        r2 = 0.0_dp
        dx(:) = q(i)%xx(:) - q(j)%xx(:)
        dx(:) = dx(:) - l_box*dnint(dx(:)/l_box)
        r2 = r2 + dx(1)*dx(1) + dx(2)*dx(2) + dx(3)*dx(3)
        coef = 1.0_dp/r2/dsqrt(r2)
        q(i)%ff(:) = q(i)%ff(:) + coef * dx(:)
        q(j)%ff(:) = q(j)%ff(:) - coef * dx(:)
     end do
  end do
  return
end subroutine force
