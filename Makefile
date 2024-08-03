all: 
	clear
	gcc src/main.c src/lista/lista.c src/hash/hash.c src/patricia/patricia.c -o bin/exe -lm
	./bin/exe

compile: 
	gcc src/main.c src/lista/lista.c src/hash/hash.c src/patricia/patricia.c -o bin/exe

run:
	./bin/exe

testeLista:
	gcc -g src/testes/teste_lista.c src/lista/lista.h src/lista/lista.c -o testelista
	./testelista