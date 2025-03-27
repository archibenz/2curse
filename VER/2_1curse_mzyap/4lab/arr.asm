section .data
    result_msg db "Result: ", 0
    result_msg_len equ $ - result_msg
    file_error_msg db "File error!", 0
    file_error_len equ $ - file_error_msg
    input_error_msg db "Invalid input!", 0
    input_error_len equ $ - input_error_msg
    array_full_msg db "Array is full!", 0
    array_full_len equ $ - array_full_msg
    parse_error_msg db "Parse error!", 0
    parse_error_len equ $ - parse_error_msg
    newline db 10
    arg_msg db "Arg: ", 0
    arg_msg_len equ $ - arg_msg

section .bss
    fd resq 1                ; файловый дескриптор
    buffer resb 4096         ; буфер для чтения данных
    buffer_size equ 4096     ; размер буфера
    product resq 1           ; переменная для произведения
    array resw 1000          ; массив для чисел (максимум 1000 элементов)
    lower_bound resd 1       ; нижний предел
    upper_bound resd 1       ; верхний предел

section .text
    global _start

    %define SYS_OPEN 2
    %define SYS_READ 0
    %define SYS_WRITE 1
    %define SYS_EXIT 60
    %define O_RDONLY 0

_start:
    ; Проверка количества аргументов
    mov rdi, [rsp+8] ; Количество аргументов
    cmp rdi, 4       ; Должно быть 4 аргумента: программа, файл, c, d
    jne input_error

    ; Отладка аргументов
    mov rsi, [rsp+16] ; Имя файла
    mov rdi, arg_msg
    call print_string
    mov rdi, rsi
    call print_string

    mov rsi, [rsp+24] ; Нижний предел
    mov rdi, arg_msg
    call print_string
    mov rdi, rsi
    call print_string

    mov rsi, [rsp+32] ; Верхний предел
    mov rdi, arg_msg
    call print_string
    mov rdi, rsi
    call print_string

    ; Открытие файла
    mov rsi, [rsp+16] ; Имя файла
    mov rax, SYS_OPEN
    mov rdi, rsi
    mov rsi, O_RDONLY
    syscall
    js file_error
    mov [fd], rax ; Сохранение файлового дескриптора

    ; Проверка открытия файла
    mov rdi, result_msg
    call print_string

    ; Считывание нижнего предела (c)
    mov rdi, [rsp+24]
    call parse_int
    mov dword [lower_bound], eax

    ; Считывание верхнего предела (d)
    mov rdi, [rsp+32]
    call parse_int
    mov dword [upper_bound], eax

    ; Инициализация
    mov qword [product], 1 ; Инициализация произведения
    xor r13d, r13d         ; Текущий индекс массива

    ; Здесь продолжается основная логика программы...

file_error:
    mov rdi, file_error_msg
    mov rsi, file_error_len
    call print_string
    jmp exit_program

input_error:
    mov rdi, input_error_msg
    mov rsi, input_error_len
    call print_string
    jmp exit_program

exit_program:
    mov rax, SYS_EXIT
    xor rdi, rdi
    syscall

print_string:
    ; Функция для вывода строки
    mov rax, SYS_WRITE      ; системный вызов write
    mov rdi, 1              ; дескриптор stdout
    mov rdx, arg_msg_len    ; длина строки
    syscall
    ret

parse_int:
    ; Реализация функции parse_int для преобразования строки в число
    xor eax, eax          ; Обнуляем результат
    xor ecx, ecx          ; Временный регистр для текущего символа
    xor edx, edx          ; Флаг отрицательного числа
    mov r8, 0             ; Счетчик байтов

.skip_whitespace:
    mov cl, byte [rdi]    ; Читаем текущий символ
    cmp cl, ' '           ; Пропускаем пробелы
    jne .check_sign
    inc rdi
    inc r8
    jmp .skip_whitespace

.check_sign:
    cmp cl, '-'
    jne .parse_digits
    inc rdi
    inc r8
    mov dl, 1             ; Устанавливаем флаг отрицательного числа

.parse_digits:
    mov cl, byte [rdi]
    sub cl, '0'           ; Преобразуем символ в число
    jl .done              ; Если символ меньше '0', завершаем
    cmp cl, 9
    jg .done              ; Если символ больше '9', завершаем
    imul eax, eax, 10     ; Умножаем результат на 10
    add eax, ecx          ; Добавляем цифру к результату
    inc rdi
    inc r8
    jmp .parse_digits

.done:
    test dl, dl
    jz .return_result
    neg eax               ; Если число отрицательное, меняем знак

.return_result:
    ret

