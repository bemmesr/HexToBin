/* From HexToBin
 * By Richard Depetris
 *
 * Main header for HexToBin functionality.
 */

#ifndef HEX_TO_BIN_HEADER
#define HEX_TO_BIN_HEADER

typedef unsigned char byte;

/* Arguments:
 * 	char *hex		- string in hex format.
 * 	int *size		- pointer to size of hex.
 * Returns:
 * 	byte *			- array of bytes. (must be freed).
 * 	int *size		- pointer to size of byte *.
 */
byte *toBin(char *hex, int *size);

#endif
