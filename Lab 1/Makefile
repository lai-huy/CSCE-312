run: clean build
	./main.out

build:
	gcc -g -Wall -Wextra -pedantic-errors -fsanitize=address,undefined -o main.out lab1_prob2.c

clean:
	rm -f *.out *.debug