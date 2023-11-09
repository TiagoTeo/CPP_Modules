NAME = Materia
C_PP = @c++ -g#-fsanitize=address -g
C_PPFLAGS = -Wall -Wextra -Werror -std=c++98
SRC =	main.cpp \
		AMateria.cpp \
		Character.cpp \
		Cure.cpp \
		Ice.cpp \
		MateriaSource.cpp
OBJ = $(SRC.cpp=.o)

all: $(NAME)

$(NAME):
	$(C_PP) $(C_PPFLAGS) $(SRC) -o $(NAME)

fclean:
	@rm $(NAME)

re: fclean all