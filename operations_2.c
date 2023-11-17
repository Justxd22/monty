#include "monty.h"

/**
 * swap - swap two element onto the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Current line number in the Monty bytecode file
*/
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *n, *t;
	char *arg = strtok(NULL, "\n \t");
	int Pnumber;

	UNUSED(line_number);
	Pnumber = atoi(arg);
	n = malloc(sizeof(stack_t));
	if (n == NULL)
		err(2, "");

	n->n = Pnumber;
	n->prev = NULL;
	n->next = NULL;

	if ((*stack) == NULL)
		*stack = n;
	else
	{
		t = *stack;
		while (t->next != NULL)
			t = t->next;
		t->next = n;
		n->prev = t;
	}
}

/**
 * add - add all the elements of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Current line number in the Monty bytecode file
*/
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *t;

	UNUSED(line_number);
	t = *stack;
	while (t)
	{
		printf("%d\n", t->n);
		t = t->next;
	}
}
