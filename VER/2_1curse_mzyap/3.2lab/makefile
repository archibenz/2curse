all: program

program: input_output.o
	ld -m elf_i386 -o program input_output.o

input_output.o: input_output.asm
	nasm -f elf32 -g -F dwarf input_output.asm -o input_output.o

clean:
	rm -f *.o program

