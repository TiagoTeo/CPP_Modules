NAME = Bureaucrat
C_PP = @c++ #-fsanitize=address -g
C_PPFLAGS = -Wall -Wextra -Werror -std=c++98
SRC =	main.cpp \
		Bureaucrat.cpp
OBJ = $(SRC.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(C_PP) $(C_PPFLAGS) $(SRC) -o $(NAME) $(OBJ)

#clean:
#	@rm $(OBJ)

fclean: #clean
	@rm $(NAME)

re: fclean all