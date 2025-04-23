global main
extern printf
extern scanf
extern qsort

section .text

compare:
  mov eax, [esp + 4]
  mov ecx, [esp + 8]
  mov eax, [eax]
  mov ecx, [ecx]
  sub eax, ecx
  ret

main:
  push ebx
  push edi

  push N
  push input_format
  call scanf
  add esp, 8

  mov edi, [N]
  mov ebx, A
  input_loop_start:
    test edi, edi
    jz input_loop_end

    push ebx
    push input_format
    call scanf
    add esp, 8
    add ebx, 4

    dec edi
    jmp input_loop_start
  input_loop_end:

  push compare
  push 4
  xor edi, edi
  mov edi, [N]
  push edi
  push A
  call qsort
  add esp, 16


  mov edi, [N]
  mov ebx, A
  output_loop_start:
    test edi, edi
    jz output_loop_end

    mov eax, [ebx]
    push eax
    push output_format
    call printf
    add esp, 8
    add ebx, 4

    dec edi
    jmp output_loop_start
  output_loop_end:

  pop edi
  pop ebx
  xor eax, eax
  ret

section .data
  input_format db "%d", 0
  output_format db "%d ", 0

section .bss
  N resd 1
  A resd 10000
