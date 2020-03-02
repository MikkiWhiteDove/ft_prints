
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/inc/libft.h"
# include <stdarg.h>
# include <ctype.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>

typedef struct      s_tab
{
    //char        *format;
	//int         len;
    va_list         arg;
    unsigned char   hash;
    unsigned char   minus_zero;
    unsigned char   plus_space;
    unsigned char   type;
    long int        p;
    int             i;
    unsigned char   l_fl;
    unsigned char   h_fl;
    unsigned char   lb_fl;
    long int        width;
}                   t_tab;


int             ft_printf(const char *format, ...);
void            form_parser(const char *format, t_tab *tab,\
va_list arg);
size_t          print_arg(t_tab tab, char type, va_list arg);
#endif