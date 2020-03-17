#include "ft_printf.h"

char		*redactor(char *s, t_tab *tab)
{
    char	*minus;

	minus = ft_strchr(s, '-');
	s = precision_redactor(s, minus, tab);
	if (tab->hash || tab->type == 'p')
		s = hashtag_redactor(tab->type, s, tab->precision);
	if (!tab->precision && !ft_strcmp(s, "0") && \
	(tab->type == 'x' || tab->type == 'o' || tab->type == 'd' || tab->type == 'u') \ 
		s[0] = '\0';
	if (!minus && tab->plus_space == '+' && (tab->type == 'd' || tab->type == 'f'))
		s = ft_strjoin_free("+", s, 2);
	tab->filler = (tab->precision != -1 && tab->type != 'f') ? ' ' : tab->filler;
	s = width_redactor(s, tab, ft_strlen(s));
	return (s);
}

