segment .text
        global _ft_list_size

_ft_list_size:
        mov     rax, 0          ; set rax to 0
        mov     r10, rdi        ; mov rdi in r10
        jmp     count           ; jump to count

count:
        cmp     r10, 0          ; if r10 == null
        jz      return          ; return
        mov     r10, [r10 + 8]  ; r10 = r10->next
        inc     rax             ; increase rax
        jmp     count           ; re-count

return:
        ret                     ; return rax