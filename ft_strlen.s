section .text

global ft_strlen

;size_t ft_strlen(const *str), str=rdi, ret=rax
ft_strlen:
			xor rax, rax			;len = 0
	.while:
			cmp byte[rdi + rax], 0	;str[len] == 0
			je	.return
			inc rax					;len++
			jmp	.while
	.return:
			ret						;return(len)