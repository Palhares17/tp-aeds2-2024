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

testeHash:
	gcc -g src/testes/teste_hash.c src/lista/lista.h src/lista/lista.c src/hash/hash.h src/hash/hash.c -o testehash
	./testehash

testeLeitura:
	gcc -g src/testes/teste_leitura.c src/lista/lista.h src/lista/lista.c src/hash/hash.h src/hash/hash.c  src/leitura/leitura.h src/leitura/leitura.c -o testeleitura
	./testeleitura
