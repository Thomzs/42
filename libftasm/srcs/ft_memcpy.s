global _ft_memcpy

section .text
_ft_memcpy:
	push rdi
	cmp rdi, 0
	je end
	cmp rsi, 0
	je end
	mov rcx, rdx
	mov rax, rsi
	cld
	rep movsb

end:
	pop rax
	ret
