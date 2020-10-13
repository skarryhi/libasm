global _ft_strcmp

_ft_strcmp:
	xor rax, rax
	xor r8, r8
	xor r9, r9
	mov rcx, -1
_while:
	inc rcx
	mov r8b, byte[rdi + rcx]
	mov r9b, byte[rsi + rcx]
	cmp r8, 0
	jz _return
	cmp r9, 0
	jz _return
	cmp r8, r9
	jz _while
_return:
	sub r8, r9
	mov rax, r8
	ret
