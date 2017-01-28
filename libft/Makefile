# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slogos <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/22 15:36:15 by hkalia            #+#    #+#              #
#    Updated: 2016/09/26 17:14:46 by hkalia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libft.a
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
DIRSRC = ./
INCLUDES = ./includes/
OBJ = $(SRC:.c=.o)
SRC =	$(DIRSRC)ft_strlen.c \
		$(DIRSRC)ft_strncat.c \
		$(DIRSRC)ft_strcpy.c \
		$(DIRSRC)ft_strchr.c \
		$(DIRSRC)ft_strdup.c \
		$(DIRSRC)ft_strndup.c \
		$(DIRSRC)ft_strnew.c \
		$(DIRSRC)ft_strnjoin.c \
		$(DIRSRC)ft_memcpy.c \
		$(DIRSRC)ft_lstnew.c

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) -I $(INCLUDES)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean clean all