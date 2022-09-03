run: all

all: build_1 build_2

build_1: clean
	gcc -std=c99 -g -Wall -Wextra -pedantic-errors -o main.out lab1_prob1.c
	./main.out

build_2: clean
	gcc -std=c99 -g -Wall -Wextra -pedantic-errors -o main.out lab1_prob2.c
	./main.out

build_3: clean
	gcc -std=c99 -g -Wall -Wextra -pedantic-errors -o main.out lab1_prob3_framework.c
	./main.out

build_4: clean
	gcc -std=c99 -g -Wall -Wextra -pedantic-errors -o main.out lab1_prob4_framework.c
	./main.out

build_5: clean
	gcc -o main.out lab1_prob5_framework.c
	./main.out

clean:
	rm -f *.out *.debug