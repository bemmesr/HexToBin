main: src/main.c src/HexToBin.c bin
	gcc src/main.c src/HexToBin.c -o bin/main

debug: src/main.c src/HexToBin.c bin
	gcc src/main.c src/HexToBin.c -o bin/main -g

bin:
	mkdir bin
