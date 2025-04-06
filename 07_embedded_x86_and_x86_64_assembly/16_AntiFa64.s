mov rbx, 1
mov rcx, 1
mov rdx, rax

antifa:
    cmp rdx, rbx
    je done

    inc rcx
    imul rbx, rcx
    jmp antifa

done:
    mov rax, rcx
    mov rbx, rax