/* From HexToBin
 * By Richard Depetris
 *
 * Entry point for cli.
 */

#include "HexToBin.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BAD_ARGS -1
#define BAD_FILE -2

int main(int argc, char **argv) {
	if (argc != 3) {
		fprintf(stderr, "Usage: %s hex file\n", argv[0]);
		return BAD_ARGS;
	}

	FILE *file = fopen(argv[2], "wb");
	if (file == NULL) {
		fprintf(stderr, "Could not open file '%s'\n", argv[2]);
		return BAD_FILE;
	}

	int size = strlen(argv[1]);
	byte *result = toBin(argv[1], &size);
	for (int i = 0; i < size; i++) {
		fputc(result[i], file);
	}
	
	fclose(file);
	free(result);
	return 0;
}
