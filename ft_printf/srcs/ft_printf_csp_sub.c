/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_csp_sub.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 19:35:10 by hharvey           #+#    #+#             */
/*   Updated: 2018/12/26 16:46:29 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printflib.h"

void	ft_sub_float(char *sgn, long double *eps, char c, int *i)
{
	*i = 0;
	*sgn = 0;
	if (c == 'f')
		*eps = 0.999999999L;
	else
		*eps = 0.9999999999999999999999L;
}

size_t	ft_strwlen_prec(const wchar_t *s, size_t prec)
{
	size_t	i;
	wchar_t	c;

	i = 0;
	while (*s)
	{
		c = *s;
		if (c < 127 && i + 1 <= prec)
			i++;
		else if (c < 2048 && i + 2 <= prec)
			i += 2;
		else if (c < 65536 && i + 3 <= prec)
			i += 3;
		else if (i + 4 <= prec)
			i += 4;
		else
			break ;
		s++;
	}
	return (i);
}

void	ft_readstr(t_params *param, va_list ap)
{
	if (ft_strnchr(param->type, "Sl"))
		ft_printf_wstr(param, va_arg(ap, wchar_t*));
	else
		ft_printf_str(param, va_arg(ap, char*));
}
