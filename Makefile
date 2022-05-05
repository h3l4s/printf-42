# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aestor <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/18 14:40:36 by aestor            #+#    #+#              #
#    Updated: 2021/03/18 14:40:43 by aestor           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	=   ./file_struc.c ./flag_di.c ./ft_itoa.c ./ft_printf.c ./ft_utils.c ./flag_di2.c ./flag_s.c ./flag_c.c \
            ./put_nbr_base.c ./flag_p.c ./ft_utils_2.c ./file_s_2.c

GCC		= gcc

HEAD	= ft_printf.h

CFLAGS	= -Wall -Wextra -Werror -I ${HEAD}

OBJS	= ${SRCS:.c=.o}

RM		= rm -rf

.c.o: 
		${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
		ar rcs ${NAME} ${OBJS}

all:	${NAME}	

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY: bonus re clean fclean all
