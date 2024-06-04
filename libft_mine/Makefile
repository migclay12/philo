NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
OPTIONS = -c -I.
AR = ar rc
RM = rm -f

SRC_DIR = src
INC_DIR = includes
OBJ_DIR = obj

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling libft..."
	@$(AR) $@ $^
	@echo "Libft compiled!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(OPTIONS) -o $@ $<
#@echo "Compiling: $<"

$(OBJ_DIR):
	mkdir -p $@

clean:
	@$(RM) $(OBJ)
	@echo "Libft cleaned!"

fclean: clean
	@$(RM) $(NAME)

re: fclean all