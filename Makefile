# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/08 16:32:35 by pbernier          #+#    #+#              #
#    Updated: 2017/08/18 14:59:16 by pbernier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT			=	FILLER
NAME			=	pbernier.filler
BINDIR			=	bin/
SRCDIR			=	src/
SRC				=	filler.c
OBJ				=	$(addprefix $(BINDIR),$(SRC:.c=.o))
LIB				=	libft/libft.a
CC				=	gcc
FLAGS			=	-Wall -Werror -Wextra -Ofast
INCLUDES		=	-I includes/ -I libft/includes/

all: $(NAME)

$(NAME): $(BINDIR) $(OBJ)
	@make -C libft
	@printf "[$(PROJECT)] Bin compilation done.                                                \n"
	@$(CC) -o $(NAME) $(OBJ) $(LIB) $(FLAGS)
	@printf "[$(PROJECT)] $(NAME) compiled.                                                    \n"


$(BINDIR)%.o: $(SRCDIR)%.c
	@printf "[$(PROJECT)] Compiling $< to $@                                                   \r"
	@$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

$(BINDIR):
	@mkdir bin

clean:
	@rm -f $(OBJ)
	@rm -rf $(BINDIR)
	@make -C libft clean
	@printf "[$(PROJECT)] Obj removed.                                                           \n"

fclean: clean
	@rm -f $(LIB)
	@rm -rf $(NAME)
	@printf "[$(PROJECT)] $(NAME) removed.                                                       \n"


re: fclean all

.PHONY: all clean fclean re
