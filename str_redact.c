#include "ft_printf.h"

char		*str_redactor(char *s, t_tab *tab)
{
	int		len;

	len = ft_strlen(s);
	if (len <= tab->width && tab->width != 0)
	{
		if (tab->precision > len || tab->precision == -1)
			s = str_redactor_one(s, tab, len);
		else if (tab->precision <= len || tab->precision == 0)
			s = str_redactor_two(s, tab);
	}
	else if (len > tab->width && tab->type != '%' && tab->type != 'N')
	{
		if (len > tab->precision && tab->precision >= tab->width)
			s = str_redactor_three(s, tab);
		else if (len >= tab->precision && tab->precision < tab->width \
				&& tab->precision != -1)
			s = str_redactor_four(s, tab);
	}
	else if (tab->width == 0)
		return (s);
	return (s);
}
