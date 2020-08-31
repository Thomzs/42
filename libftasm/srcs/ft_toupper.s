global _ft_toupper
extern _ft_islower

section .text
_ft_toupper:
	call _ft_islower
	cmp eax, 0
	je end
	sub rdi, 32

end:
	mov rax, rdi
	ret
