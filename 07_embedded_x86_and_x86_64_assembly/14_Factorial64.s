cmp al, 0
jbe zero

movzx rdx, al
mov rcx, rdx

cmp rcx, 0
jbe done

mov rax, 1

loop:
    cmp rcx, 1
    jbe done
    imul rax, rcx
    dec rcx
    jmp loop

zero:
    mov rax, 1

done:
    mov rdx, rax
