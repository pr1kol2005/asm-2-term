global main
extern printf
extern scanf

section .text

main:
  push dword A
  push dword Text
  call scanf
  add esp, 8

  and dword [A], 0xffff

  push dword [A]
  push dword Text
  call printf
  add esp, 8

  xor eax, eax
  ret

section .data
Text db "%u", 0

section .bss
A resd 1
