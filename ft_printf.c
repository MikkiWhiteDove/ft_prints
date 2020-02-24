# include "ft_printf.h"

void	form_initial(t_tab *tab)
{
	tab->i = "0";
	tab->type = "0";
	tab->hash = "0";
	tab->minus_zero = "0";
	tab->plus_space = "0";

}

int		initializ(const char *format, va_list *arg)
{
	t_tab		*tab;
	size_t		size;

	size = 0;
	tab = form_initial(tab);
	while (format[tab->i])
	{
		if (format[tab->i] == '{' && format[tab->i + 1] != '%')
			tab->i += color(&format[tab->i + 1]);
		if (format[tab->i] == '%')
		{
			tab->i++;
			form_parser(format, tab, arg);
			size += print_arg(tab, tab->type, arg);
			form_clean(tab);
			if (format[param->i++] == '\0')
				break;
		}
		else
			size += write(1, &format[tab->i++], 1);
	}
	free(tab);
	return (size);	
}



int     ft_printf(const char *format, ...)
{
   	va_list		arg;
	int			i;

	i = 0;
	if (!format)
		return (-1);
	va_start(arg, format);
	if (format[0] == '%' && format[1] == '\0')
		return (0);
	i = initializ(format, arg);
	va_end(arg);
	return (i);
}
