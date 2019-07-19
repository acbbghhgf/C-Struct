src=.
src_c=${shell find $(src) -name "*.cpp"}
objs=$(patsubst %.cpp,%.o,$(src_c))

CC=g++
INC=-I . -I ./msgpack/include/ -I ./msgpack/ -I ./msgpack/include/msgpack
CFLAGS=${INC} -O -g #--fast-math -Ofast -Wall -funroll-loops -DUSE_BLAS
libasr=test

all: ${objs} $(libasr)
	echo ${objs} ${cpp_objs}

${libasr}: ${objs}
	${CC}  ${CFLAGS} $^ -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<;

clean:
	rm ${objs} ${libasr}
