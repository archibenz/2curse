all:  
	gcc -m64 -c -g -o main.o main.c  
	nasm -f elf64 signed_int.asm -o signed_int.o
	nasm -f elf64 unsigned_int.asm -o unsigned_int.o
	gcc -m64 -no-pie -o program main.o signed_int.o unsigned_int.o 

clean:
	rm -f *.o program
