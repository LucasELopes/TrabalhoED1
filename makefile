all: teste 
	./teste

debug: # Para usar essa flag o vscode tem que ter as extensoes do C/C++ extension pack instalado, o gdb instalado na maquina e o json configurado.
	gcc -g main.c funcoes.c #-Wall -Werror -Wextra 

in: teste 
	./teste < input/2.in

teste: funcoes.o main.o
	gcc -o teste funcoes.o main.o

main.o: main.c funcoes.h
	gcc -c main.c #-Wall -Werror -Wextra

funcoes.o: funcoes.c funcoes.h
	gcc -c funcoes.c #-Wall -Werror -Wextra

clean:
	rm -r teste *.o *.out
	
