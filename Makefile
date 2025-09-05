# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yihe <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/19 09:46:19 by yihe              #+#    #+#              #
#    Updated: 2025/06/24 13:20:44 by yihe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -Isrc/ft_printf
RM = rm -f

SRC_FILES = \
			 src/ft_isalpha.c \
			 src/ft_isdigit.c \
			 src/ft_isalnum.c \
			 src/ft_isascii.c \
			 src/ft_isprint.c \
			 src/ft_strlen.c \
			 src/ft_memset.c \
			 src/ft_bzero.c \
			 src/ft_memcpy.c \
			 src/ft_memmove.c \
			 src/ft_strlcpy.c \
			 src/ft_strlcat.c \
			 src/ft_toupper.c \
			 src/ft_tolower.c \
			 src/ft_strchr.c \
			 src/ft_strrchr.c \
			 src/ft_strncmp.c \
			 src/ft_memchr.c \
			 src/ft_memcmp.c \
			 src/ft_strnstr.c \
			 src/ft_atoi.c \
			 src/ft_calloc.c \
			 src/ft_strdup.c \
			 src/ft_substr.c \
			 src/ft_strjoin.c \
			 src/ft_strtrim.c \
			 src/ft_split.c \
			 src/ft_itoa.c \
			 src/ft_strmapi.c \
			 src/ft_striteri.c \
			 src/ft_putchar_fd.c \
			 src/ft_putstr_fd.c \
			 src/ft_putendl_fd.c \
			 src/ft_putnbr_fd.c \
			 src/ft_lstnew.c \
			 src/ft_lstadd_front.c \
			 src/ft_lstsize.c \
			 src/ft_lstlast.c \
			 src/ft_lstadd_back.c \
			 src/ft_lstdelone.c \
			 src/ft_lstclear.c \
			 src/ft_lstiter.c \
			 src/ft_lstmap.c \
			 src/ft_printf/ft_printf.c \
			 src/ft_printf/print_formatted_char.c \
			 src/ft_printf/print_formatted_string.c \
			 src/ft_printf/print_formatted_pointer.c \
			 src/ft_printf/print_formatted_int.c \
			 src/ft_printf/print_formatted_unsigned.c \
			 src/ft_printf/print_formatted_hex.c \
			 src/ft_printf/print_formatted_number.c \
			 src/ft_printf/ft_ultoa_base.c \
			 src/ft_printf/parse_format.c

OBJ_FILES = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_FILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
