#include "ft_printf.h"

if (tab->i == 'd' || tab->i == 'i' || tab->i == 'u')
	{
		if (tab->type == 'd' || tab->type == 'i')
			ap = va_arg(arg, signed int);
		else
			ap = va_arg(arg, unsigned int);
		ap2 = (char*)malloc(sizeof(char) * tab->tmp_len + 1);
		ap2 = ft_itoa(ap);
		tab->tmp = ft_strjoin(tab->tmp, ap2);
		//printf("arg: %d\n", ap);
		printf("arg: %s\n", tab->tmp);
	}







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