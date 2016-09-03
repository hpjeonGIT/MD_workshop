# Makfile to compile MD example
.SUFFIXES: .o .c
CXX = gcc
FLAGS = -g -ansi
LIB = -lm
INCLUDE =
OBJ = main.o force.o verlet.o print.o
TRG = md_run
${TRG}: ${OBJ}
	${CXX} ${FLAGS} -o ${TRG} ${OBJ} ${LIB}
.c.o:
	${CXX} ${FLAGS} -c $<
clean:
	rm ${OBJ} ${TRG} *~
