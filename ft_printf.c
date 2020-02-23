# include "ft_printf.h"

int  initializ(const char *format, va_list *arg, t_tab *tab, int i, int n)
{
    int     j;

    j = 0;
	while (format[j] != '\0')
	{
		if (format[j] == '%')
			n++;
		j++;
	}
	if (n == 0)
	{
		ft_putstr(format);
		tab->len = ft_strlen(format);
		return (tab->len);
	}
	else if (n == 2)
	{
		ft_putstr("%\n");
		return (1);
	}
	// else
	// {
	// 	parse(format, arg);
	// }
}

int     ft_printf(const char *format, ...)
{
   	va_list		arg;
	t_tab		*tab;
	int			n;
	int			i;

	n = 0;
	i = 0;
	if (!(tab = (t_tab*)malloc(sizeof(tab))))
		return (n);
	va_start(arg, format);
	n = initializ(format, &arg, tab, i, n);
	va_end(arg);
	free(tab);
	return (n);
}
