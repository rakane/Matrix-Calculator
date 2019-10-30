link: lib compile
	gcc calculator.o -L. libmatrix.a libmatrixdriver.a -o calculator
lib:
	gcc -c ../../matrix.c -o matrix.o
	gcc -c matrixDriver.c -o matrixdriver.o
	mv matrix.o libmatrix.a
	mv matrixdriver.o libmatrixdriver.a
compile:
	gcc -c calculator.c -o calculator.o
clean:
	rm libmatrix.a
	rm libmatrixdriver.a
	rm calculator.o
	rm calculator
