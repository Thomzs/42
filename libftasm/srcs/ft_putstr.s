%define MATCH_SYSCALL(nb)	0x2000000 | nb
%define STDOUT				1
%define WRITE				4

global _ft_putstr
extern _ft_strlen
extern _fflush

section .text
_ft_putstr:
	cmp rdi, 0
	je end
	push rdi
	call _ft_strlen
	pop rsi
	mov rdi, STDOUT
	mov rdx, rax
	mov rax, MATCH_SYSCALL(WRITE)
	syscall

end:
	ret
