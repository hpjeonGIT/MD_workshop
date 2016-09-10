subroutine print_snap(isnap)
  use md
  implicit none
  integer(di):: isnap, i
  character(256):: fname
  write(fname, 10) isnap
10 format("snapshot", I5.5, ".xyz")
  open(unit=25, file=fname, ACTION="WRITE")
  write(25,*) Npt
  write(25,*) "Header"
  do i=1_di, Npt
     write(25,20), "C ", q(i)%xx(1:3)
  end do
20 format(A2, 3(1X, ES12.5))
  close(25)
  return
end subroutine print_snap
