PWD = $(pwd)
SRC=${shell find ${PWD} -name '*.c'}
OBJ=$(patsubst %.c, %.o, ${SRC})

CC=gcc
INC=-I .
CFLAGS=${INC} -O -g
object=test

all:${object} ${OBJ}
	echo ${OBJ}

${object}:${OBJ}
	${CC} ${CFLAGS} $^ -o $@

#${OBJ}:${SRC}
#	${CC} ${CFLAGS} -c -o $@ $<
%.o:%.c
	${CC} ${CFLAGS} -c -o $@ $<

clean:
	rm ${OBJ} ${object}
