#include "ft_printf.h"

int			putstr_for_null_char(char *s)
{
	size_t i;

	i = 0;
	if (s != NULL)
		while (s[i] != '\0')
		{
			if (s[i] == '@')
			{
				s[i] = (0000);
			}
			ft_putchar(s[i]);
			i++;
		}
	return (i);
}

static char	*type_s(t_tab *tab, va_list *arg)
{
	char	*str;
	int		i;

	if (tab->l_fl != 1)
		str = (char *)va_arg(*arg, char *);
	else
		str = (char *)va_arg(*arg, wchar_t *);
	if (!str)
		str = "(null)";
	str = str_redactor(ft_strdup(str), tab);
	// if (tab->type == 'S')
	// {
	// 	i = 0;
	// 	while (str[i])
	// 	{
	// 		str[i] = ft_toupper(str[i]);
	// 		i++;
	// 	}
	// }
	return (str);
}

static char     *ft_stradd(char *str, char c)
{
    int     len;
    char    *new;

    len = 0;
    if (str)
    {
        len = ft_strlen(str);
        if (!(new = (char *)ft_strnew(len + 1)))
            return (NULL);
        ft_strcat(new, str);
        ft_strdel(&str);
    }
    else
        new = ft_strnew(1);
    new[len] = c;
    new[len + 1] = '\0';
    return (new);    
}

static char	*type_c(t_tab *tab, va_list *ap)
{
	char	v_ar;
	char	*str;

	v_ar = (char)va_arg(*ap, int);
	if (v_ar)
	{
		str = str_redactor(ft_stradd(NULL, v_ar), tab);
	}
	else
	{
		fl->type = 'N';
		str = str_redactor(ft_strdup("@"), tab);
	}
	return (str);
}

char		*type_s_c(t_tab *tab, va_list *arg)
{
	char	*str;

	str = NULL;
	if (tab->l_fl == 0 || tab->l_fl == 1)
	{
		if (tab->type == 's' || tab->type == 'S')
			str = type_s(tab, arg);
		if (tab->type == 'c')
			str = type_c(tab, arg);
	}
	else
		str = ft_strdup("(null)");
	return (str);
}




// static char     *type_c(t_tab *tab, va_list *arg)
// {
//     char    *str;
//     char    l_arg;

//     l_arg = (char)va_arg(*arg, int);
//     if (l_arg)
//         str = str_red(ft_stradd(NULL, l_arg), tab);
//     else
//     {
//         tab->type = 'N';
//         str = str_red(ft_strdup("@"), tab);
//     }
    
// }

// char    print_str(t_tab *tab, va_list *arg)
// {
//     char    *s;

//     s = NULL;
//     if (tab->l_fl == 0 || tab->l_fl == 1)
//     {
//         if (tab->type == 's')
//             s = type_s(tab, arg);
//         // if (tab->type == 'c')
//         //     s = type_c(tab, arg);
//     }
//     else
//         s = ft_strdup("(null)");
//     return (s);
// }