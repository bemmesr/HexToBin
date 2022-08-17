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
	char *source = NULL;
	int out = 2;
	if (argc == 4) {
		char fileFlag[] = "-from";
		if (strcmp(fileFlag, argv[1]) == 0) {
			FILE *in = fopen(argv[2], "r");
			if (in == NULL) {
				fprintf(stderr, "Could not open file '%s'\n", argv[2]);
				return BAD_FILE;
			}
			fseek(in, 0, SEEK_END);
			int length =ftell(in);
			source = malloc(length);
			fseek(in, 0, SEEK_SET);
			fread(source, 1, length, in);
			fclose(in);
			out = 3;
		}
	} else if (argc == 3) {
		source = malloc(strlen(argv[1]) + 1);
		strcpy(source, argv[1]);
	} else {
		fprintf(stderr, "Usage: %s (hex/-from file) file\n", argv[0]);
		return BAD_ARGS;
	}

	FILE *file = fopen(argv[out], "wb");
	if (file == NULL) {
		fprintf(stderr, "Could not open file '%s'\n", argv[out]);
		return BAD_FILE;
	}

	int size = strlen(source);
	byte *result = toBin(source, &size);
	for (int i = 0; i < size; i++) {
		fputc(result[i], file);
	}
	
	fclose(file);
	free(result);
	if (source != NULL) {
		free(source);
	}
	return 0;
}
