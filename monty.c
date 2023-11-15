#include "monty.h"


int main(int argc, char **argv)
{
    FILE *f;
    char *line = NULL;
    size_t input_size = 0,

    if (argc != 2)
        err(0, "");

    f = fopen(argv[1], "r");
    if (f == NULL)
        err(1, argv[1]);

    while (getline(&line, &input_size, f) != -1)
    {
        printf("%s", line);
    }

    fclose(f);
}