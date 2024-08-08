all: 
	clear
	gcc src/main.c -g src/lista/lista.c src/hash/hash.c src/leitura/leitura.c src/patricia/patricia.c src/util/util.c -o bin/exe -lm
	./bin/exe

compile: 
	gcc src/main.c -g src/lista/lista.c src/hash/hash.c src/leitura/leitura.c src/patricia/patricia.c src/util/util.c -o bin/exe -lm

run:
	./bin/exe

testePatricia:#sem teste



# textes realizados: 
# Autor: Gabriel
# 02/08
testeLista:
	clear 
	gcc -g src/tests/teste_lista.c src/lista/lista.c -o bin/testelista
	./bin/testelista

testeHash:
	clear
	gcc -g src/tests/teste_hash.c src/lista/lista.c src/hash/hash.c -o bin/testehash -lm
	./bin/testehash

testeUtil:
	clear 
	gcc -g src/tests/teste_util.c src/util/util.c -o bin/ulilExe
	./bin/ulilExe

testeLeitura:
	clear
	gcc -g src/tests/teste_leitura.c src/lista/lista.c src/hash/hash.c src/leitura/leitura.c src/patricia/patricia.c -o bin/testeLeitura -lm
	./bin/testeLeitura

