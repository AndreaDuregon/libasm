;   extern  : insert an extern function
;   syscall : call the function save in the register
;   jc      : jump if the last call return a negative value
;   push    : push in stack the value in the register
;   pop     : pop in the register the value pushed in the stack
;   call    : call extern function

segment .text
        global _ft_write
        extern ___error             ; extern function

_ft_write:
        mov     rax, 0x2000004      ; address of write in rax
        jmp     write               ; jump to write

write:
        syscall                     ; call to write
        jc      error               ; if syscall return negative, jump to error
        jmp     return              ; jump to return
    
error:
        push    rax                 ; push in the stack the value of rax
        call    ___error            ; call ___error function
        pop     r10                 ; pop value in the stack in r10
        mov     [rax], r10          ; move r10 in [rax]
        mov     rax, -1             ; rax = -1
        ret                         ; return

return:
        ret                         ; return