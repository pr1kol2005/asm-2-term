global main
extern printf
extern scanf

section .text

main:
  push ebx
  push edi

  push N
  push input_format
  call scanf
  add esp, 8

  mov di, [N]
  mov ebx, A
  while_1_start:
  test di, di
  jz while_1_end
    push ebx
    push input_format
    call scanf
    add esp, 8
    add ebx, 2
  dec di
  jmp while_1_start
  while_1_end:

  mov di, [N]
  while_2_start:
  test di, di
  jz while_2_end
    sub ebx, 2
    mov ax, [ebx]
    push eax
    push output_format
    call printf
    add esp, 8
  dec di
  jmp while_2_start
  while_2_end:

  pop edi
  pop ebx
  xor eax, eax
  ret

section .data
  input_format db "%hu", 0
  output_format db "%hu ", 0

section .bss
  N resw 1
  A resw 10000
