# example for foo
.SUFFIXES: .o .cc
CXX = g++
FLAGS = -O3 -ansi
LIB = -lm 
INCLUDE = 
OBJT = main.o force.o verlet.o
TARG = md_sample
${TARG}: ${OBJT}
	${CXX} ${FLAGS} -o ${TARG} ${OBJT} ${LIB}
.cc.o:
	${CXX} ${FLAGS} -c $<
clean:
	rm ${OBJT} ${TARG} *~

