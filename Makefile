# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agerbaud <agerbaud@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 12:34:17 by agerbaud          #+#    #+#              #
#    Updated: 2024/04/04 18:50:14 by agerbaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a
INCLUDE = pipex.h
SRCS =	pipex.c	\
		utils.c

CC = cc -Wall -Wextra -Werror -MMD -g3

OBJECTS = $(SRCS:.c=.o)
DEPENDANCIES = $(SRCS:.c=.d)


all: $(NAME)

$(LIBFTDIR):
	$(MAKE) -C $@ bonus

$(LIBFT): $(LIBFTDIR)

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(LIBFT) -o $@ $^

-include $(DEPENDANCIES)


%.o: %.c
	$(CC) -c $<


clean:
	$(RM) $(OBJECTS) $(DEPENDANCIES)
	$(MAKE) -C $(LIBFTDIR) $@

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFTDIR) $@

re: fclean all


.PHONY: all clean fclean re $(LIBFTDIR)
