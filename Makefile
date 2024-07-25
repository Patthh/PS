# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pracksaw <pracksaw@student.42bangkok.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/18 19:53:39 by pracksaw          #+#    #+#              #
#    Updated: 2024/07/24 21:24:58 by pracksaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	:=	push_swap
#BNAME	:=	checker
CFLAGS 	:= 	-Wall -Werror -Wextra
CC 		:= 	cc
RM		:=	rm -f
SRCS 	:= memory_free_meta.c \
		input_cleaner.c	input_convertcheckback.c input_fill_stacks.c \
		input_formatcheck.c input_check.c \
		rotates.c swaps.c pushes.c reverse_rotates.c \
		sort_push_swap.c sort_costs_a.c sort_push_to_a.c sort_push_to_b.c \
		sort_push_to_b_utils.c sort_targeting_a.c sort_targeting_b.c \
		sort_stacks_utils.c \
		basic_utils.c ft_bzero.c ft_calloc.c ft_itoa.c ft_split.c \
		ft_strdup.c ft_strlcpy.c ft_substr.c

MAIN    := main.c
#BSRCS   := checker.c gnl.c gnl_utils.c
OBJS	:=	$(SRCS:.c=.o)
#BOBJS	:=	$(BSRCS:.c=.o)
MOBJS   := $(MAIN:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(MOBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MOBJS)

#$(BNAME): $(OBJS) $(BOBJS)
#	$(CC) $(CFLAGS) -o $(BNAME) $(OBJS) $(BOBJS)

#bonus: $(BNAME)

norm: $(SRCS) $(MAIN) $(BSRCS)
	$(norm) $(SRCS) $(MAIN) $(BSRCS) push_swap.h

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BOBJS) $(MOBJS) a.out

fclean: clean
	$(RM) $(NAME) $(BNAME)

re: fclean all

#shuf:
#int_max =
#2147483647
#	AR=($(shuf -i 0-1000000000 -n 500 | tr '\n' ' ')); ./push_swap $AR | wc -l
#	valgrind --leak-check=full --track-origins=yes ./push_swap

.PHONY: all clean fclean re norm
