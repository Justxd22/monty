#include "monty.h"

/**
 * err - Prints an error message then exits with code failure
 *
 * @code: Error code indicating the type of error
 * @m: Additional error message to be displayed
 *
 * Description: Prints error msg based on error code
 */
void err(int code, char *m)
{
	const char *e[] = {"USAGE: monty file", "Error: Can't open file",
	 "Error: malloc failed"};

	if (strlen(m) > 0)
		fprintf(stderr, "%s%s%s\n", e[code], " ", m);
	else
		fprintf(stderr, "%s\n", e[code]);
	exit(EXIT_FAILURE);
}
