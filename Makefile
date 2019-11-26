
_END=$'\x1b[0m
_BOLD=$'\x1b[1m
_UNDER=$'\x1b[4m
_REV=$'\x1b[7m
# Colors
_GREY=$'\x1b[30m
_RED=$'\x1b[31m
_GREEN=$'\x1b[32m
_YELLOW=$'\x1b[33m
_BLUE=$'\x1b[34m
_PURPLE=$'\x1b[35m
_CYAN=$'\x1b[36m
_WHITE=$'\x1b[37m

PROJECT		=	lem-in
CMPL		=	gcc -g
# FLGS		=	-Wall -Wextra -Werror

NAME		=	lem-in
LIBR		=	libft
LBIN		=	libft/libft.a

HDRS		=	-I./headers
FILENAMES	=	file_manager.c checker.c links.c rooms.c hashing.c bfs.c update_graph.c \
				parents.c queue.c .tools.c main.c groups.c print_results.c del_groups.c

SRC_DIR		=	sources
OBJ_DIR 	=	objects

SRCS		=	$(addprefix $(SRC_DIR)/, $(FILENAMES))
OBJS		=	$(addprefix $(OBJ_DIR)/, $(FILENAMES:.c=.o))

all: $(NAME)

$(NAME):	$(OBJS)
		@make -s -C $(LIBR)
		@$(CMPL) $(FLGS) -o $(NAME) $(SRCS) $(HDRS) $(LBIN)
		@echo "$(_GREEN)[↳]$(_END) $(_BLUE)$(_BOLD)$(_UNDER)$(NAME)$(_END) .. lemme in trough the right path."

$(OBJS): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(HDR) | $(OBJ_DIR)
		@$(CC) $(HDRS) $(FLAGS) -c $< -o $@ 
		@echo "$(_YELLOW)[√]$(_END) Create $@"

$(OBJ_DIR):
		@mkdir $(OBJ_DIR)
		@echo "$(_YELLOW)[√]$(_END) Creating $(OBJ_DIR) folder."

clean:
		@make clean -C $(LIBR)
		@rm -rf  $(OBJ_DIR)
		@echo "$(_RED)[×]$(_END) Cleaning $(PROJECT) objects."

fclean: clean
		@make fclean -C $(LIBR)
		@rm -f $(NAME)
		@echo "$(_BLUE)[↺]$(_END) Back to the 0, where the choice is one."

re: fclean all
