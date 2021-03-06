# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/25 09:43:49 by dmahoro-          #+#    #+#              #
#    Updated: 2021/04/16 21:42:06 by dmahoro-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
NAME		= libft.a
SRCS		= ft_memset.c \
			  ft_bzero.c \
			  ft_memcpy.c \
			  ft_memccpy.c \
			  ft_memmove.c \
			  ft_memchr.c \
			  ft_memcmp.c \
			  ft_strlen.c \
			  ft_isalpha.c \
			  ft_isdigit.c \
			  ft_isalnum.c \
			  ft_isascii.c \
			  ft_isprint.c \
			  ft_toupper.c \
			  ft_tolower.c \
			  ft_strchr.c \
			  ft_strrchr.c \
			  ft_strncmp.c \
			  ft_strlcpy.c \
			  ft_strlcat.c \
			  ft_strnstr.c \
			  ft_atoi.c \
			  ft_calloc.c \
			  ft_strdup.c \
			  \
			  ft_substr.c \
			  ft_strjoin.c \
			  ft_strtrim.c \
			  ft_split.c \
			  ft_itoa.c \
			  ft_strmapi.c \
			  ft_putchar_fd.c \
			  ft_putstr_fd.c \
			  ft_putendl_fd.c \
			  ft_putnbr_fd.c \
			  \
			  ft_islower.c \
			  ft_isupper.c \
			  ft_strncpy.c \
			  ft_strcpy.c \
			  ft_strcat.c \
			  ft_bit_map.c \
			  ft_bit_at.c \
			  ft_strnew.c \
			  ft_firstwordlen.c \
			  ft_countwords.c \
			  ft_split_set_separators.c \
			  ft_itoa_base.c \
			  \
			  ft_strstr.c \
			  ft_strcmp.c \
			  ft_memchr_pos.c

SRCS_BON	= ft_lstnew.c \
			  ft_lstadd_front.c \
			  ft_lstsize.c \
			  ft_lstlast.c \
			  ft_lstadd_back.c \
			  ft_lstdelone.c \
			  ft_lstclear.c \
			  ft_lstiter.c \
			  ft_lstmap.c

CFLAGS		= -Wall -Wextra -Werror
OBJS		= $(SRCS:%.c=%.o)
OBJS_BON	= $(OBJS) $(SRCS_BON:%.c=%.o)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -c $(SRCS) -I./
		ar -rcs $@ $^

bonus: $(OBJS_BON)
		$(CC) $(CFLAGS) -c $(SRCS_BON) -I./
		ar -rcs $(NAME) $^

all: $(NAME)

so:
	$(CC) -c -fPIC $(CFLAGS) $(SRCS_BON)
	gcc -shared -o libft.so $(OBJS_BON)

clean:
	rm -f $(OBJS_BON) *.so

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
