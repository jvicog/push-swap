# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/25 17:39:25 by jvico-ga          #+#    #+#              #
#    Updated: 2022/03/16 18:12:30 by jvico-ga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap.a
SRCS	= ft_atoi.c ft_split.c ft_strlcpy.c ft_strlen.c push_swap.c push_swap_aux.c
			three_numbers.c
OBJS	= $(SRCS:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

all: $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS) 
clean:
			$(RM) $(OBJS)
			
fclean:		clean
	$(RM) $(NAME)
re:			fclean all
.PHONY:     bonus all clean fclean re