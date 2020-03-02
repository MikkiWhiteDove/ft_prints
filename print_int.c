#include "ft_printf.h"

char    *print_int(t_tab *tab, va_list *arg)
{
    char str;

    str = NULL;
    if (tab->l_fl == 1)
        str = ft_itoa_l(va_arg(*arg, long));
    else if (tab->l_fl == 2)
        str = ft_itoa_ll(va_arg(*arg, long long));
    else if (tab->h_fl == 1)
        str = ft_itoa((short)va_arg(*arg, int));
    else if (tab->h_fl == 2)
        str = ft_itoa((signed char)va_arg(*arg, int));
    else
        str = ft_itoa(va_arg(*arg, int));
    str = redactor(str, tab);
    return (str);    
}