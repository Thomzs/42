global _ft_isascii

section .text
_ft_isascii:
	cmp rdi, byte 0
	jl no
	cmp rdi, 127
	jg no

yes:
	mov rax, 1
	ret

no:
	mov rax, 0
	ret
