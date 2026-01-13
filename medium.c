#include "ft_push_swap.h"

// Calcul de la taille d'une liste
int ft_lstsize(t_list *lst)
{
    int size = 0;
    while (lst)
    {
        lst = lst->next;
        size++;
    }
    return size;
}

// Racine carrée entière
int ft_sqrt(int size)
{
    size_t i = 1;
    while (i * i <= (size_t)size)
    {
        if ((int)(i * i) == size)
            return (int)i;
        i++;
    }
    return 0;
}

// Rotation intelligente pour medium mode
void smart_rotate(t_ctrl *ctrl, int pos, int size)
{
    t_list *last;

    if (pos <= size / 2)
    {
        while (pos-- > 0)
            rotate_a(ctrl);
    }
    else
    {
        pos = size - pos;
        while (pos-- > 0)
        {
            last = ctrl->first;
            while (last->next)
                last = last->next;
            last->next = ctrl->first;
            ctrl->first = ctrl->first->next;
            last->next->next = NULL;
            ft_printf("rra\n");
        }
    }
}

// Normalise la liste pour medium_mode (chaque valeur devient son rang)
void normalize_list(t_ctrl *ctrl)
{
    int size = ft_lstsize(ctrl->first);
    int *arr = malloc(sizeof(int) * size);
    t_list *tmp = ctrl->first;
    int i;

    if (!arr)
        return;

    for (i = 0; i < size && tmp; i++)
    {
        arr[i] = tmp->data;
        tmp = tmp->next;
    }

    // Tri insertion
    for (i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    tmp = ctrl->first;
    while (tmp)
    {
        for (i = 0; i < size; i++)
            if (tmp->data == arr[i])
            {
                tmp->data = i;
                break;
            }
        tmp = tmp->next;
    }

    free(arr);
}

// medium_mode final
t_list *medium_mode(t_ctrl *ctrl)
{
    t_list *b = NULL;
    int size = ft_lstsize(ctrl->first);
    int chunk_size = ft_sqrt(size);
    int chunk_id = 0;
    int pushed = 0;

    if (!ctrl || !ctrl->first || is_sorted(ctrl))
        return ctrl->first;

    if (chunk_size < 2)
        chunk_size = 2;

    normalize_list(ctrl);

    while (ctrl->first)
    {
        if (ctrl->first->data >= chunk_id * chunk_size &&
            ctrl->first->data < (chunk_id + 1) * chunk_size)
        {
            push_a_to_b(&b, ctrl);
            pushed++;
            if (b && b->next && b->data < b->next->data)
                rotate_b(&b, ctrl);
        }
        else
        {
            smart_rotate(ctrl, 0, size);
        }

        if (pushed >= (chunk_id + 1) * chunk_size)
            chunk_id++;
    }

    while (b)
        push_b_to_a(&b, ctrl);

    return ctrl->first;
}
