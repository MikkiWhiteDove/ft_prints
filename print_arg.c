# include "ft_printf.h"

size_t          print_arg(t_tab tab, char type, va_list arg)
{
    if (type == 'd' || type == 'i')
        return (print_int(tab, arg));
    else if (type == 's')
        return (print_str(tab, arg));
    else if (type == 'o')
        return (print_oct(tab, arg));
    else if (type == 'u')
        return (print_unsig(tab, arg));
    else if (type == 'p')
        return (print_point(tab, arg));
    else if (type == 'X' || type == 'x')
        return (print_hex(tab, arg));
    else
        return (print_chr(tab, arg));
    return (0);
}