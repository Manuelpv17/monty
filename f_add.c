#include "monty.h"

/**
 * f_add - adds the top two elements of the stack.
 * @stack: head of linked list (stack)
 * @line_number: counter lines
 */
void f_add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free(global_var.buffer);
		free_loop(global_var.words);
		free_stack(*stack);
		fclose(global_var.fd);
		exit(EXIT_FAILURE);
	}

	while (temp->next != NULL)
		temp = temp->next;

	temp->prev->n += temp->n;
	f_pop(stack, line_number);
}
