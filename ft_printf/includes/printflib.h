/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printflib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:11:09 by hharvey           #+#    #+#             */
/*   Updated: 2018/12/26 17:50:35 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTFLIB_H

# define PRINTFLIB_H

# include "libft.h"
# include <stdint.h>
# include <wchar.h>

typedef struct	s_params
{
	char		type[5];
	int			size;
	int			width;
	int			precision;
	int			plus;
	int			minus;
	int			space;
	int			zero;
	int			hash;
	int			res;
}				t_params;

int				ft_get_width(const char *str, int *p,
				va_list ap, t_params *param);
int				ft_get_precision(const char *str, int *p, va_list ap);
size_t			ft_strwlen_prec(const wchar_t *s, size_t prec);
long double		ft_pow(long double nb, int pow);
int				ft_count_float_digit(long double nb);
int				ft_wstrisprintable(wchar_t *str);
void			ft_printchar(t_params *param);
void			ft_printf_unsgn(long long int nb, int base,
				t_params *param, int isbig);
void			ft_printf_str(t_params *param, char *str);
void			ft_printf_wstr(t_params *param, wchar_t *str);
char			*ft_read_float(t_params *param, va_list ap);
char			*ft_add_end(char *str, int prec, int *len, char c);
char			*ft_add_start(char *str, int prec, int *len, char c);
void			ft_read_dec(t_params *param, va_list ap);
char			*ft_getprintnb(long long int nb, char c, int prsn);
void			ft_readstr(t_params *param, va_list ap);
char			*ft_width(t_params *param, char *str, int *p);
void			ft_readchar(t_params *param, va_list ap);
void			ft_readmem(t_params *param, void *in);
void			ft_read_unsgn(t_params *param, va_list ap);
void			ft_zs(int width, int len, int zero, int *res);
t_params		*ft_param_init(t_params *param);
int				end_type(char c);
void			ft_check_type(char *s);
int				ft_isdigit2(int c);
void			ft_check_old_types(char *s, char c);
char			*ft_get_output_str(t_params *param, va_list ap);
void			ft_read_size(t_params *param, char c);
int				ft_read_wp(t_params *param, const char *str,
				int *p, va_list ap);
void			ft_readparams(t_params *param, int *p,
				const char *str, va_list ap);
void			ft_sub_float(char *sgn, long double *eps, char c, int *i);

#endif
