# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slyazid <slyazid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/15 00:41:25 by slyazid           #+#    #+#              #
#    Updated: 2019/07/12 17:13:37 by slyazid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT     = libft
CC          = gcc
FLAGS       = -Wall -Wextra -Werror
NAME        = libft.a

FILENAMES = ft_atoi.c ft_atoi_base.c ft_itoa.c  ft_lstmap.c  ft_memcpy.c ft_putendl_fd.c ft_strchr.c ft_striter.c ft_strncat.c ft_strsplit.c ft_trim_delim.c \
			ft_bzero.c ft_lstadd.c ft_lstnew.c ft_memdel.c ft_putlst.c ft_strclr.c ft_striteri.c ft_strncmp.c ft_strstr.c ft_wlength.c \
			ft_isalnum.c ft_lstadd_elt.c ft_lstsize.c ft_memmove.c ft_putnbr.c ft_strcmp.c ft_strjoin.c ft_strnjoin.c ft_strncpy.c ft_strsub.c get_next_line.c\
			ft_isalpha.c ft_lstdel.c ft_memalloc.c ft_memset.c ft_putnbr_fd.c ft_strcpy.c ft_strlcat.c ft_strnequ.c ft_strtrim.c\
			ft_isascii.c ft_lstdel_elt.c ft_memccpy.c ft_putchar.c ft_putstr.c ft_strdel.c ft_strlen.c ft_strnew.c ft_strwcount.c\
			ft_isdigit.c ft_lstdelone.c ft_memchr.c ft_putchar_fd.c ft_putstr_fd.c ft_strdup.c ft_strmap.c ft_strnstr.c ft_tolower.c\
			ft_isprint.c ft_lstiter.c ft_memcmp.c ft_putendl.c ft_strcat.c ft_strequ.c ft_strmapi.c ft_strrchr.c ft_toupper.c 

ODIR		= obj
HDR			=  libft.h
OBJ			=  $(addprefix $(ODIR)/, $(FILENAMES:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	    @ar rc $(NAME) $(OBJ)

$(OBJ): $(ODIR)/%.o : %.c $(HDR) | $(ODIR)
	    @$(CC) $(FLAGS) -c $< -o $@

$(ODIR):
	    @mkdir $(ODIR)

clean:
	    @rm -rf  $(ODIR)

fclean: clean
	    @rm -f $(NAME)

re: fclean all 
