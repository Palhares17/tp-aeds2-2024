all: 
	clear
	gcc src/main.c src/hash/hash.c src/patricia/patricia.c -o bin/exe -lm
	./bin/exe

compile: 
	gcc src/main.c src/hash/hash.c src/patricia/patricia.c -o bin/exe

run:
	./bin/exe
