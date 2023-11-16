#include "monty.h"

void err(int code, char *m)
{
		const char *e[] = {"USAGE: monty file", "Error: Can't open file", "Error: malloc failed"};

		if (strlen(m) > 0)
				fprintf(stderr, "%s%s%s\n", e[code], " ", m);
		else
				fprintf(stderr, "%s\n", e[code]);
		exit(EXIT_FAILURE);
}