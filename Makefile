# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amagnell <amagnell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 12:00:39 by sadoming          #+#    #+#              #
#    Updated: 2024/03/04 19:49:19 by sadoming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
# ------------------ #
# Flags:

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
CPPFLAGS = -MMD -MP
LDFLAGS = $(addprefix -L, $(dir $(LIBFT)))
INCLUDE = -I ./readline/ -I $(INC_DIR)/ -I $(LIB_DIR)/include/ 
# ------------------ #
# Directories:

OBJ_DIR = ./obj
LIB_DIR = ./libft
RDL_DIR = ./readline
INC_DIR = ./include

# Minishell SRC Directories:
SRC_DIR = ./src
BLT_DIR = $(SRC_DIR)/builtins
PER_DIR = $(SRC_DIR)/print_errors
UTL_DIR = $(SRC_DIR)/utils
# ------------------- #
# Sources:
MAK = Makefile # This Makefile

LIBFT = $(LIB_DIR)/libft.a # The Libft

# Readline libraries ->
READLINE = ./readline/libreadline.a
HISTORY = ./readline/libhistory.a

# HEADERS
HEADERS = $(INC_DIR)/ $(LIB_DIR)/include/

# MINISHELL SRC ->

SRC_SRC = minishell_main.c minishell_welcome.c ft_readline.c tokenize_com.c\
		  manage_structs.c
BLT_SRC = echo.c 
PER_SRC = print_common_errors.c
UTL_SRC = print_all_arrstr.c signals.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_SRC))
SRC += $(addprefix $(BLT_DIR)/, $(BLT_SRC))
SRC += $(addprefix $(PER_DIR)/, $(PER_SRC))
SRC += $(addprefix $(UTL_DIR)/, $(UTL_SRC))

OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))
#OBJS = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

DEPS = $(OBJS:%.o=%d)
-include $(DEPS)
# ******************************************************************************* #
#-------------------------------------------------------------#
all: $(LIBFT) $(NAME) 
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
	@norminette -R CheckForbiddenSourceHeader $(LIB_DIR)
	@norminette -R CheckForbiddenSourceHeader $(HEADERS)
	@norminette -R CheckForbiddenSourceHeader $(SRC_DIR)
	@echo "\n~~~~~~~~~~~~~~~~~~~~~~\n"
	@norminette $(LIB_DIR)
	@norminette $(HEADERS)
	@norminette $(SRC_DIR)
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

# LIBFT ->
$(LIBFT): 
	@echo "\033[0;33m\n * Compiling Libft -->\033[0;37m\n"
	@make -s -C $(LIB_DIR)
	@echo "\033[1;37m~ **************************************** ~\n"
# ----------------------------------------
# READLINE ->

$(READLINE):
	@echo "\033[0;33m * Compiling Readline -->\033[0;37m\n"
	@echo " Plesase wait a bit\n"
	@make -s -C $(RDL_DIR)
	@echo "\033[1;37m~ **************************************** ~\n"
# ----------------------------------------
# MINISHELL ->

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(LIBFT) $(HEADERS)
	@echo "\033[0;37m Compiling...: $<"
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -D READLINE_LIBRARY=1 -c $< -o $@ $(INCLUDE)

$(NAME): $(MAK) $(HEADERS) $(LIBFT) $(READLINE) $(OBJS)
	@echo "\033[1;93m\n * Making $(NAME) -->\033[0;37m\n"
	$(CC) $(LDFLAGS) $(CFLAGS) $(OBJS) -l ft $(READLINE) $(HISTORY) -ltermcap -lreadline -o $(NAME)
	@echo "\033[1;32m\n $(NAME) Compiled Successfully\033[0;37m\n"

# ********************************************************************************* #
# ********************************************************************************* #
# Debugging region:

debug: $(NAME)
	@echo " ~ Debugging ./$(NAME)"
	@lldb $(NAME)

# ------------------

leaks: $(NAME)
	@echo " ~ Running leaks -atExit -- ./$(NAME)"
	@leaks -atExit -- ./$(NAME)

# ------------------

val: $(NAME)
	@echo " ~ Running valgrind ./$(NAME)"
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

# ********************************************************************************* #
# Clean region

clean:
	@make -s clean -C $(LIB_DIR)
	@make -s clean -C $(RDL_DIR)
	@/bin/rm -frd $(OBJ_DIR)
	@echo "\033[1;34m\n All obj removed\033[1;97m\n"


fclean: clean
	@make -s fclean -C $(LIB_DIR)
	@/bin/rm -f $(NAME)
	@/bin/rm -frd $(NAME).dSYM
	@find . -name ".DS_Store" -type f -delete
	@echo "\033[1;34m All cleaned succesfully\033[1;97m\n"

clear: fclean
	@clear

re: fclean all
# -------------------- #
.PHONY: all author clean clear debug fclean help leaks norm re run val
# ********************************************************************************** #
