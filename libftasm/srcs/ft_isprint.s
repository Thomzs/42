global _ft_isprint

section .text
_ft_isprint:
	cmp rdi, 32
	jl no
	cmp rdi, 126
	jg no

yes:
	mov rax, 1
	ret

no:
	mov rax, 0
	ret
