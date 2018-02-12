clean:
	rm -rf *.o target

clean-build: clean target

target:spies_tool.o
	gcc -o target spies_tool.o

spies_tool.o: spies_tool.c
	gcc -c spies_tool.c
