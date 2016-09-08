# Makfile to compile MD example
.SUFFIXES: .o .c
CXX = gcc
FLAGS = -O2 -g -ansi
LIB = -lm
FOMP = -fopenmp
INCLUDE =
OBJ = main.o force.o force_omp.o verlet.o print.o
TRG = md_run
${TRG}: ${OBJ}
	${CXX} ${FLAGS} ${FOMP} -o ${TRG} ${OBJ} ${LIB}
main.o:main.c
	${CXX} ${FLAGS} ${FOMP} -c $<
force_omp.o:force_omp.c
	${CXX} ${FLAGS} ${FOMP} -c $<
.c.o:
	${CXX} ${FLAGS} -c $<
clean:
	rm ${OBJ} ${TRG} *~
