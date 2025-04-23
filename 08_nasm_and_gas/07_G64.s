global main
extern printf
extern scanf

section .text
main:
  mov rax, rsp
  and rsp, ~0xf
  push rax
  push rax

  xor rax, rax
  mov rdi, format
  mov rsi, A
  call scanf

  xor rax, rax
  mov rdi, format
  mov rsi, B
  call scanf

  mov rax, [A]
  add rax, [B]
  
  jc ca
      mov rdi, negative
      jmp fi
  ca:
      mov rdi, positive
  fi:

  xor rax, rax
  call printf

  xor rax, rax
  pop rsp
  ret

section .data
  negative  db "NO", 10, 0
  positive db "YES", 10, 0
  format db "%llu", 0

section .bss
  A resb 8
  B resb 8
