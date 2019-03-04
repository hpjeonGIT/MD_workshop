ubroutine print_snap(isnap)
  use md
  implicit none
  integer(gi):: isnap, i, k
  character(256):: fname
  write(fname,10) isnap
10 format("snapshot",I5.5,".xyz")
  open(unit=20, file=fname, ACTION="WRITE")
  write(20,*) N
  write(20,*) "Header here"
  do i=1, N3, 3
     write(20,30) "O ", (xx(i+k), k=0,2)
  end do
30 format (A3, 3(1X, ES11.4))
  close(20)
  return
end subroutine print_snap
