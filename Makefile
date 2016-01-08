cpp=g++ -g

all: bf

bf: bf.o
	${cpp} bf.o -o bf

bf.o: bf.cpp
	${cpp} -c bf.cpp -o bf.o

clean:
	rm -rf bf *.o

test: bf
	./test/test.sh
