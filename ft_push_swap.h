#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

//--------Headers---------
#include <unistd.h>
#include <stdlib.h>
#include "../ft_printf.h"
#include "../ft_libft.h"

//--------Fonctions---------
char    **ft_push_swap(int argc, char **argv);
int     verify_args(char *s);
char    **parsing(int argc, char **argv);
char	*strjoin_space(char const *s1, char const *s2, int space);
int     verify_double(char **a, int size);

//----------Utils-----------
void    push_a_to_b(char **a, char **b);
void    push_b_to_a(char **a, char **b);
void    reverse_rotate_a(char **temp_stack_a);
void    reverse_rotate_b(char **temp_stack_b);
void    reverse_rotate_a_b(char **temp_stack_a, char **temp_stack_b);
void    rotate_a(char **temp_stack_a);
void    rotate_b(char **temp_stack_b);
void    rotate_a_b(char **temp_stack_a, char **temp_stack_b);
char    **swap_a(char **temp_stack_a);
char    **swap_b(char **temp_stack_b);
void    swap_a_b(char **temp_stack_a, char **temp_stack_b);

#endif