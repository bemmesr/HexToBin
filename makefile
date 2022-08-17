main: src/main.c src/HexToBin.c bin
	gcc src/main.c src/HexToBin.c -o bin/main

bin:
	mkdir bin
