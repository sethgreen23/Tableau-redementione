all: test.exe main.exe stats.exe jstl_test.exe
	echo "it is completed"

stats.exe: intarray.o tools.o stats.o
	gcc intarray.o tools.o stats.o -o stats.exe

main.exe: intarray.o tools.c main.o jstl.o
	gcc intarray.o tools.o main.o jstl.o -o main.exe

test.exe: tools.o test.o intarray.o
	gcc tools.o test.o intarray.o -o test.exe

jstl_test.exe: tools.o jstl_test.o jstl.o intarray.o
	gcc intarray.o tools.o jstl_test.o jstl.o -o jstl_test.exe

test.o: test.c intarray.h tools.h
	gcc -c test.c

main.o: main.c intarray.h tools.h
	gcc -c main.c

intarray.o: intarray.c intarray.h tools.h
	gcc -c intarray.c

tools.o: tools.c tools.h
	gcc -c tools.c

stats.o: stats.c intarray.h tools.h 
	gcc -c stats.c

jstl_test.o: jstl_test.c jstl.h tools.h intarray.h
	gcc -c jstl_test.c

jstl.o: jstl.c jstl.h tools.h intarray.h
	gcc -c jstl.c