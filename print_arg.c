# include "ft_printf.h"

size_t      *print_arg(t_tab *tab, char type, va_list *arg)
{
    char *s;

	s = NULL;
    if (type == 's' || type == 'c' || type == 'S')
		s = print_str(tab, arg);
	else if (type == 'd' || type == 'i')
		s = print_int(tab, arg);
	else if (type == 'u')
		s = digit_uint_processing(tab, arg);
	else if (type == 'o' || type == 'b'\
			|| type == 'x' || type == 'X')
		s = print_oct(tab, arg);
	// else if (type == 'f')
	// 	s = digit_double_processing(tab, arg);
	// else if (type == '%')
	// 	s = str_redactor(ft_strdup("%"), tab);
	// else if (type == 'p')
	// 	s = redactor(ft_itoa_base_unsigned(va_arg(*arg, size_t), 16), tab);
	// else if (type == 'k')
	// 	s = data_iso(arg);
	else
		return (NULL);
    return (s);
    // if (type == 'd' || type == 'i' || type == 'u')
    //     return (print_int(tab, arg));
    // else if (type == 's' || type == 'c')
    //     return (print_str(tab, arg));
    // else if (type == 'o')
    //     return (print_oct(tab, arg));
    // // else if ()
    // //     return (print_unsig(tab, arg));
    // else if (type == 'p')
    //     return (print_point(tab, arg));
    // else if (type == 'X' || type == 'x')
    //     return (print_hex(tab, arg));
    // else
    //     return (print_chr(tab, arg));
    // return (0);

}