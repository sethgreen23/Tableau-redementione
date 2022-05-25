all: test.exe main.exe stats.exe
	echo "it is completed"

stats.exe: intarray.o tools.o stats.o
	gcc intarray.o tools.o stats.o -o stats.exe

main.exe: intarray.o tools.c main.o
	gcc intarray.o tools.o main.o -o main.exe

test.exe: intarray.o tools.o test.o
	gcc intarray.o tools.o test.o -o test.exe

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