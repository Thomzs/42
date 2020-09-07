global _ft_strcpy
extern _ft_strlen

section .text
_ft_strcpy:
	push rdi
	cmp rdi, 0
	je end
	cmp rsi, 0
	je end
	mov rdx, rdi
	mov rdi, rsi
	call _ft_strlen
	add rax, 1 ;copy the null char at the end
	mov rcx, rax
	mov rdi, rdx
	cld
	rep movsb

end:
	pop rax
	ret
