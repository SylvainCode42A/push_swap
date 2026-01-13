#include "ft_push_swap.h"

void init_ctrl(t_ctrl **ctrl)
{
    *ctrl = malloc(sizeof(t_ctrl));
    if (!*ctrl)
        return ;
    (*ctrl)->strat = NULL;
    (*ctrl)->bench = 0;
    (*ctrl)->count_ra = 0;
    (*ctrl)->count_rb = 0;
    (*ctrl)->count_rr = 0;
    (*ctrl)->count_pb = 0;
    (*ctrl)->count_pa = 0;
    (*ctrl)->count_sa = 0;
    (*ctrl)->count_sb = 0;
    (*ctrl)->count_ss = 0;
    (*ctrl)->count_rra = 0;
    (*ctrl)->count_rrb = 0;
    (*ctrl)->count_rrr = 0;
    (*ctrl)->count_disorder = 0.0f;
    (*ctrl)->first = NULL;
    (*ctrl)->last = NULL;
}

int take_strat(char *arg, t_ctrl *ctrl)
{
    if (!arg)
    {
        ctrl->strat = "adaptive";
        return 0;
    }
    if (ft_strcmp(arg, "--simple") == 0)
        ctrl->strat = "simple";
    else if (ft_strcmp(arg, "--medium") == 0)
        ctrl->strat = "medium";
    else if (ft_strcmp(arg, "--complex") == 0)
        ctrl->strat = "complex";
    else
        ctrl->strat = "adaptive";
    return 1;
}

int parse_bench(int argc, char **argv, t_ctrl *ctrl)
{
    if (argc > 1 && ft_strcmp(argv[argc - 1], "--bench") == 0)
    {
        ctrl->bench = 1;
        return (argc - 1);
    }
    ctrl->bench = 0;
    return (argc);
}

int parsing_ext(int argc, char **argv, char **tempnormalized, size_t i)
{
    char *tmp;
    int space;

    space = 0;
    if (i < (size_t)(argc - 1))
        space = 1;
    tmp = strjoin_space(*tempnormalized, argv[i], space);
    free(*tempnormalized);
    if (!tmp)
        return (0);
    *tempnormalized = tmp;
    return (1);
}

char **parsing(int argc, char **argv, int i, size_t max)
{
    char **normalized;
    char *tempnormalized;

    tempnormalized = ft_strdup("");
    if (!tempnormalized)
        return NULL;
    while (i < (int)max)
        i += parsing_ext(argc, argv, &tempnormalized, i);
    normalized = ft_split(tempnormalized, ' ');
    free(tempnormalized);
    return normalized;
}

int verify_sign(char *s)
{
    size_t i = 0;
    if (!s || s[0] == '\0')
        return 0;
    if (s[i] == '+' || s[i] == '-')
        i++;
    if (s[i] == '\0')
        return 0;
    while (s[i])
    {
        if (s[i] < '0' || s[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

int verify_double(char **stack_a, size_t size)
{
    size_t i, j;
    i = 0;
    while (i < size - 1)
    {
        j = i + 1;
        while (j < size)
        {
            if (ft_strcmp(stack_a[i], stack_a[j]) == 0)
                return 0;
            j++;
        }
        i++;
    }
    return 1;
}

int parse_int_strict(char *s, int *out)
{
    long value;

    if (!verify_sign(s))
        return 0;
    value = ft_atol(s);
    if (value < INT_MIN || value > INT_MAX)
        return 0;
    *out = (int)value;
    return 1;
}

int verify_arg(char **stack_a, size_t size)
{
    size_t i;

    for (i = 0; i < size; i++)
        if (!verify_sign(stack_a[i]))
            return 0;
    if (size < 2)
        return 0;
    if (!verify_double(stack_a, size))
        return 0;
    return 1;
}

t_list *ft_create_elem(int data)
{
    t_list *node;
    node = malloc(sizeof(t_list));
    if (!node)
        return NULL;
    node->data = data;
    node->next = NULL;
    return node;
}

t_list *tab_in_list(char **stack_a, t_ctrl *ctrl)
{
    t_list *node;
    size_t i;
    int value;

    i = 0;
    ctrl->first = NULL;
    ctrl->last = NULL;
    while (stack_a[i])
    {
        if (!parse_int_strict(stack_a[i], &value))
            return NULL;
        node = ft_create_elem(value);
        if (!node)
            return NULL;
        if (!ctrl->first)
        {
            ctrl->first = node;
            ctrl->last = node;
        }
        else
        {
            ctrl->last->next = node;
            ctrl->last = node;
        }
        i++;
    }
    free_tab(stack_a);
    return ctrl->first;
}

int print_bench(t_ctrl *ctrl)
{
    size_t total;
    total = ctrl->count_ra + ctrl->count_rb + ctrl->count_rr + ctrl->count_pa + ctrl->count_pb;
    write(2, "[bench] Disorder : ", 19);
    ft_putfloat(ctrl->count_disorder);
    write(2, "[bench] Strategy : ", 19);
    ft_putstr(ctrl->strat);
    write(2, "[bench] Total operations : ", 27);
    ft_putnbr(total);
    write(2, "[bench] ra : ", 13);
    ft_putnbr(ctrl->count_ra);
    write(2, "[bench] rb : ", 13);
    ft_putnbr(ctrl->count_rb);
    write(2, "[bench] rr : ", 13);
    ft_putnbr(ctrl->count_rr);
    write(2, "[bench] pa : ", 13);
    ft_putnbr(ctrl->count_pa);
    write(2, "[bench] pb : ", 13);
    ft_putnbr(ctrl->count_pb);
    return 0;
}

void adaptive_mode(t_ctrl *ctrl, t_list **b)
{
    t_list *current;
    size_t comparisons = 0;
    float disorder = 0.0f;

    if (!ctrl || !ctrl->first || !ctrl->first->next)
    {
        simple_mode(ctrl);
        return ;
    }
    current = ctrl->first;
    while (current->next)
    {
        if (current->data > current->next->data)
            disorder += 1.0f;
        current = current->next;
        comparisons++;
    }
    ctrl->count_disorder = disorder / (float)comparisons;
    if (ctrl->count_disorder < 0.2f)
        simple_mode(ctrl);
    else if (ctrl->count_disorder <= 0.5f)
        medium_mode(ctrl);
    else
        complex_mode(ctrl, b);
}

void get_strategie(t_ctrl *ctrl, t_list **b)
{
    if (is_sorted(ctrl))
        return;
    if (size_list_a(ctrl) <= 3)
    {
        simple_mode(ctrl);
        return;
    }
    if (ft_strcmp("adaptive", ctrl->strat) == 0)
        adaptive_mode(ctrl, b);
    else if (ft_strcmp("simple", ctrl->strat) == 0)
        simple_mode(ctrl);
    else if (ft_strcmp("medium", ctrl->strat) == 0)
        medium_mode(ctrl);
    else if (ft_strcmp("complex", ctrl->strat) == 0)
        complex_mode(ctrl, b);
}

t_list *ft_push_swap(int argc, char **argv)
{
    t_list *a;
    t_ctrl *ctrl;
    char **stack_a;
    int i = 0;
    size_t max;
    t_list *b;

    b = NULL;
    a = NULL;
    init_ctrl(&ctrl);
    if (!ctrl)
        return NULL;

    if (argc > 1)
        i = take_strat(argv[1], ctrl);

    max = parse_bench(argc, argv, ctrl);
    stack_a = parsing(argc, argv, i, max);

    if (max < (size_t)i || !verify_arg(stack_a, max - i))
    {
        write(2, "Error\n", 6);
        free_tab(stack_a);
        free_list(&ctrl->first, NULL);
        return NULL;
    }

    a = tab_in_list(stack_a, ctrl);
    if (!a)
    {
        write(2, "Error\n", 6);
        free_tab(stack_a);
        free_list(&ctrl->first, NULL);
        return NULL;
    }
    get_strategie(ctrl, &b);
    print_list(ctrl->first);
    if (ctrl->bench)
        print_bench(ctrl);
    free(ctrl);
    return (a);
}
