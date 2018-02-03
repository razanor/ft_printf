# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nrepak <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/15 19:34:18 by nrepak            #+#    #+#              #
#    Updated: 2018/01/16 20:58:58 by nrepak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

SRC := 	ft_printf.c ft_itoa_10.c ft_itoa_unsigned.c auxiliary.c auxiliary2.c Cc.c Ss.c Ddi.c Uu.c Oo.c Xx.c p.c SsC_manipulation.c width_and_precision.c percentage.c     

OBJ_DIR := obj

FLAGS := -Wall -Wextra -Werror

LIBDIR := ./libft

OBJ := $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBDIR)
	@cd $(LIBDIR) && mv *.o ../obj
	@ar rc $(NAME) obj/*.o

$(OBJ_DIR)/%.o: ./%.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(FLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBDIR)
	@rm -rf obj

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C $(LIBDIR)

re: fclean all

.PHONY: all clean fclean re
