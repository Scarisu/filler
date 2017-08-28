# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/08 16:32:35 by pbernier          #+#    #+#              #
#    Updated: 2017/08/28 16:45:08 by pbernier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT			=	FILLER
NAME			=	pbernier.filler
BINDIR			=	bin/
SRCDIR			=	src/
SRC				=	filler.c \
					map.c \
					frame.c \
					init.c \
					piece.c \
					result.c \
					clear.c
OBJ				=	$(addprefix $(BINDIR),$(SRC:.c=.o))
LIB				=	lib/libft/libft.a
CC				=	gcc
FLAGS			=	-Wall -Werror -Wextra -Ofast
DFLAGS			=	
FLAGS_MLX		=
INCLUDES		=	-I includes/ -I lib/libft/includes/ -I lib/minilibx_macos_sierra/

all: $(NAME)

$(NAME): $(BINDIR) $(OBJ)
	@make -C ./lib/libft
	@printf "[$(PROJECT)] Bin compilation done.                                                \n"
	@$(CC) -o $(NAME) $(OBJ) $(LIB) $(FLAGS) $(FLAGS_MLX) $(DFLAGS)
	@printf "[$(PROJECT)] $(NAME) compiled.                                                    \n"


$(BINDIR)%.o: $(SRCDIR)%.c
	@printf "[$(PROJECT)] Compiling $< to $@                                                   \r"
	@$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $< $(DFLAGS)

$(BINDIR):
	@mkdir bin

clean:
	@rm -f $(OBJ)
	@rm -rf $(BINDIR)
	@make -C ./lib/libft clean
	@printf "[$(PROJECT)] Obj removed.                                                           \n"

fclean: clean
	@rm -f $(LIB)
	@rm -rf $(NAME)
	@printf "[$(PROJECT)] $(NAME) removed.                                                       \n"

re: fclean all

.PHONY: all clean fclean re
