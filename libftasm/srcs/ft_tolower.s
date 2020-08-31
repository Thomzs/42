global _ft_tolower
extern _ft_isupper

section .text
_ft_tolower:
	call _ft_isupper
	cmp eax, 0
	je end
	add rdi, 32

end:
	mov rax, rdi
	ret
