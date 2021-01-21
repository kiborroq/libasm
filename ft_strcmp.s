section		.text

global		ft_strcmp

;int ft_strcmp(const char *s1, const char *s2), s1=rdi, s2=rsi, ret=rax
ft_strcmp:
			xor rax, rax			;diff = 0
			xor dl, dl				;tmp = 0
			xor	rcx, rcx			;i = 0
	.while:
			mov	dl, [rsi + rcx]		;tmp = s2[i]
			cmp	[rdi + rcx], dl		;s1[i] == tmp
			jg	.greater
			jl	.less
			cmp [rsi + rcx], byte 0	;s1[i] == 0
			je	.return
			inc	rcx					;i++
			jmp	.while
	.greater:
			mov rax, 1				;s1[i] > s2[i], diff = 1
			jmp .return
	.less:
			mov rax, -1
			jmp .return				;s1[i] < s2[i], diff = -1
	.return:
			ret						;return (diff)