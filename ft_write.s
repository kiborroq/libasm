section		.text

global		ft_write
extern		__errno_location

;ssize_t ft_write(int fd, const void *buf, size_t count), fd=rdi, buf=rsi, count=rdx, ret=rax
ft_write:
			mov		rax, 1						;system call - sys_write=1
			syscall								;call core
			cmp		rax, 0						;rax(-errno) < 0, error during reading
			jl		.errno						;if error during sys_write
			jmp		.return
	.errno:
			neg		rax							;rax(errno) = rax(-errno) * (-1)
			mov		rdx, rax					;move rax(errno) to rdx
			call	__errno_location wrt ..plt	;call __errno_location, errno pointer set to rax
			mov		[rax], rdx					;*errno = rdx(errno)
			mov		rax, -1						;set rax to -1
			jmp		.return
	.return:
			ret									;return (rax)