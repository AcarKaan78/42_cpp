CC			= c++ -Wall -Wextra -Werror -std=c++98
RM			= rm -rf
NAME		= ./hi
NAME_SHORT	= hi

SRCS_DIR 	= .
SRCS		= $(shell find $(SRCS_DIR) -type f -name "*.cpp")

OBJS		= $(SRCS:.cpp=.o)

%.o			: %.cpp
			@echo "[..] $(NAME_SHORT)... compiling $*.cpp\r\c"
			@$(CC) -c $< -o $@
			@echo "$(_CLEAR)"

all			: $(NAME)

$(NAME)		: $(OBJS)
			@$(CC) $(OBJS) -o $(NAME)
			@echo "$(_OK) $(NAME_SHORT) compiled"

clean		:
			@$(RM) $(OBJS)

fclean		: clean
			@$(RM) $(NAME)

re			: fclean all

.PHONY		: all clean fclean re