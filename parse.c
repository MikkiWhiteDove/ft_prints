#include "ft_printf.h"

void    flag_pars(const char *format, t_tab *tab)
{
    size_t i;

    i = tab->i;
    while (format[i] == '-' || format[i] == '+' || format[i] == ' ' ||
            format[i] == '#' || format[i] == '0')
    {
        if (format[i] == '#')
            tab->hash = '#';
        else if ((format[i] == '-' || format[i] == '0')
                && tab->minus_zero != '-')
            tab->minus_zero = format[i];
        else if ((format[i] == '+' || format[i] == ' ') 
                && tab->plus_space == '+')
            tab->plus_space = format[i];
        i = ++tab->i;
    }
    
}


void    form_parser(const char *format, t_tab *tab, va_list arg)
{
    flag_pars(format, tab);
    width_prc_pars(format, tab, arg);
    size_pars(format, tab);
    tab->type = format[tab->i];
}





int		check_precision(char *tmp, t_tab *tab)
{
	int		p;
	p = 0;
	p = check_width(tmp, tab);
	return (p);
}
int		check_width(char *tmp, t_tab *tab)
{
	char	*str;
	int		z;
	int		width;
	z = tab->i;
	width = 0;
	str = NULL;
	//str = (char*)malloc(sizeof(char) * ft_strlen(tmp));
	while (tmp[tab->i] >= '0' && tmp[tab->i] <= '9')
		tab->i++;
	str = ft_strsub(tmp, z, (tab->i) - z);
	width = atoi(str);
	free(str);
	return (width);
}

void	width_prc_pars(const char *tmp, t_tab *tab, va_list *arg)
{
	tab->p = 0;
	tab->width = 0;
	if ((tmp[tab->i] >= '0' && tmp[tab->i] <= '9') || tmp[tab->i] == '.') // чтобы узнать, указана ли ширина
	{
		if (tmp[tab->i] >= '0' && tmp[tab->i] <= '9')
			tab->width = check_width(tmp, tab);
		if (tmp[tab->i] == '.')
		{
			tab->i++;
			tab->p = check_precision(tmp, tab);
		}
	}
}

// int     ft_printf(const char *format, ...)
// {
//     va_list		arg;
// 	t_tab		*tab;
// 	int			n;
// 	char		*tmp;
// 	va_start(arg, format);
// 	n = 0;
// 	tab = NULL;
// 	if (!(tab = (t_tab*)malloc(sizeof(tab))))
// 		return (0);
// 	/*while (format[i] != '\0')
// 	{
// 		if (format[i] == '%')
// 			n++;
// 		i++;
// 	}*/
// 	tab->i = 0;
// 	tmp = NULL;
// 	tmp = (char*)malloc(sizeof(char) * ft_strlen(format));
// 	//while (format[i] != '\0')
// 	//{
// 		while (format[tab->i] != '%' && format[tab->i] != '\0')
// 		{
// 			tmp[tab->i] = format[tab->i];
// 			tab->i++;
// 		}
// 	//}
// 	tmp[tab->i] = '\0';
// 	tab->i++;
// 	parse(tmp, arg, tab);
// 	/*if (n == 0)
// 	{
// 		ft_putstr(format);
// 		tab->len = ft_strlen(format);
// 		return (tab->len);
// 	}
// 	else if (n == 2)
// 	{
// 		ft_putstr("%\n");
// 		return (1);
// 	}
// 	else
// 	{
// 		parse(format, arg);
// 	}*/
// 	//tab->len = func(smth, format, arg);
// 	va_end(arg);
// 	return (tab->len);
// }

