NAME = ScavTrap
C_PP = @c++ #-fsanitize=address -g
C_PPFLAGS = -Wall -Wextra -Werror -std=c++98
SRC =	main.cpp \
		ClapTrap.cpp \
		ScavTrap.cpp
OBJ = $(SRC.cpp=.o)

all: $(NAME)

$(NAME):
	$(C_PP) $(C_PPFLAGS) $(SRC) -o $(NAME)

fclean:
	@rm $(NAME)

re: fclean all