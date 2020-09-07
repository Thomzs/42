global _ft_strdup
extern _ft_strlen
extern _ft_strcpy
extern _malloc
extern _ft_puts

section .text
_ft_strdup:
	push rdi
	cmp rdi, 0
	je end_null
	call _ft_strlen
	add rax, 1
	mov rdi, rax
	call _malloc
	pop rsi
	mov rdi, rax
	call _ft_strcpy

end:
	ret	

end_null:
	pop rax
	ret
