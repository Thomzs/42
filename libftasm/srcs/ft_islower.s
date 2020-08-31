global _ft_islower

section .text
_ft_islower:
	cmp rdi, 97
	jl no
	cmp rdi, 122
	jle yes

no:
	mov rax, 0
	ret

yes:
	mov rax, 1
	ret
