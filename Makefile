# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhoorntj <rhoorntj@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/27 16:28:36 by rhoorntj          #+#    #+#              #
#    Updated: 2020/07/19 18:02:00 by rhoorntj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rhoorntj.filler
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBFT = $(LIBDIR)libft.a
SRCDIR = ./src/
OBJDIR = ./obj/
LIBDIR = ./libft/
INCL = ./includes/

FILES = $(shell find src -type f | grep -E "\.c$$" | sed 's/src//g')
SRC = $(addprefix $(SRCDIR), $(FILES))
OBJ = $(addprefix $(OBJDIR), $(FILES:.c=.o))
SRCSUBDIR = $(shell find ./src -type d)
OBJSUBDIR = $(SRCSUBDIR:./src%=./obj%)
LONGEST = $(shell echo $(notdir $(SRC)) | tr " " "\n" | \
	awk ' { if ( lenght > x ) { x = lenght; y = $$0 } }END{ print y }' | wc -c )

all: lib $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCL)
	@$(CC)  -o $@ -c $< $(FLAGS)

lib:
	@make -C $(LIBDIR)

$(OBJSUBDIR):
	@mkdir $@

$(NAME): $(OBJSUBDIR) $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT)

clean:
	@rm -rf $(OBJDIR)
	@make -C $(LIBDIR) clean

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBFT)

re: fclean all

.PHONY: clean fclean re all
