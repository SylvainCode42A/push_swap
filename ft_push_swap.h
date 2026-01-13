#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

#include <stddef.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "ft_printf/ft_printf.h"

typedef struct s_list {
    int             data;
    struct s_list   *next;
} t_list;

typedef struct s_ctrl {
    char    *strat;
    int     bench;
    size_t  count_ra;
    size_t  count_rb;
    size_t  count_rr;
    size_t  count_pb;
    size_t  count_pa;
    size_t  count_sa;
    size_t  count_sb;
    size_t  count_ss;
    size_t  count_rra;
    size_t  count_rrb;
    size_t  count_rrr;
    float   count_disorder;
    t_list  *first;
    t_list  *last;
} t_ctrl;

void        radix_sort(t_ctrl *ctrl, t_list **b, int i);
void        complex_mode(t_ctrl *ctrl, t_list **b);
void        simple_mode(t_ctrl *ctrl);
t_list	    *medium_mode(t_ctrl *ctrl);
void        adaptive_mode(t_ctrl *ctrl, t_list **b);
void        get_strategie(t_ctrl *ctrl, t_list **b);
t_list      *ft_create_elem(int data);
t_list      *tab_in_list(char **stack_a, t_ctrl *ctrl);
void        push_a_to_b(t_list **b, t_ctrl *ctrl);
void        push_b_to_a(t_list **b, t_ctrl *ctrl);
void        reverse_rotate_a(t_ctrl *ctrl);
void        reverse_rotate_b(t_list **b, t_ctrl *ctrl);
void        reverse_rotate_a_b(t_list **b, t_ctrl *ctrl);
void        rotate_a(t_ctrl *ctrl);
void        rotate_b(t_list **b, t_ctrl *ctrl);
void        rotate_a_b(t_list **b, t_ctrl *ctrl);
void        swap_a(t_ctrl *ctrl);
void        swap_b(t_list **b, t_ctrl *ctrl);
void        swap_a_b(t_list **b, t_ctrl *ctrl);
int         is_sorted(t_ctrl *ctrl);
int         size_list_a(t_ctrl *ctrl);
int         size_list_b(t_list *b);
int         size_max_bit(int max);
int         search_max(t_ctrl *ctrl);
int         ft_sqrt(int size);
void        normalize_list(t_ctrl *ctrl);
static int  find_chunk_pos(t_list *lst, int min, int max);
void	    smart_rotate(t_ctrl *ctrl, int pos, int size);
int         take_strat(char *arg, t_ctrl *ctrl);
int         parse_bench(int argc, char **argv, t_ctrl *ctrl);
int         parsing_ext(int argc, char **argv, char **tempnormalized, size_t i);
char        **parsing(int argc, char **argv, int i, size_t max);
int         verify_sign(char *s);
int         verify_double(char **stack_a, size_t size);
int         parse_int_strict(char *s, int *out);
int         verify_arg(char **stack_a, size_t size);
int         print_bench(t_ctrl *ctrl);
t_list      *ft_push_swap(int argc, char **argv);
size_t	    ft_strlen(const char *s);
int	        ft_strcmp(const char *s1, const char *s2);
char	    *ft_strdup(const char *str);
char	    *ft_substr(char const *s, unsigned int start, size_t len);
char	    **ft_split(char const *s, char c);
int	        ft_atoi(const char *str);
long	    ft_atol(const char *str);
char        *strjoin_space(char const *s1, char const *s2, int space);
void	    ft_putfloat(float nb);
void        free_tab(char **a);
void        free_list(t_list **a, t_list **b);
void        print_list(t_list *a);
int         ft_lstsize(t_list *lst);

#endif