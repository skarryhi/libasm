global _ft_strdup
extern _malloc
extern _ft_strlen
extern _ft_strcpy

_ft_strdup:
	push rdi
	call _ft_strlen
	call _malloc
	cmp rax, 0
	jz _return
	mov rdi, rax
	pop rsi
	call _ft_strcpy 
_return:
	ret