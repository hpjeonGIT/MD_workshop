module md
  implicit none
  !http://fortranwiki.org/fortran/show/Real+precision
  integer, parameter:: si = selected_int_kind(4)
  integer, parameter:: di = selected_int_kind(8)
  integer, parameter:: sp = kind(1.0)
  integer, parameter:: dp = kind(1.0d0)
  integer(di), parameter:: Npt=1000
  real   (dp), parameter:: rcut = 9.0_dp, rcut2 = rcut*rcut, l_box = 20.0_dp, &
       & mass = 10.0_dp
  type particle
     real(dp):: xx(3), vv(3), ff(3), xm
  end type particle
  !
  type(particle), allocatable:: q(:)
  !
end module md

