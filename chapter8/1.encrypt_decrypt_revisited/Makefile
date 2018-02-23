encryption-decryption-tool: encryption-decryption-tool.o encrypt.o checksum.o libsecurity
	gcc encryption-decryption-tool.o -L ./locallib/ -l security -o encryption-decryption-tool

createdirectory:
	mkdir -p  locallib

encrypt.o: encrypt.c encrypt.h createdirectory
	gcc -c encrypt.c  -fPIC -o ./locallib/encrypt.o

checksum.o: checksum.c checksum.h createdirectory
	gcc -c  checksum.c -o ./locallib/checksum.o -I ./

libsecurity: checksum.o encrypt.o createdirectory
	#ar -rsc ./locallib/libsecurity.a ./locallib/checksum.o ./locallib/encrypt.o
	#This changes the library to a dynamically linked library also known as a shared object.
	#To use a dynamically linked library we need to export LD_LIBRARY_PATH variable after adding to it the path of the directory which holds the library.
	gcc -shared ./locallib/checksum.o ./locallib/encrypt.o -o ./locallib/libsecurity.so

encryption-decryption-tool.o: encryption-decryption-tool.c
	gcc -c encryption-decryption-tool.c -o encryption-decryption-tool.o

clean:
	rm -rf *.o *.a locallib
