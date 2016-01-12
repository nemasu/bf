cpp=g++

all: cpp += -O2
all: bf strip

static: cpp += -static
static: all

debug: cpp += -g
debug: bf

bf: bf.o
	${cpp} bf.o -o bf

bf.o: bf.cpp
	${cpp} -c bf.cpp -o bf.o

clean:
	rm -rf bf *.o

test: bf
	./test/test.sh

strip: bf
	@strip --strip-all bf
	@strip --strip-debug bf
