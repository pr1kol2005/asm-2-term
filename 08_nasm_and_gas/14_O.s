global main

section .text
main:
  mov eax, 3
  mov ebx, 0
  mov ecx, input_byte
  mov edx, 1
  int 128

  mov al, [input_byte]
  or al, 7
  mov [input_byte], al

  mov eax, 4
  mov ebx, 1
  mov ecx, input_byte
  mov edx, 1
  int 128

  xor eax, eax
  ret

section .bss
  input_byte resb 1
