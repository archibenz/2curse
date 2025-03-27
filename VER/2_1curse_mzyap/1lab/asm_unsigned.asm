section .data
    extern a_uint
    extern b_uint
    extern c_uint
    extern numerator_uint
    extern denominator_uint
    extern result_uint

section .text
    global compute_unsigned_int

compute_unsigned_int:
    ; Загружаем b_uint в eax с нулевым расширением до 32 бит
    movzx eax, word [b_uint]     ; eax = b_uint
    ; Загружаем c_uint в ecx с нулевым расширением до 32 бит
    movzx ecx, word [c_uint]     ; ecx = c_uint

    ; Беззнаковое умножение b_uint * c_uint
    mul ecx                      ; edx:eax = eax * ecx

    ; Сохраняем результат умножения в ebx
    mov ebx, eax                 ; ebx = результат умножения

    ; Загружаем a_uint в ecx с нулевым расширением до 32 бит
    movzx ecx, word [a_uint]     ; ecx = a_uint

    ; Подготовка к делению 8 / a_uint
    mov eax, 8                   ; eax = 8
    xor edx, edx                 ; edx = 0 (очищаем старшие 32 бита)

    ; Проверяем деление на ноль
    cmp ecx, 0
    je division_by_zero_error

    ; Выполняем **беззнаковое деление**: 8 / a_uint
    div ecx                      ; eax = 8 / a_uint

    ; Вычитаем результат деления из результата умножения
    sub ebx, eax                 ; ebx = (b_uint * c_uint) - (8 / a_uint)

    ; Сохраняем числитель
    mov [numerator_uint], ebx

    ; Вычисляем знаменатель: 31 + b_uint - 1
    movzx eax, word [b_uint]
    add eax, 30                  ; eax = 31 + b_uint - 1

    ; Сохраняем знаменатель
    mov [denominator_uint], eax

    ; Проверяем деление на ноль
    cmp eax, 0
    je division_by_zero_error

    ; Загружаем числитель в eax для деления
    mov eax, [numerator_uint]    ; eax = числитель

    ; ПОДГОТОВКА К ЗНАКОВОМУ ДЕЛЕНИЮ
    ; Расширяем знак числителя из eax в edx
    cdq                          ; edx:eax = знаково расширенный eax

    ; Выполняем ЗНАКОВОЕ деление: числитель / знаменатель
    idiv dword [denominator_uint] ; eax = числитель / знаменатель

    ; Сохраняем результат
    mov [result_uint], eax

    ret

division_by_zero_error:
    ; Обработка деления на ноль
    mov eax, 0
    mov [result_uint], eax
    ret

