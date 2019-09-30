link: lib compile
	gcc src/main.o -L. src/libmatrix.a
lib:
	gcc -c src/matrix.c -o src/matrix.o
	mv src/matrix.o src/libmatrix.a
compile:
	gcc -c src/main.c -o src/main.o
clean:
	rm *.out
	rm src/libmatrix.a
	rm src/main.o
