all: teste clean

teste: funcoes.o main.o
	gcc -o teste funcoes.o main.o
	./teste
	
main.o: main.c funcoes.h
	gcc -c main.c #-Wall -Werror -Wextra

funcoes.o: funcoes.c funcoes.h
	gcc -c funcoes.c #-Wall -Werror -Wextra

clean:
	rm -r teste *.o
