xor rbx, rbx
mov rdx, rcx
mov rsi, rax

sum_loop:
    cmp rdx, 0
    je done

    add rbx, [rsi]
    add rsi, 8
    dec rdx
    jmp sum_loop
done:
