Program MD_fortran
  use md
  implicit none
  !
  integer(gi):: i, ierr
  real   (gp):: dt
  !
  ! initialize
  dt = 0.1_gp
  allocate(xx(N3),vv(N3),ff(N3),xm(N), stat=ierr)
  call data_read
  !
  ! Loop starts
  i = 0
  !$acc data copyin(xx(1:N3),vv(1:N3),xm(1:N),dt) copyout(ff(1:N3),sys_energy)
  do while(i<=100)
     call verlet_1(dt)
     call force()
     call verlet_2(dt)
     i = i + 1
     !if (mod(i,10) ==0) call print_snap(i)
     !print *, sys_energy
  end do
  !$acc end data
  !call print_snap(i)
  print *, sys_energy
  print *, xx(1), vv(1), ff(1), xm(1)
  
  ! Finish
  deallocate(xx, vv, ff, xm, stat=ierr)
  !
end Program
!
!##################################################
subroutine data_read
  use md
  implicit none
  integer(gi):: i, k
  real   (dp):: x
  !
  do i=1, N3
     call random_number(x)
     xx(i) = (x - 0.5_gp)*l_box
     call random_number(x)
     vv(i) = (x - 0.5_gp)*0.001
     ff(i) = 0.0_gp
  end do
  xm(:) = mass
  return
end subroutine data_read
