NAME = push_swap

LIBFT_DIR = libft/
LIBFT_FILE = libft.a
LIBFT = $(addprefix $(LIBFT_DIR), $(LIBFT_FILE))
SRCS_DIR = srcs/
SRC_FILES =	push_swap.c \

SRCS_ACTIONS_DIR = actions/
SRC_ACTION_FILES = swap.c \
					push.c \
					rotate.c \
					reverse_rotate.c \
					action_lst.c \

SRCS_PARSING_DIR = srcs/1_parsing/
SRC_PARSING_FILES = checking.c \
					parsing.c \

SRCS_ALGORITHM_DIR = srcs/2_algorithm/
SRC_ALGORITHM_FILES = calculate_utils.c \
					merge_utils.c \
					move_utils.c \
					rotation_utils.c \
					sort_3.c \
					sort_ev.c \

							  
OBJS_DIR =	objs/
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJ_FILES))

OBJS_ACTIONS_DIR = objs/actions/
OBJ_ACTION_FILES = $(SRC_ACTION_FILES:.c=.o)
OBJS_ACTIONS = $(addprefix $(OBJS_ACTIONS_DIR), $(OBJ_ACTION_FILES))

OBJS_PARSING_DIR = objs/parsing/
OBJ_PARSING_FILES = $(SRC_PARSING_FILES:.c=.o)
OBJS_PARSING = $(addprefix $(OBJS_PARSING_DIR), $(OBJ_PARSING_FILES))

OBJS_ALGORITHM_DIR = objs/algorithm/
OBJ_ALGORITHM_FILES = $(SRC_ALGORITHM_FILES:.c=.o)
OBJS_ALGORITHM = $(addprefix $(OBJS_ALGORITHM_DIR), $(OBJ_ALGORITHM_FILES))

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rc
INCLUDE  = -I ./include/ -I ./libft/include/

all: 		$(NAME)

m_libft:
			@make -C $(LIBFT_DIR)

clean: 		
			make -C $(LIBFT_DIR) clean
			@$(RM) $(OBJS)
			@$(RM) $(OBJS_ACTIONS)

fclean: 	clean
			make -C $(LIBFT_DIR) fclean
			@$(RM) $(NAME)

re:			fclean all

$(NAME):	m_libft $(OBJS_DIR) $(OBJS) $(OBJS_ACTIONS_DIR) $(OBJS_ACTIONS) $(OBJS_PARSING_DIR) $(OBJS_PARSING) $(OBJS_ALGORITHM_DIR) $(OBJS_ALGORITHM) 
			@$(CC) $(INCLUDE) $(OBJS) $(OBJS_ACTIONS) $(OBJS_PARSING) $(OBJS_ALGORITHM) -Llibft/ -lft -o $@

$(OBJS_DIR):
						@mkdir $@
$(OBJS_ACTIONS_DIR):
						@mkdir $@
$(OBJS_PARSING_DIR):
						@mkdir $@
$(OBJS_ALGORITHM_DIR):
						@mkdir $@

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
				$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(OBJS_ACTIONS_DIR)%.o:	$(SRCS_ACTIONS_DIR)%.c
				$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(OBJS_PARSING_DIR)%.o:	$(SRCS_PARSING_DIR)%.c
				$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(OBJS_ALGORITHM_DIR)%.o:	$(SRCS_ALGORITHM_DIR)%.c
				$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)



.PHONY: all clean fclean re bonus
