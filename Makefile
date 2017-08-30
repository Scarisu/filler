# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlecart <rlecart@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/08 16:32:35 by rlecart           #+#    #+#              #
#    Updated: 2017/08/30 20:11:01 by rlecart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT			=	FILLER
NAME			=	rlecart.filler
OBJDIR			=	objs/
SRCDIR			=	srcs/
SRC				=	filler.c \
					map.c \
					frame.c \
					init.c \
					piece.c \
					result.c \
					clear.c
OBJ				=	$(addprefix $(OBJDIR),$(SRC:.c=.o))
LIB				=	lib/libft/libft.a
CC				=	gcc
FLAGS			=	-Wall -Werror -Wextra -Ofast
INCLUDES		=	-I includes/ -I lib/libft/includes/

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ)
	@make -C ./lib/libft
	@printf "[$(PROJECT)] Objs compilation done.                                               \n"
	@$(CC) -o $(NAME) $(OBJ) $(LIB) $(FLAGS) $(FLAGS_MLX)
	@printf "[$(PROJECT)] $(NAME) compiled.                                                    \n"


$(OBJDIR)%.o: $(SRCDIR)%.c
	@printf "[$(PROJECT)] Compiling $< to $@                                                   \r"
	@$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

$(OBJDIR):
	@mkdir objs

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJDIR)
	@make -C ./lib/libft clean
	@printf "[$(PROJECT)] Obj removed.                                                           \n"

fclean: clean
	@rm -f $(LIB)
	@rm -rf $(NAME)
	@printf "[$(PROJECT)] $(NAME) removed.                                                       \n"

re: fclean all

.PHONY: all clean fclean re
