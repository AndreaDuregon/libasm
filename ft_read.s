segment .text
        global _ft_read
        extern ___error                 ; extern function

_ft_read:
        mov     rax, 0x2000003          ; address of read in rax
        jmp     read                    ; jump to read

read:
        syscall                         ; call to write
        jc      error                   ; if syscall return negative, jump to error
        jmp     return                  ; jump to return

error:
        push    rax                     ; push in the stack the value of rax
        call    ___error                ; call ___error function
        pop     r10                     ; pop value in the stack in r10
        mov     [rax], r10              ; move r10 in [rax]
        mov     rax, -1                 ; rax = -1
        ret                             ; retrun

return:
        ret                             ; return