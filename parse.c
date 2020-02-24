#include "ft_printf.h"

void    form_parser(const char *format, t_tab *tab, va_list arg)
{
    flag_pars(format, tab);
    width_prc_pars(format, tab, arg);
    size_pars(format, tab);
    tab->type = format[tab->i];
}

void    flag_pars(const char *format, t_tab *tab)
{
    size_t n;

    n = tab->i;
    while (format[n] == '-' || format[n] == '+' || format[n] == ' ' ||
            format[n] == '#' || format[n] == '0')
    {
        if (format[n] == '#')
            tab->hash = '#';
        else if ((format[n] == '-' || format[n] == '0')
                && tab->minus_zero != '-')
            tab->minus_zero = format[n];
        else if ((format[n] == '+' || format[n] == ' ') 
                && tab->plus_space == '+')
            tab->plus_space = format[n];
        n = ++param->n;
    }
    
}