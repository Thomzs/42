global _ft_memset

section .text
_ft_memset:
	push rdi
	cmp rdi, 0
	je end
	mov rax, rsi
	mov rcx, rdx
	cld
	repne stosb

end:
	pop rax	
	ret
