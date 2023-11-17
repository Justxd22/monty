#include "monty.h"

/**
 * push - Pushes an element onto the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Current line number in the Monty bytecode file
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *n;
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
		(*stack)->prev = n;
		n->next = *stack;
		*stack = n;
	}
}

/**
 * pall - Prints all the elements of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Current line number in the Monty bytecode file
*/
void pall(stack_t **stack, unsigned int line_number)
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

/**
 * pint - Prints the value at the top of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Current line number in the Monty bytecode file
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - pop elenents
 * @stack: Double pointer to the head of the stack
 * @line_number: Current line number in the Monty bytecode file
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *t;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	t = *stack;
	*stack = (*stack)->next;
	free(t);
}

/**
 * nop - nothing
 * @stack: Double pointer to the head of the stack
 * @line_number: Current line number in the Monty bytecode file
*/
void nop(stack_t **stack, unsigned int line_number)
{
	UNUSED(line_number);
	UNUSED(stack);
}
