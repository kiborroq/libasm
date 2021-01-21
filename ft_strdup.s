section			.text

global			ft_strdup
extern			ft_strlen
extern			malloc
extern			ft_strcpy

;char *ft_strdup(const char *src), src=rdi, ret=rax
ft_strdup:
			call ft_strlen			;rax(len) = ft_strlen(s)
			inc	 rax				;rax(size) = rax(len) + 1
			push rdi				;save rdi(src) to stack
			mov	 rdi, rax			;move rax(size) to rdi
			call malloc wrt ..plt	;mem allocate for new src
			cmp	 rax, 0				;rax(dest) == 0
			je	 .return
			pop  rsi				;set src to rsi from stack
			mov	 rdi, rax			;move rax(dest) to rdi
			call ft_strcpy			;copy rsi(src) to rdi(dest)
	.return:
			ret						;return (dest)