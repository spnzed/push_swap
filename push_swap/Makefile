
NAME = push_swap

SRCS_DIR = srcs/
SRC_FILES =	push_swap.c \

SRCS_ACTIONS_DIR = 		srcs/actions/
SRC_ACTION_FILES = 		swap.c \
						push.c \
						rotate.c \
						reverse_rotate.c \

SRCS_MAIN_DIR = 		srcs/main/
SRC_MAIN_FILES = 		error_free.c \
						genstack.c \
						nodes_back.c \
						nodes_init.c \
						nodes_move.c \
						sort.c \

SRCS_UTILS_DIR = 		srcs/utils/
SRC_UTILS_FILES = 		ft_atoi.c \
						ft_atol.c \
						ft_error_message.c \
						ft_find_biggest.c \
						ft_find_smallest.c \
						ft_free_stack.c \
						ft_free_argv.c \
						ft_isdigit.c \
						ft_lst_last.c \
						ft_lst_size.c \
						ft_lst_sorted.c \
						ft_lstadd_flinked.c \
						ft_lstadd_blinked.c \
						ft_num_begins.c \
						ft_putstr_fd.c \
						ft_split.c \
						ft_strlen.c \

OBJS_DIR =	objs/
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJ_FILES))

OBJS_ACTIONS_DIR = objs/actions/
OBJ_ACTION_FILES = $(SRC_ACTION_FILES:.c=.o)
OBJS_ACTIONS = $(addprefix $(OBJS_ACTIONS_DIR), $(OBJ_ACTION_FILES))

OBJS_MAIN_DIR = objs/main/
OBJ_MAIN_FILES = $(SRC_MAIN_FILES:.c=.o)
OBJS_PARSING = $(addprefix $(OBJS_MAIN_DIR), $(OBJ_MAIN_FILES))

OBJS_UTILS_DIR = objs/utils/
OBJ_UTILS_FILES = $(SRC_UTILS_FILES:.c=.o)
OBJS_ALGORITHM = $(addprefix $(OBJS_UTILS_DIR), $(OBJ_UTILS_FILES))

DEPS = $(SRC_FILES.c=.d) $(SRC_ACTION_FILES.c=.d) $(SRC_MAIN_FILES.c=.d) $(SRC_UTILS_FILES.c=.d))

CC = gcc
CFLAGS = -Wall -Wextra -Werror -MMD
RM = rm -f
AR = ar rc
INCLUDE = -I include

all: 		$(NAME)

clean:
			@$(RM) $(OBJS)
			@$(RM) $(OBJS_ACTIONS)
			@$(RM) $(OBJS_ALGORITHM)
			@$(RM) $(OBJS_PARSING)

fclean: 	clean
			@$(RM) $(NAME)
			@$(RM) -rf $(OBJS_DIR)

re:			fclean all

$(NAME):	$(OBJS_DIR) $(OBJS) $(OBJS_ACTIONS_DIR) $(OBJS_ACTIONS) $(OBJS_MAIN_DIR) $(OBJS_PARSING) $(OBJS_UTILS_DIR) $(OBJS_ALGORITHM)
			@$(CC) $(CFLAGS) $(OBJS) $(OBJS_ACTIONS) $(OBJS_PARSING) $(OBJS_ALGORITHM) -o $@

$(OBJS_DIR):
						@mkdir $@
$(OBJS_ACTIONS_DIR):
						@mkdir $@
$(OBJS_MAIN_DIR):
						@mkdir $@
$(OBJS_UTILS_DIR):
						@mkdir $@

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c Makefile include/push_swap.h
				$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJS_ACTIONS_DIR)%.o:	$(SRCS_ACTIONS_DIR)%.c Makefile include/push_swap.h
				$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJS_MAIN_DIR)%.o:	$(SRCS_MAIN_DIR)%.c Makefile include/push_swap.h
				$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJS_UTILS_DIR)%.o:	$(SRCS_UTILS_DIR)%.c Makefile include/push_swap.h
				$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

-include $(DEPS)

.PHONY: all clean fclean re bonus
