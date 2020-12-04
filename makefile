all: main.o
	gcc -o program main.c
main.o:
	gcc -c main.c
clean:
	rm *.o
run:
	./program
