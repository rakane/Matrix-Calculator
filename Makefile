link: lib compile
	gcc src/main.o -L. src/libmatrix.a src/libmatrixdriver.a -o calculator
	gcc test/check_matrix.o -L. src/libmatrix.a src/libmatrixdriver.a -o check `pkg-config --cflags --libs check`
lib:
	gcc -c src/matrix.c -o src/matrix.o
	gcc -c src/matrixdriver.c -o src/matrixdriver.o
	mv src/matrix.o src/libmatrix.a
	mv src/matrixdriver.o src/libmatrixdriver.a
compile:
	gcc -c src/main.c -o src/main.o
	gcc -c test/check_matrix.c -o test/check_matrix.o
clean:
	rm src/libmatrix.a
	rm src/libmatrixdriver.a
	rm src/main.o
	rm test/check_matrix.o
	rm calculator
	rm check
