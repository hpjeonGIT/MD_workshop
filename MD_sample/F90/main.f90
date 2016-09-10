Program MD_F90
  use md
  use omp_lib
  implicit none
  !
  integer(di):: i, ierr
  real   (dp):: dt
  !
  ! Initial setup
  dt = 0.1_dp
  allocate(q(Npt), stat=ierr)  
  call data_read
  !
  !$omp parallel
  !$omp master
  print '("### No. of OMP threads = ", I3)', omp_get_num_threads()
  !$omp end master
  !$omp end parallel
  !
  ! MD time integration
  i = 0_di
  do while (i <= 1000_di)
     call verlet_1(dt)
     ! call force
     call force_omp 
     call verlet_2(dt)
     i = i + 1_di
     if (mod(i,100_di) == 0_di) call print_snap(i)
  end do
  !
  ! Empty dynamic memory
  deallocate(q, stat=ierr)
end Program MD_F90
!
!####################################################
subroutine data_read
  use md
  implicit none
  integer(di):: i, k
  real   (dp):: x
  !
  do i=1_di, Npt
     do k=1_di, 3_di
        call random_number(x)
        q(i)%xx(k) = (x - 0.5_dp) * l_box
     end do
     q(i)%vv(:) = 0.0_dp
     q(i)%ff(:) = 0.0_dp
     q(i)%xm    = mass
  end do
  return
end subroutine data_read
