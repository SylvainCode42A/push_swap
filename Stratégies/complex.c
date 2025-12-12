#include "ft_push_swap.h"

void radix_sort(t_list **a, t_list **b, int count, int i)
{
	size_t bit;

	while (count > 0)
	{
		bit = ((*a)->data >> i) & 1;
		if (bit == 1)
			rotate_a(a);
		else
			push_a_to_b(a, b);
		count--;
	}
}

void complex_mode(t_list **a, t_list **b)
{
	size_t i;
	int max_bit;
	int count;

	i = 0;
	max_bit = search_max(*a);
	while (i < max_bit)
	{
		count = size_list(*a);
		radix_sort(a, b, count, i);
		count = size_list(b);
		if (count)
		{
			while (count > 0)
			{
				push_b_to_a(a, b);
				count--;
			}
		}
		i++;
	}
}
