#include "ft_printf.h"

int main(void)
{
    int a = 42;
    unsigned int b = 3000;
    char c = 'Z';
    char *str = "Hello, 42!";
    void *ptr = &a;

    ft_printf("=== Test de ft_printf ===\n");

    ft_printf("Char: %c\n", c);
    ft_printf("String: %s\n", str);
    ft_printf("Int: %d\n", a);
    ft_printf("Int (i): %i\n", a);
    ft_printf("Unsigned: %u\n", b);
    ft_printf("Hex lowercase: %x\n", b);
    ft_printf("Hex uppercase: %X\n", b);
    ft_printf("Pointer: %p\n", ptr);
    ft_printf("Pourcentage: %%\n");

    ft_printf("=========================\n");

    return 0;
}
