#include "ft_push_swap.h"
#include <math.h>

// Vérifier si la liste est triée
int	is_sorted(t_list *lst)
{
	while (lst && lst->next)
	{
		if (lst->data > lst->next->data)
			return (0);
		lst = lst->next;
	}
	return (1);
}

// Trouver la position d'une valeur dans la liste
int	find_pos(t_list *lst, int value)
{
	int	pos;

	pos = 0;
	while (lst)
	{
		if ((int)lst->content == value)
			return (pos);
		lst = lst->next;
		pos++;
	}
	return (-1);
}

// Rotation intelligente : choisir la direction la plus courte
void	smart_rotate(t_list **a, int pos, int size)
{
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rotate_a(a);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
		{
			t_list *last;
			last = *a;
			while (last->next)
				last = last->next;
			last->next = *a;
			*a = (*a)->next;
			last->next->next = NULL;
			ft_printf("rra\n");
		}
	}
}

// Chunk Sort O(n√n)
t_list	*medium_mode(t_list *a, t_list *b)
{
	int	size;
	int	chunk_size;
	int	chunk_id;
	int	i;
	int	pushed;

	if (!a || is_sorted(a))
		return (a);
	size = ft_lstsize(a);
	chunk_size = (int)sqrt(size);
	if (chunk_size < 2)
		chunk_size = 2;
	chunk_id = 0;
	i = 0;
	// Traiter chaque chunk
	while (i < size)
	{
		// Plage du chunk courant : [chunk_id * chunk_size, (chunk_id + 1) * chunk_size[
		if ((int)a->content >= (chunk_id * chunk_size) && 
			(int)a->content < ((chunk_id + 1) * chunk_size))
		{
			push_a_to_b(&a, &b);
			if (b && b->next && (int)b->content < (int)b->next->content)
				rotate_b(&b);
			i++;
		}
		else
			// Rotation intelligente (la plus courte direction)
			smart_rotate(&a, 0, size);
		// Passer au chunk suivant quand on en a poussé assez
		if (i % chunk_size == 0 && i > 0)
			chunk_id++;
	}
	// Repousser les éléments de B vers A
	while (b)
		push_b_to_a(&a, &b);
	return (a);
}
