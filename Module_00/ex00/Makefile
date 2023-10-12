NAME = megaphone
C_PP = @c++
C_PPFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = megaphone.cpp
OBJ = $(SRC.cpp=.o)

all: $(NAME)

$(NAME):
	$(C_PP) $(C_PPFLAGS) $(SRC) -o $(NAME)

fclean:
	@rm $(NAME)

re: fclean all
