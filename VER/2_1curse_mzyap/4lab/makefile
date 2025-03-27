all:
	nasm -f elf64 -F dwarf -g arr.asm -o arr.o
	ld -m elf_x86_64 -o program arr.o
	./program input.txt

clean:
	rm -f *.o program
