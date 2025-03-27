all:  
	gcc -m64 -c -g -o main.o main.c  # Добавляем флаг -m64 для компиляции main.c
	nasm -f elf64 asm_signed.asm -o asm_signed.o
	nasm -f elf64 asm_unsigned.asm -o asm_unsigned.o
	gcc -m64 -no-pie -o program main.o asm_signed.o asm_unsigned.o  # Флаг -m64 и -no-pie для линковки

clean:
	rm -f *.o program