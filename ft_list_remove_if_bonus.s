segment .text
	global _ft_list_remove_if
	extern _free

_ft_list_remove_if:
		push	rdi
		cmp		rdi, 0				; if begin_list == NULL
		je		return				; return
		mov		r15, [rdi + 8]		; r15 = begin->next
		pop		rdi					;
		cmp		r15, 0				; if (begin->next) == NULL
		je		rm_list				; jump to rm_list
		cmp		rsi, 0				; if data == NULL
		je		return				; return
		cmp		rdx, 0				; if cmp == NULL
		je		return				; return
		cmp		rcx, 0				; if free == NULL
		je		return				; return
		jmp		head				; if begin_list == NULL

head:
		push	rcx					; 
		push	rdx					;
		push	rsi					;
		push	rdi					;
		mov		r10, [rdi]			; r10 = begin_list
		mov		rdi, [r10]			; rdi = begin_list->data
		call	rdx					; cmp(begin_list->data, data)
		pop		rdi					;
		pop		rsi					;
		pop		rdx					;
		pop		rcx					;
		cmp		rax, 0				; if cmp == 0
		je		rm_head				; jump to rm_head
		push	rcx					;
		push	rdx					;
		push	rsi					;
		push	rdi					;
		mov		r10, [rdi]			; r10 = begin_list
		pop		rdi					;
		pop		rsi					;
		pop		rdx					;
		pop		rcx					;
		jmp		second				; jump to second

rm_head:
		mov		r10, [rdi]			; r10 = begin_list
		mov		r11, [r10 + 8]		; r11 = begin_list->next
		push	r11					;
		push	rcx					;
		push	rdx					;
		push	rsi					;
		push	rdi					;
		mov		rdi, [r10]			; rdi = begin_list->data
		call	rcx					; free(begin_list->data)
		pop		rdi					; 
		push	rdi					;
		mov		r10, [rdi]			; r10 = begin_list
		mov		rdi, r10			; rdi = begin_list
		call 	_free				; free(begin_list)
		pop		rdi					;
		pop		rsi					;
		pop		rdx					;
		pop		rcx					;
		pop		r11					; 
		mov		[rdi], r11			; begin_list = begin_list->next
		jmp		return				; return

second:	
		mov		r11, [r10 + 8]		; r11 = list->next
		cmp		r11, 0				; if list->next == NULL
		je		return				; return
		push	r11					;
		push	r10					;
		push	rcx					;
		push	rdx					;
		push	rsi					;
		push	rdi					;
		mov		rdi, [r11]			; rdi = list->next->data
		call	rdx					; cmp(list->next->data, data)
		pop		rdi					;
		pop		rsi					;
		pop		rdx					;
		pop		rcx					;
		pop		r10					;
		pop		r11					;
		cmp		rax, 0				; if cmp == 0
		je		rm					; jump to rm
		mov		r10, r11			; r10, list->next
		jmp		second				; jump to second

rm:
		mov		r12, [r11 + 8]		; r12 = list->next->next
		mov		[r10 + 8], r12		; list->next = list->next->next
		push	r12					;
		push	r10					;
		push	rcx					;
		push	rdx					;
		push	rsi					;
		push	rdi					;
		mov		rdi, [r11]			; rdi = list->next->data
		call	rcx					; free(list->next->data)
		pop		rdi					;
		pop		rsi					;
		pop		rdx					;
		pop		rcx					;
		pop		r10					;
		pop		r12					;
		mov		r10, r12			; r10 = list->next->next
		jmp		return				; return

rm_list:
		push	rcx					; 
		push	rdx					;
		push	rsi					;
		push	rdi					;
		mov		r10, [rdi]			; r10 = begin_list
		mov		rdi, [r10]			; rdi = begin_list->data
		call	rdx					; cmp(begin_list->data, data)
		pop		rdi					;
		pop		rsi					;
		pop		rdx					;
		pop		rcx					;
		cmp		rax, 0				; if cmp == 0
		je		return				; return
		mov		rdi, [rdi]			; rdi = begin_list
		call	_free				; free(head)
		jmp		return				; return

return:
		ret							; return