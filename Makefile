# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiborroq <kiborroq@kiborroq.42.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/19 14:11:42 by kiborroq          #+#    #+#              #
#    Updated: 2021/01/21 11:50:20 by kiborroq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libasm.a

SRCS	= ft_strlen.s \
		ft_strcpy.s \
		ft_strcmp.s \
		ft_write.s \
		ft_read.s \
		ft_strdup.s
OBJS	= ${SRCS:.s=.o}
ASM		= nasm
SFLAGS	= -f elf64

TEST	= test
CC		= gcc
CFLAGS	= -Werror -Wextra -Wall

.s.o:
		@${ASM} ${SFLAGS} $< -o ${<:.s=.o}

${NAME}:${OBJS}
		@echo Create ${NAME}
		@ar rcs ${NAME} ${OBJS}

all:	${NAME}

test:	${NAME}
		@echo Create ${TEST}
		@${CC} ${CFLAGS} test.c ${NAME} -o ${TEST}
		@./${TEST}

clean:
		@echo "Remove all *.o"
		@rm -f ${OBJS}

fclean:	clean
		@echo Remove ${NAME}
		@echo Remove ${TEST}
		@rm -f ${NAME}
		@rm -f ${TEST}
		@rm -f libft.so

re: 	fclean all

.PHONY:	all clean fclean re .c.o test
