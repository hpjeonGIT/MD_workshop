# example for foo
.SUFFIXES: .o .f90
FC = pgf90
FLAGS = -fast  # -debug -p  # -O3 -ansi 
FACC = -acc -Minfo=accel #-openmp
LIB = 
INCLUDE = 
OBJT = md.o force.o verlet.o print_snap.o main.o
TARG = md_sample
${TARG}: ${OBJT}
	${FC} ${FLAGS} ${FACC} -o ${TARG} ${OBJT} ${LIB}
main.o:main.f90
	${FC} ${FLAGS} ${FACC} -c $<
md.o:md.f90
	${FC} ${FLAGS} ${FACC} -c $<
force.o:force.f90
	${FC} ${FLAGS} ${FACC} -c $<
verlet.o:verlet.f90
	${FC} ${FLAGS} ${FACC} -c $<
.f90.o:
	${FC} ${FLAGS} -c $<
clean:
	rm ${OBJT} ${TARG} md.mod *~
