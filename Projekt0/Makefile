all:

release: release2
	gcc main.o -o program
release2:
	gcc -c  main.c
debug: debug2
	gcc main.o -o program
debug2:
	gcc -g -c main.c
clean:
	-rm *o program
