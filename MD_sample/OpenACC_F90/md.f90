module md
  implicit none
  !http://fortranwiki.org/fortran/show/Real+precision
  integer,     parameter:: si = selected_int_kind(4)
  integer,     parameter:: di = selected_int_kind(8)
  integer,     parameter:: gi = di
  integer,     parameter:: sp = kind(1.0)
  integer,     parameter:: dp = kind(1.0d0)
  integer,     parameter:: gp = dp
  integer(gi), parameter:: N = 1000
  real   (gp), parameter:: rcut = 9.0_gp, l_box = 20.0_gp, mass = 10.0_gp
  !
  integer(gi):: N3 = N*3_gi
  real(gp),allocatable:: xx(:), vv(:), ff(:), xm(:)
  real(gp):: sys_energy
  !$acc declare create(xx,ff,rcut,l_box,mass,vv,xm,sys_energy, N3)  
  !
end module md
