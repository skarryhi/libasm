
global _ft_strcpy

_ft_strcpy:
	xor rax, rax
_while:
	cmp byte[rsi + rax], 0
	jz _return
	mov bl, byte[rsi + rax]
	mov byte[rdi + rax], bl
	inc rax
	jmp _while
_return:
	mov byte[rdi + rax], 0
	mov rax, rdi
	ret