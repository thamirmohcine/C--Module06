NAME=Serialization

CC= c++ 

CPPFLAGS= -std=c++98 -Wall -Wextra -Werror 

SRC= main.cpp Serializer.cpp 

OBJ= main.o Serializer.o 

HEADER= Serializer.hpp 

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADER)
	$(CC) $(CPPFLAGS) $< -c -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all