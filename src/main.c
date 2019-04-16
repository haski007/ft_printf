#include "../includes/ft_printf.h"

void        exit_func()
{
    system("leaks ft_printf");
    exit(1);
}

// #define ARG "Result|||||||||%#50.22x*\n",  157

int         main(void)
{
    int     my_result;
    int     org_result;
    // int     a = 0;
    // int     *b = &a;
    // long long double  chlen = -0;
    
    my_result = ft_printf("%f---------%t%d%t------%#x\n", 0.0, RED, 23, WHITE, 4432);
    org_result = printf("%f---------%d------%#x\n", 0.0, 23, 4432);
    printf("\n\nMy result - %d\n", my_result);
    printf("Original result - %d\n", org_result);
    //   system("leaks ft_printf"); 
    return (0);
}