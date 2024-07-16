all: 
	clear
	gcc src/main.c src/hash/hash.c src/patricia/patricia.c -o exe
	./bin/exe

compile: 
	gcc src/main.c src/hash/hash.c src/patricia/patricia.c -o exe

run:
	./bin/exe
