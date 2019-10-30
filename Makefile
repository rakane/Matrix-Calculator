test: lib compile
	gcc test/check_matrix.o -L. libmatrix.a -o check `pkg-config --cflags --libs check`
lib:
	gcc -c matrix.c -o matrix.o
	mv matrix.o libmatrix.a
compile:
	gcc -c test/check_matrix.c -o test/check_matrix.o
clean:
	rm libmatrix.a
	rm test/check_matrix.o
	rm check
