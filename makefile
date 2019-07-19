src=./msgpack
src_c=${shell find $(src) -name "*.c"}
wtk=./wtk
wtk_c=${shell find $(wtk) -name "*.c"}
objs=$(patsubst %.c,%.o,$(src_c) $(wtk_c))

CC=gcc
INC=-I . -I ./msgpack/include/ -I ./msgpack/ -I ./msgpack/include/msgpack
CFLAGS=${INC} -O -g -rpath=. #--fast-math -Ofast -Wall -funroll-loops -DUSE_BLAS
libasr=test

all: ${objs} $(libasr)
	echo ${objs} ${cpp_objs}

${libasr}: test.o  ${objs}
	${CC}  ${CFLAGS} $^ -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<;
test.o : test.c# msg_test.c
	$(CC) $(CFLAGS) -c -o $@ $<;

clean:
	rm ${objs} test.o
