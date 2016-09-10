# Makfile to compile MD example
.SUFFIXES: .o .f90
FC = gfortran
FLAGS = -O2 -g 
LIB = -lm
FOMP = -fopenmp
INCLUDE =
OBJ = md.o main.o force.o force_omp.o verlet.o print_snap.o
TRG = md_run
${TRG}: ${OBJ}
	${FC} ${FLAGS} ${FOMP} -o ${TRG} ${OBJ} ${LIB}
main.o:main.f90
	${FC} ${FLAGS} ${FOMP} -c $<
force_omp.o:force_omp.f90
	${FC} ${FLAGS} ${FOMP} -c $<
.f90.o:
	${FC} ${FLAGS} -c $<
clean:
	rm ${OBJ} ${TRG} md.mod *~
