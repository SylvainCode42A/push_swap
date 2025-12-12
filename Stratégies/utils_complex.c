#include "ft_push_swap.h"

int size_list(t_list *stack)
{
	int count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

int size_max_bit(int max)
{
	int max_bit;

	max_bit = 0;
	while (((max >> max_bit) & 1) != 0)
		max_bit++;
	return (max_bit);
}

int search_max(t_list **a)
{
	t_list 	*use;
	int 	count;
	int 	size;

	use = *a;
	count = 0;
	while (use)
	{
		if (count < use->data)
			count = use->data;
		use = use->next;
	}
	return (size_max_bit(count));
}