#include "ft_printf.h"

int		main(void)
{
	ft_printf("%%\n");
	ft_printf("%-6d\n",5);
	ft_printf("%-6d\n",15);
	ft_printf("%-6d\n",125);
	ft_printf("%s\n","sva[rujrjvkla");
	ft_printf("%c\n",'c');
	return (0);
}