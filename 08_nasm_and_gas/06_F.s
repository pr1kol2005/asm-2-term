global main
extern printf
extern scanf

section .text

main:
  push dword A
  push dword Text
  call scanf
  add esp, 8

  push dword B
  push dword Text
  call scanf
  add esp, 8

  mov eax, [A]
  mov edx, [B]
  cmp eax, edx
  jge else
      push eax
  jmp fi
  else:
      push edx
  fi:

  push dword Text
  call printf
  add esp, 8

  xor eax, eax
  ret

section .data
Text db "%d", 0

section .bss
  A resd 1
  B resd 1
