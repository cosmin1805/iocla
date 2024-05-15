%include "../utils/printf32.asm"

%define NUM_FIBO 10

section .text

extern printf
global main
main:
    mov ebp, esp

    ; TODO - replace below instruction with the algorithm for the Fibonacci sequence
    sub esp, NUM_FIBO * 4

    mov ecx, NUM_FIBO

; int fibonacci(int nr, int n)
fibonacci:
    pop     ebp
    mov     eax, [ebp + 8] ; luam n-ul curent
    cmp     eax, 1
    jle     fibonacci_end

    dec     eax
    push    eax
    inc     eax

    call    fibonacci

    pop     ebx ; luam ce se returneaza
    add     eax, ebx

    mov     ebx, [ebp + 8] ; luam n-ul curent
    sub     ebx, 2
    push    ebx

    call    fibonacci

    pop     ebx ; luam ce se returneaza
    add     eax, ebx

    ret

fibonacci_end:
    mov eax, 1
    ret

print:
    mov eax, dword [esp + (ecx - 1) * 4]
    PRINTF32 `%d \x0`, eax
    dec ecx
    cmp ecx, 0
    ja print

    PRINTF32 `\n\x0`
    mov esp, ebp
    xor eax, eax
    ret
