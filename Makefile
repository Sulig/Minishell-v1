# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 12:00:39 by sadoming          #+#    #+#              #
#    Updated: 2024/02/21 19:43:22 by sadoming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
# ------------------ #
# Flags:

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
# ------------------ #
# Directories:

ACT_DIR = ./
OBJ_DIR = ./obj
LIB_DIR = ./libft
INC_DIR = ./include
SRC_DIR = ./src
PER_DIR = $(SRC_DIR)/print_errors
# ------------------- #
# Sorces:

LIBFT = $(LIB_DIR)/libft.a
MAK = Makefile

LIBS = $(INC_DIR)/minishell_general_library.h $(INC_DIR)/colors.h

SRC_SRC = minishell_main.c
PER_SRC = print_err_args.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_SRC))
SRC += $(addprefix $(PER_DIR)/, $(PER_SRC))

RSC = $(SRC_SRC) $(PER_SRC)#add other _SRC

TMP = $(SRC:.c=.o)
OBJ = $(addprefix $(OBJ_DIR)/, $(ACT_DIR:.c=.o))
OBJ_SRC = $(addprefix $(OBJ_DIR)/, $(RSC:.c=.o))
# ******************************************************************************* #
#-------------------------------------------------------------#
all: $(NAME)
#-------------------------------------------------------------#
#-------------------------------------------------------------#
help:
	@echo "\033[1;37m\n ~ Posible comands:\n"
	@echo "\t~ all  \t\t #-> Make $(NAME)\n"
	@echo "\t~ clean \t #-> Clean *.o\n"
	@echo "\t~ fclean \t #-> Clean all\n"
	@echo "\t~ clear \t #-> Clean all & clear\n"
	@echo "\t~ norm \t\t #-> Run norminette\n"
	@echo "\t~ run  \t\t #-> Run $(NAME)\n"
	@echo "\t~ re   \t\t #-> Redo $(NAME)\n"
	@make -s author

#-------------------------------------------------------------#
#-------------------------------------------------------------#
author:
	@echo "\033[1;34m\n~ **************************************** ~\n"
	@echo "  ~ \tMade by amagnell && sadoming \t  ~\n"
	@echo "~ **************************************** ~\n\n"
#-------------------------------------------------------------#
#-------------------------------------------------------------#
norm:
	@echo "\n\033[1;93m~ Norminette:\n"
	@norminette -R CheckForbiddenSourceHeader
	@echo "\n~~~~~~~~~~~~~~~~~~~~~~\n"
	@norminette
	@echo "\033[1;32m\n ~ Norminette:\t~ OK\n"
	@echo "~~~~~~~~~~~~~~~~~~~~~~\n"
#-------------------------------------------------------------#
#-------------------------------------------------------------#
run: all
	@echo "\033[1;34m\n~ **************************************** ~\n"
	@echo " ~ Running ./$(NAME)"
	@echo "\n~ **************************************** ~\033[0;37m\n"
	@./$(NAME)
#-------------------------------------------------------------#
#-------------------------------------------------------------#
# ******************************************************************************* #
# Compiling Region:

$(LIBFT):
	@echo "\033[1;93m\n * Compiling Libft -->\033[1;97m\n"
	@make -s -C $(LIB_DIR)
	@echo "\033[1;37m~ **************************************** ~\n"

%.o: %.c $(LIB) $(MAK)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@echo " Compiling OBJS for $(NAME)\033[0;97m\n"
	@mkdir -p $(OBJ_DIR)

$(OBJ): $(OBJ_DIR) $(TMP)
	@mv -f $(TMP) $(OBJ_DIR)
	@echo "\033[1;35m\n OBJS for $(NAME) created succesfuly\n"

$(NAME): $(MAK) $(LIBFT) $(OBJ)
	@echo "\033[1;93m * Making $(NAME) -->\033[1;97m\n"
	$(CC) $(LIBFT) $(OBJ_SRC) -o $(NAME)
	@echo "\033[1;32m\n $(NAME) Compiled Successfully\033[1;97m\n"

# ********************************************************************************* #
# Clean region

clean:
	@make -s clean -C $(LIB_DIR)
	@/bin/rm -frd $(OBJ_DIR)
	@/bin/rm -f $(TMP)
	@echo "\033[1;34m\n All obj removed\033[1;97m\n"


fclean: clean
	@make -s fclean -C $(LIB_DIR)
	@/bin/rm -f $(NAME)
	@find . -name ".DS_Store" -type f -delete
	@echo "\033[1;34m All cleaned succesfully\033[1;97m\n"

clear: fclean
	@clear

re: fclean all
# -------------------- #
.PHONY: all author clean clear fclean help norm re
# ********************************************************************************** #
