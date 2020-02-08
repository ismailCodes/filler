_lCYAN = \x1b[96m
_lYELLOW = \x1b[93m
_lGREEN = \x1b[92m
_lBLUE = \x1b[94m
_RED = \x1b[31m
_BOLD = \x1b[1m
_END = \x1b[0m

CC = gcc
NAME = ismail.filler
FILENAMES = test.c get_next_line.c board_utils.c heatmap.c\
			piece_utils.c

HEADER_FILE = ./inc/filler.h
SRC_DIR = ./src
OBJ_DIR = ./obj
INC_DIR = ./inc

SRC = $(addprefix $(SRC_DIR)/, $(FILENAMES))
OBJ = $(addprefix $(OBJ_DIR)/, $(FILENAMES:.c=.o))

FLAGS		= -Wall -Werror -Wextra
LIBFT		= ./libs/libft/libft.a
LIBFT_DIR	= ./libs/libft
INCLUDES	= -I ./libs/libft\
			  -I ./inc
LIBRARIES	= -L ./libs/libft -lft

DELAY = 0

all : $(NAME)
$(NAME): $(LIBFT) $(OBJ)
	@echo "$(CC) $(_lYELLOW)$(FLAGS)$(_END) $(_lCYAN)$(OBJ)$(_END)\n$(_lGREEN) $(LIBRARIES)$(_END)   --include-dir$(_RED)$(INC_DIR)$(_END)$(_RED)$(INCLUDES)$(_END) -o $(_lBLUE)$(NAME)$(_lEND)$(_RED)\n"
	@$(CC) $(FLAGS) $(OBJ) $(LIBRARIES) $(INCLUDES) -o $(NAME)
	#@ar -rcs $(NAME) $(OBJ) libs/libft/*.o
$(OBJ): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(HEADER_FILE) | $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@ -I  $(INC_DIR) $(INCLUDES)
$(OBJ_DIR):
	@mkdir $(OBJ_DIR)
$(LIBFT):
	@make -C $(LIBFT_DIR)
clean:
	@echo "\n$(_lCYAN)Makefile :$(_END) will delete $(_RED)$(OBJ) $(VIS_OBJ)$(_END)"
	@echo "starting in $(DELAY) sec, $(_RED)press Ctrl-c to abort$(_END)"
	@sleep $(DELAY)
	@make -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)
fclean: clean
	@echo "\n$(_lCYAN)Makefile :$(_END) will delete $(_RED)$(NAME)$(_END)"
	@echo "starting in $(DELAY) sec, $(_RED)press Ctrl-c to abort$(_END)"
	@sleep $(DELAY)
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
re: fclean all