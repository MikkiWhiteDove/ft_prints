// # include "ft_printf.h"

// char	*output_parameter(t_flags *fl, va_list *ap)
// {
// 	char *s;

// 	s = NULL;
// 	if (fl->type == 's' || fl->type == 'c' || fl->type == 'S')
// 		s = type_s_c(fl, ap);
// 	else if (fl->type == 'd' || fl->type == 'i')
// 		s = digit_int_processing(fl, ap);
// 	else
// 		return (NULL);
// 	return (s);
// }