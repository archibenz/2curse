all: program

program: asm_signed.o asm_unsigned.o input_output.o
	ld -m elf_i386 -o program asm_signed.o asm_unsigned.o input_output.o

asm_signed.o: asm_signed.asm
	nasm -f elf32 -g -F dwarf asm_signed.asm -o asm_signed.o

asm_unsigned.o: asm_unsigned.asm
	nasm -f elf32 -g -F dwarf asm_unsigned.asm -o asm_unsigned.o

input_output.o: input_output.asm
	nasm -f elf32 -g -F dwarf input_output.asm -o input_output.o

clean:
	rm -f *.o program

