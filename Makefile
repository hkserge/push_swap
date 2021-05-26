# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/26 14:12:05 by khelegbe          #+#    #+#              #
#    Updated: 2021/05/26 14:29:53 by khelegbe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	clang

FLAGS		=	-Wall -Wextra -Werror

NAME		=	libftpush_swap.a

SRCS		=





HEADERS		=	.

OBJECTS		=	${SRCS:.c=.o}

all:			$(NAME)

.c.o:
				@${CC} ${FLAGS} -I ${HEADERS} -c $< -o ${<:.c=.o}

$(NAME) :		${OBJECTS}
				@make -C libft
				@cp libft/libft.a ${NAME}
				@ar rcs ${NAME} ${OBJECTS}
				@printf "\033[92mpush_swap compiled\n\033[0m

debug:
				@make
				clang main.c libftpush_swap.a -I include -I libft
				./a.out

clean:
				@make -C libft clean
				@rm -rf ${OBJECTS}
				@printf "\033[92mclean done\n\033[0m"

fclean:			clean
				@make -C libft fclean
				@rm -rf $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
