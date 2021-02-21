segment .text
		global _ft_strdup
		extern _malloc
		extern _ft_strcpy
		extern _ft_strlen

_ft_strdup:
		jmp     strdup

strdup:
		call	_ft_strlen
		add		rax, 1
		push	rdi
		mov		rdi, rax
		call	_malloc
		pop		r10
		mov		rdi, rax
		mov		rsi, r10
		jmp		copy

copy:
		call	_ft_strcpy
		jmp		return

return:
		mov		rax, rdi
		ret