SRC = src/*.c

all:
	cc -Wall -Werror -Wextra $(SRC) -Iinc -o snake
