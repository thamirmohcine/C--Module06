NAME=IdentifyRealType

CC= c++ 

CPPFLAGS= -std=c++98 -Wall -Wextra -Werror 

SRC= main.cpp Base.cpp A.cpp B.cpp C.cpp Functions.cpp

OBJ= main.o Base.o A.o B.o C.o Functions.o

HEADER= Base.hpp A.hpp B.hpp C.hpp Functions.hpp

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