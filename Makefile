# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/26 14:12:05 by khelegbe          #+#    #+#              #
#    Updated: 2021/06/22 15:49:52 by khelegbe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	clang

FLAGS		=	-Wall -Wextra -Werror -g

NAME		=	push_swap

SRCS		=	srcs/push_swap.c

HEADERS		=	-I include -I libft

LIB			=	-lft -L libft

LIBFT_PATH	=	libft

LIBFT		=	${LIBFT_PATH}/libft.a

OBJECTS		=	${SRCS:.c=.o}

all:			$(NAME)

.c.o:
				${CC} ${FLAGS} ${HEADERS} -c $< -o ${<:.c=.o}

$(NAME) :		${OBJECTS}
				@make -C libft
				@${CC} ${FLAGS} ${OBJECTS} ${HEADERS} ${LIB} ${LIBFT} -o ${NAME}
				@printf "\033[92mpush_swap compiled\n\033[0m"

debug:			$(NAME)
				./${NAME} "12 35 35 45"
				# @rm -rf $(NAME)

clean:
				@make clean -C ${LIBFT_PATH}
				@rm -rf ${OBJECTS}
				@printf "\033[92mclean done\n\033[0m"

fclean:			clean
				@make fclean -C ${LIBFT_PATH}
				@rm -rf $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
