section		.text

global		ft_strcpy

;char *ft_strcpy(char *dest, const char *src), dest=rdi, src=rsi, ret=rax
ft_strcpy:
			xor dl, dl					;tmp = 0
			xor rcx, rcx				;i = 0
	.while:
			mov dl, byte [rsi + rcx]	;tmp = src[i]
			mov	byte [rdi + rcx], dl	;dest[i] = tmp
			cmp byte [rsi + rcx], 0		;src[i] == 0
			je	.return
			inc	rcx						;i++
			jmp	.while
	.return:
			mov rax, rdi
			ret							;return (dest)