/* From HexToBin
 * By Richard Depetris
 *
 * Main implementation for HexToBin internals.
 */

#include "HexToBin.h"

#include <stdlib.h>

byte toByte(char hex) {
	if (hex >= '0' && hex <= '9') {
		return hex - '0';
	}
	if (hex >= 'a' && hex <= 'f') {
		return hex - 'a' + 10;
	}
	if (hex >= 'A' && hex <= 'F') {
		return hex - 'A' + 10;
	}
	return 0;
}

byte *toBin(char *hex, int *size) {
	byte buffer[*size];
	int bufferIndex = 0;
	for (int i = 0; i < *size; i++) {
		if (hex[i] == '0' && hex[i + 1] == 'x') {
			byte value = toByte(hex[i + 2]);
			value *= 16;
			value += toByte(hex[i + 3]);
			buffer[bufferIndex] = value;
			bufferIndex++;
		}
	}

	byte *result = malloc(bufferIndex);
	for (int i = 0; i < bufferIndex; i++) {
		result[i] = buffer[i];
	}
	*size = bufferIndex;
	return result;
}
