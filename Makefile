NAME = philo
SRC_DIRS = .
INC_DIR = includes

SRCS = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@gcc $(FLAGS) $^ -o $@
	@echo "Philo compiled!"

%.o: %.c
	@echo "Compiling $<..."
	@gcc $(FLAGS) -c $< -o $@

exe: all 
	@./$(NAME) 5 800 200 200 2

leak: all
	valgrind --leak-check=full ./$(NAME) 5 800 200 200 2

clean:
	@$(RM) $(OBJS)
	@echo "Philo cleaned!"

fclean: clean
	@$(RM) $(NAME)

re: fclean all

#valgrind --leak-check=full ./philo