# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 14:51:32 by ljaehaer          #+#    #+#              #
#    Updated: 2022/02/18 11:02:14 by ljaehaer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex

SRC			=	src/pipex.c src/utils.c src/utils2.c

SRC_B		=	src_b/pipex_bonus.c src_b/utils_bonus.c src_b/pipex_here_doc_bonus.c\
				src_b/utils_here_doc_bonus.c src_b/utils_here_doc_bonus2.c src_b/utils_here_doc_bonus3.c

HEADER		=	inc/pipex.h

OBJ			=	${SRC:%.c=%.o}
OBJ_B		=	${SRC_B:%.c=%.o}
OBJ_TO_OBJ_B	=	src/utils.o src/utils2.o

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

.PHONY	:		all clean fclean re bonus

all		:		${NAME}
	
${NAME}	:		${OBJ}
	make -C libft
	${CC} ${CFLAGS} -o ${NAME} ${OBJ} -L./libft -lft

%.o		:		%.c ${HEADER}
	${CC} ${CFLAGS} -c $< -o $@

clean	:		
	${RM} ${OBJ} ${OBJ_B}

fclean	:		clean
	make -C libft fclean
	${RM} ${NAME}

re		:		fclean all

bonus	:
	@make OBJ="${OBJ_B} ${OBJ_TO_OBJ_B}" all
