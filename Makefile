link: lib compile
	gcc src/main.o -L. src/libmatrix.a src/libmatrixdriver.a
lib:
	gcc -c src/matrix.c -o src/matrix.o
	gcc -c src/matrixdriver.c -o src/matrixdriver.o
	mv src/matrix.o src/libmatrix.a
	mv src/matrixdriver.o src/libmatrixdriver.a
compile:
	gcc -c src/main.c -o src/main.o
clean:
	rm *.out
	rm src/libmatrix.a
	rm src/main.o
