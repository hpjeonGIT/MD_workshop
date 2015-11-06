# example for foo
.SUFFIXES: .o .cc
CXX = g++
FLAGS = -O3 -ansi
LIB = -lm 
INCLUDE = 
OBJT = math_1.o math_2.o math_3.o
TARG = b.out
${TARG}: ${OBJT}
	${CXX} ${FLAGS} -o ${TARG} ${OBJT} ${LIB}
.cc.o:
	${CXX} ${FLAGS} -c $<
clean:
	rm ${OBJT} ${TARG}
