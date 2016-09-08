# Makfile to compile MD example
.SUFFIXES: .o .cxx
CXX = g++
FLAGS = -g -ansi
LIB = -lm
FOMP = -fopenmp
INCLUDE =
OBJ = main.o force.o verlet.o print.o
TRG = md_run
${TRG}: ${OBJ}
	${CXX} ${FLAGS} ${FOMP} -o ${TRG} ${OBJ} ${LIB}
main.o:main.cxx
	${CXX} ${FLAGS} ${FOMP} -c $<
force.o:force.cxx
	${CXX} ${FLAGS} ${FOMP} -c $<
.cxx.o:
	${CXX} ${FLAGS} -c $<
clean:
	rm ${OBJ} ${TRG} *~
