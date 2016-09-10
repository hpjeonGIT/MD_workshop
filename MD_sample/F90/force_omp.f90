!
! Parallel force-field routine
!##################################################
subroutine force_omp
  use md
  implicit none
  !
  integer(di):: i, j, ierr
  real   (dp):: r2, dx(3), coef
  real   (dp), allocatable:: tmp(:,:)
  !
  ! Initialization of force components
  do i=1_di, Npt
     q(i)%ff(:) = 0.0_dp
  end do
  !
  ! Force update
  !$omp parallel &
  !$omp default(shared) private(tmp, ierr)
  allocate(tmp(3_di,Npt), stat=ierr)
  tmp(:,:) = 0.0_dp
  !$omp do private(i,j, r2,dx,coef)&
  !$omp schedule(dynamic)
  do i=1_di, Npt-1_di
     do j=i+1_di, Npt
        !
        r2 = 0.0_dp
        dx(:) = q(i)%xx(:) - q(j)%xx(:)
        dx(:) = dx(:) - l_box*dnint(dx(:)/l_box)
        r2 = r2 + dx(1)*dx(1) + dx(2)*dx(2) + dx(3)*dx(3)
        coef = 1.0_dp/r2/dsqrt(r2)
        !
        tmp(:,i) = tmp(:,i) + coef*dx(:)
        tmp(:,j) = tmp(:,j) - coef*dx(:)
     end do
  end do
  !$omp end do
  !$omp critical
  do i=1_di, Npt
     q(i)%ff(:) = q(i)%ff(:) + tmp(:,i)
  end do
  !$omp end critical
  deallocate(tmp, stat=ierr)
  !$omp end parallel
  return
end subroutine force_omp
