#include "ft_printf.h"

void    flag_pars(const char *format, t_tab *tab)
{
    size_t i;

    i = tab->i;
    while (format[i] == '-' || format[i] == '+' || format[i] == ' ' ||
            format[i] == '#' || format[i] == '0' || format[i] == '*')
    {
        if (format[i] == '#')
            tab->hash = '#';
        else if ((format[i] == '-' || format[i] == '0')
                && tab->minus_zero != '-')
            tab->minus_zero = format[i];
        else if ((format[i] == '+' || format[i] == ' ') 
                && tab->plus_space == '+')
            tab->plus_space = format[i];
		// else if (format[i] == '*')
			// перескакивает через ширину и сразу проверяет точность
        i = ++tab->i;
    }
    
}

int		check_precision(const char *format, t_tab *tab)
{
	int		p;
	p = 0;
	p = check_width(format, tab);
	return (p);
}
int		check_width(const char *format, t_tab *tab)
{
	char	*str;
	int		z;
	int		width;
	z = tab->i;
	width = 0;
	str = NULL;
	//str = (char*)malloc(sizeof(char) * ft_strlen(tmp));
	while (format[tab->i] >= '0' && format[tab->i] <= '9')
		tab->i++;
	str = ft_strsub(format, z, (tab->i) - z);
	width = atoi(str);
	free(str);
	return (width);
}

void	width_prc_pars(const char *format, t_tab *tab, va_list *arg)
{
	tab->p = 0;
	tab->width = 0;
	if ((format[tab->i] >= '0' && format[tab->i] <= '9') || format[tab->i] == '.') // чтобы узнать, указана ли ширина
	{
		if (format[tab->i] >= '0' && format[tab->i] <= '9')
			tab->width = check_width(format, tab);
		if (format[tab->i] == '.')
		{
			tab->i++;
			tab->p = check_precision(format, tab);
		}
	}
}

void	size_pars(const char *format, t_tab *tab)
{
	while (format[tab->i] == 'l' )
	{
		tab->l_fl++;
		tab->i++;
		if (tab->l_fl >= 3)
			return (1);
	}
	while (format[tab->i] == 'h' && tab->l_fl == 0)
	{
		tab->h_fl++;
		tab->i++;
		if (tab->h_fl >= 3)
			return (1);
	}
	while (format[tab->i == 'L'] && tab->l_fl == 0 && tab->h_fl == 0)
	{
		tab->lb_fl++;
		tab->i++;
		if (tab->lb_fl >= 2)
			return (0);
	}
	return (0);
}

void    form_parser(const char *format, t_tab *tab, va_list arg)
{
    flag_pars(format, tab);
    width_prc_pars(format, tab, arg);
    size_pars(format, tab);
    tab->type = format[tab->i];
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

