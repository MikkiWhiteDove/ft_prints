
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/inc/libft.h"
# include <stdarg.h>
# include <ctype.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>

typedef struct  s_tab
{
    char        *format;
	int         len;
    va_list     arg;
}               t_tab;


int                 ft_printf(const char *format, ...);

#endif