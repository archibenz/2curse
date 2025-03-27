; Use default RIP-relative addressing
default rel

section .data
    extern a_char          ; Extern declarations for variables
    extern b_char
    extern c_char
    extern numerator_char
    extern denominator_char
    extern result_char

section .text
    global compute_signed_char

compute_signed_char:
    ; Load b_char into ebx and c_char into ecx with sign extension
    movsx ebx, byte [b_char]
    movsx ecx, byte [c_char]

    ; Multiply b_char * c_char
    imul ebx, ecx           ; ebx = b_char * c_char

    ; Prepare to compute 8 / a_char
    mov eax, 8              ; eax = 8 (dividend)
    cdq                     ; edx:eax = sign-extended dividend
    movsx ecx, byte [a_char]; ecx = a_char (divisor)

    ; Check for division by zero
    cmp ecx, 0
    je division_by_zero_error

    ; Perform signed division
    idiv ecx                ; eax = 8 / a_char

    ; Subtract the result of division from the multiplication result
    sub ebx, eax            ; ebx = (b_char * c_char) - (8 / a_char)

    ; Store the numerator
    mov [numerator_char], ebx

    ; Compute the denominator: 31 + b_char - 1
    movsx eax, byte [b_char]
    add eax, 30             ; eax = 31 + b_char - 1

    ; Store the denominator
    mov [denominator_char], eax

    ; Check for division by zero
    cmp eax, 0
    je division_by_zero_error

    ; Prepare to divide numerator by denominator
    mov eax, [numerator_char]
    cdq                     ; edx:eax = sign-extended dividend

    ; Perform signed division
    idiv dword [denominator_char]; eax = numerator_char / denominator_char

    ; Store the result
    mov [result_char], eax

    ret

division_by_zero_error:
    ; Handle division by zero error
    mov eax, 0
    mov [result_char], eax
    ret

