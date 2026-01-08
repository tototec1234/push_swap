# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toruinoue <toruinoue@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/01 21:34:56 by torinoue          #+#    #+#              #
#    Updated: 2026/01/08 17:32:14 by toruinoue        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
DEBUGFLAGS = -g -fsanitize=address

ifeq ($(MAKECMDGOALS),debug)
	CFLAGS += $(DEBUGFLAGS)
endif

IFLAGS = -I$(INC_DIR)
NAME = push_swap
BONUS_NAME = checker
INC_DIR = includes
SRC_DIR = srcs
OBJ_DIR = objs

LIBFT_DIR = libft
LIBFT = ${LIBFT_DIR}/libft.a
LIB = -L $(LIBFT_DIR) -lft

MAIN_DIR = $(SRC_DIR)/main
MAIN = $(MAIN_DIR)/push_swap.c\
	$(MAIN_DIR)/validate_argv.c\

PROCESS_DIR = $(SRC_DIR)/processes
PROCESSES = $(PROCESS_DIR)/ctrl_process.c\
	$(PROCESS_DIR)/a_back_to_b.c\
	$(PROCESS_DIR)/a_initial_partition_half_a.c\
	$(PROCESS_DIR)/a_partition_half_a.c\
	$(PROCESS_DIR)/b_partition_half_b.c\
	$(PROCESS_DIR)/b_sort_b.c\
	$(PROCESS_DIR)/sort_under_six.c\
	$(PROCESS_DIR)/sort_2_to_4_elemnts.c\


UTILS_DIR = $(SRC_DIR)/utils
UTILS = $(UTILS_DIR)/main_argv_utils.c\
	$(UTILS_DIR)/main_initial_stac_a_b.c\
	$(UTILS_DIR)/main_validate_args.c\
	$(UTILS_DIR)/push_swap_utils.c\
	$(UTILS_DIR)/operator_push.c\
	$(UTILS_DIR)/operator_reverse_rotate.c\
	$(UTILS_DIR)/operator_rotate.c\
	$(UTILS_DIR)/operator_swap.c\
	$(UTILS_DIR)/under_6_rec_utils.c\
	$(UTILS_DIR)/get_current_pos.c\
	$(UTILS_DIR)/partition_a_utils.c\
	$(UTILS_DIR)/stack_management.c\
	$(UTILS_DIR)/stack_analysis.c\
	$(UTILS_DIR)/under_6_list_management.c\
	$(UTILS_DIR)/write_stdout.c\
	$(UTILS_DIR)/write_err.c\

SRCS = $(MAIN)\
	$(UTILS)\
	$(PROCESSES)\

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

BONUS_DIR = $(SRC_DIR)/bonus
BONUS = $(BONUS_DIR)/checker_bonus.c\
	$(BONUS_DIR)/checker_utils_bonus.c\
	$(BONUS_DIR)/stack_operations_bonus.c\
	$(BONUS_DIR)/parse_utils_bonus.c\
	$(BONUS_DIR)/instructions_swap_bonus.c\
	$(BONUS_DIR)/instructions_push_bonus.c\
	$(BONUS_DIR)/instructions_rotate_bonus.c\
	$(BONUS_DIR)/instructions_reverse_rotate_bonus.c

BONUS_OBJS = $(BONUS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

vpath %.c $(SRC_DIR)

all: $(LIBFT) $(OBJ_DIR) $(NAME)

$(LIBFT):
	@make $(MAKECMDGOALS) -C $(LIBFT_DIR);

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ $(LIB)  -o $@	

$(OBJ_DIR)/%.o: %.c $(INC_DIR)/push_swap.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "\033[31mObject files are removed\033[0m"

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@echo "\033[31m$(NAME) is removed\033[0m"

re: fclean all

debug: fclean all

bonus: $(LIBFT) $(OBJ_DIR) $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $^ $(LIB) -o $@

.PHONY: all clean fclean re debug bonus