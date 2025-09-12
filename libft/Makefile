# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 12:34:17 by agerbaud          #+#    #+#              #
#    Updated: 2025/09/12 10:52:23 by agerbaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
INCLUDE = includes/libft.h
SRCS =	srcs/ft_isalpha.c		\
		srcs/ft_isdigit.c		\
		srcs/ft_isalnum.c		\
		srcs/ft_isascii.c		\
		srcs/ft_isdir.c			\
		srcs/ft_isprint.c		\
		srcs/ft_strlen.c		\
		srcs/ft_memset.c		\
		srcs/ft_bzero.c			\
		srcs/ft_memcpy.c		\
		srcs/ft_memmove.c		\
		srcs/ft_strlcpy.c		\
		srcs/ft_strlcat.c		\
		srcs/ft_toupper.c		\
		srcs/ft_tolower.c		\
		srcs/ft_strchr.c		\
		srcs/ft_strrchr.c		\
		srcs/ft_strncmp.c		\
		srcs/ft_memchr.c		\
		srcs/ft_memcmp.c		\
		srcs/ft_strnstr.c		\
		srcs/ft_atoi.c			\
		srcs/ft_calloc.c		\
		srcs/ft_strdup.c		\
		srcs/ft_substr.c		\
		srcs/ft_strjoin.c		\
		srcs/ft_strtrim.c		\
		srcs/ft_split.c			\
		srcs/ft_itoa.c			\
		srcs/ft_strmapi.c		\
		srcs/ft_striteri.c		\
		srcs/ft_perror.c		\
		srcs/ft_putchar_fd.c	\
		srcs/ft_putstr_fd.c		\
		srcs/ft_putendl_fd.c	\
		srcs/ft_putnbr_fd.c

SRCS_BONUS =	srcs/bonus/ft_lstnew_bonus.c		\
				srcs/bonus/ft_lstadd_front_bonus.c	\
				srcs/bonus/ft_lstsize_bonus.c		\
				srcs/bonus/ft_lstlast_bonus.c		\
				srcs/bonus/ft_lstadd_back_bonus.c	\
				srcs/bonus/ft_lstdelone_bonus.c		\
				srcs/bonus/ft_lstclear_bonus.c		\
				srcs/bonus/ft_lstiter_bonus.c		\
				srcs/bonus/ft_lstmap_bonus.c

BUILD_DIR = .build

CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD
RF = -rf

OBJECTS = $(SRCS:%.c=$(BUILD_DIR)/%.o)
OBJECTS_BONUS = $(SRCS_BONUS:%.c=$(BUILD_DIR)/%.o)
DEPENDANCIES = $(SRCS:%.c=$(BUILD_DIR)/%.d) $(SRCS_BONUS:%.c=$(BUILD_DIR)/%.d)


all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) -crs $@ $^

-include $(DEPENDANCIES)

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@


bonus:
	@$(MAKE) SRCS="$(SRCS) $(SRCS_BONUS)"

clean:
	$(RM) $(RF) $(BUILD_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(SRCS) $(SRCS_BONUS)
	gcc -nostartfiles -shared -o libft.so $(OBJECTS) $(OBJECTS_BONUS)


.PHONY: all bonus clean fclean re so
