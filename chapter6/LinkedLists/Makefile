
debug: main.o functions.o
	gcc -g -o target main.o functions.o

target: main.o functions.o
	gcc -o target main.o functions.o

main.o: main.c island_node.h
	gcc -c  main.c

functions.o: functions.c island_node.h
	gcc -c  functions.c

clean:
	rm -rf *.o target

clean-build: clean target
