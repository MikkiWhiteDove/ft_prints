#include "ft_printf.h"

static char     *type_s(t_tab *tab, va_list *arg)
{
    char    *str;
    int     i;

    if (tab->l_fl != 1)
        str = (char *)va_arg(*arg, char *);
    else 
        str = (char *)va_arg(*arg, wchar_t *);
    if (!str)
        str = "(null)";
    str = str_red(tab, ft_strdup(str));
    return (str);
}

static char     *stradd(char *str, char c)
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

char    print_str(t_tab *tab, va_list *arg)
{
    char    *s;

    s = NULL;
    if (tab->l_fl == 0 || tab->l_fl == 1)
    {
        if (tab->type == 's')
            s = type_s(tab, arg);
        // if (tab->type == 'c')
        //     s = type_c(tab, arg);
    }
    else
        s = ft_strdup("(null)");
    return (s);
}