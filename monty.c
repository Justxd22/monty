#include "monty.h"

/**
 * exc_func - Creates an instruction_t structure
 * @l: Input line of code
 * Return: Pointer to the created instruction_t structure
*/
instruction_t *exc_func(char *l)
{
	char *code;
	instruction_t *queue;

	code = strtok(l, "\n\t ");
	queue = malloc(sizeof(*queue));
	if (queue == NULL)
		err(2, "");
	queue->opcode = code;
	queue->f = NULL;
	if (strcmp(code, "push") == 0)
		queue->f = push;
	else if (strcmp(code, "pall") == 0)
		queue->f = pall;
	else if (strcmp(code, "pint") == 0)
		queue->f = pint;
	else if (strcmp(code, "pop") == 0)
		queue->f = pop;
	else if (strcmp(code, "swap") == 0)
		queue->f = swap;
	else if (strcmp(code, "add") == 0)
		queue->f = add;
	else if (strcmp(code, "nop") == 0)
		queue->f = nop;

	return (queue);
}

/**
 * freeLIST - Frees the memory allocated for a linked list
 * @h: The head of the linked list
*/
void freeLIST(stack_t *h)
{
	stack_t *n;

	if (!h)
		return;

	n = h;
	while (n)
	{
		h = n;
		n = h->next;
		free(h);
	}
}

/**
 * main - Main function of the Monty interpreter
 * @argc: The number of CL args
 * @argv: An array of strings containing the CL args
 *
 * Return: 0 on success & error code on failure
*/
int main(int argc, char **argv)
{
	FILE *f;
	char *line = NULL;
	unsigned int n = 0, r = 0;
	size_t input_size = 0;
	instruction_t *exec = NULL;
	stack_t *list = NULL;

	if (argc != 2)
		err(0, "");

	f = fopen(argv[1], "r");
	if (f == NULL)
		err(1, argv[1]);

	while (getline(&line, &input_size, f) != -1)
	{
		if (!line)
			continue;
		n++, exec = exc_func(line);

		if (!exec->f)
			fprintf(stderr, "L%d: unknown instruction %s\n", n, exec->opcode), r = -1;
		else if (exec->opcode[0] == '#')
			r = 0;
		else
			exec->f(&list, n);

		free(exec), free(line), line = NULL;
		if (r != 0)
		{
			if (list)
				freeLIST(list);
			exit(EXIT_FAILURE);
		}
		continue;
	}

	freeLIST(list), fclose(f);
	return (0);
}
