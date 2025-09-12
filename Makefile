# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 12:34:17 by agerbaud          #+#    #+#              #
#    Updated: 2025/09/12 11:17:01 by agerbaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a
SRCS = srcs/pipex.c srcs/utils.c

CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD
BUILD_DIR = .build

OBJECTS = $(SRCS:%.c=$(BUILD_DIR)/%.o)
DEPENDENCIES = $(SRCS:%.c=$(BUILD_DIR)/%.d)

LIBFT_SRC = $(wildcard $(LIBFTDIR)/*.c) $(wildcard $(LIBFTDIR)/**/*.c)
LIBFT_HDR = $(wildcard $(LIBFTDIR)/*.h) $(wildcard $(LIBFTDIR)/**/*.h)
LIBFT_DEPS = $(LIBFT_SRC) $(LIBFT_HDR)


all: $(NAME)

$(LIBFT): $(LIBFT_DEPS)
	$(MAKE) -C $(LIBFTDIR) bonus

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $@

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@


-include $(DEPENDENCIES)


clean:
	$(RM) -r $(BUILD_DIR)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all


.PHONY: all clean fclean re