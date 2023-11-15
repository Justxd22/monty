#include "monty.h"


int main(int argc, char **argv)
{
    FILE *f;
    char *line = NULL;

    if (argc != 2)
        err(0, "");

    f = fopen(argv[1], "r");
    if (f == NULL)
        err(1, argv[1]);

    while (getline(&line, sizeof(line), f) != -1)
    {
        printf("%s", line);
    }

    fclose(f);
}