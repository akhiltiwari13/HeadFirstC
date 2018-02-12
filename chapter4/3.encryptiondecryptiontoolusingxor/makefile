encrypt.o: encrypt.c encrypt.h
	gcc -c encrypt.c
encryption-decryption-tool.o: encryption-decryption-tool.c
	gcc -c encryption-decryption-tool.c
encryption-decryption-tool: encryption-decryption-tool.o encrypt.o
	gcc encryption-decryption-tool.o encrypt.o -o encryption-decryption-tool

