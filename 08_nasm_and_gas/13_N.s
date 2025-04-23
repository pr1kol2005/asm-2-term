extern printf
extern scanf
global main

section .text
main:
  push ebx
  push edi

  mov ebx, A
  mov edi, 8

  A_loop_start:
    test edi, edi
    jz A_loop_end

    push ebx
    push input_format
    call scanf
    add esp, 8

    add ebx, 1
    dec edi
    jmp A_loop_start
  A_loop_end:

  mov ebx, B
  mov edi, 8

  B_loop_start:
    test edi, edi
    jz B_loop_end

    push ebx
    push input_format
    call scanf
    add esp, 8

    add ebx, 1
    dec edi
    jmp B_loop_start
  B_loop_end:

  movapd xmm0, [A]
  paddsb  xmm0, [B]
  movapd [A], xmm0

  xor eax, eax
  mov ebx, A
  mov edi, 8

  mutual_loop_start:
    test edi, edi
    jz mutual_loop_end

    mov al, [ebx]
    push eax
    push output_format
    call printf
    add esp, 8

    add ebx, 1
    dec edi
    jmp mutual_loop_start
  mutual_loop_end:

  pop edi
  pop ebx

  xor eax, eax
  ret

section .data
  input_format db "%hhd", 0
  output_format db "%hhd ", 0
    
section .bss
  align 16
  A resb 16
  B resb 16

