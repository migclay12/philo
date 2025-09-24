NAME = philo
SRC_DIRS = src
INC_DIR = src

SRCS = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
OBJS = $(SRCS:.c=.o)

# Compilation flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3 -pthread -I$(INC_DIR)
LDFLAGS = -pthread

# Colors for output
GREEN = \033[0;32m
YELLOW = \033[1;33m
RED = \033[0;31m
NC = \033[0m # No Color

.PHONY: all clean fclean re help debug sanitize

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@
	@echo "$(GREEN)✓ Philo compiled successfully!$(NC)"

%.o: %.c
	@echo "$(YELLOW)Compiling $<...$(NC)"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:

	@$(RM) $(OBJS)
	@echo "$(YELLOW)🧹 Object files cleaned!$(NC)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)🗑️  All files cleaned!$(NC)"

re: fclean all

debug: CFLAGS += -g3 -DDEBUG
debug: re
	@echo "$(GREEN)✓ Debug build created!$(NC)"

sanitize: CFLAGS += -fsanitize=thread -g3
sanitize: LDFLAGS += -fsanitize=thread
sanitize: re
	@echo "$(GREEN)✓ Sanitized build created!$(NC)"

help:
	@echo "$(GREEN)Available targets:$(NC)"
	@echo "  all     - Build the project"
	@echo "  clean   - Remove object files"
	@echo "  fclean  - Remove all generated files"
	@echo "  re      - Rebuild everything"
	@echo "  debug   - Build with debug symbols"
	@echo "  sanitize- Build with thread sanitizer"
	@echo "  help    - Show this help message"