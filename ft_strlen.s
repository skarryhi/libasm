
global _ft_strlen


_ft_strlen:
	xor rax, rax
	cmp rdi, 0
	jz _return
_while:
	cmp byte[rdi + rax], 0
	jz _return
	inc rax
	jmp _while
_return:
	ret