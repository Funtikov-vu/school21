/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:13:02 by hharvey           #+#    #+#             */
/*   Updated: 2018/12/24 16:53:54 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"
#include "libft.h"

char	*ft_add_start(char *str, int prec, int *p, char c)
{
	int dif;
	int len;

	len = *p;
	if ((dif = prec - len) > 0)
	{
		*p = len + dif;
		return (ft_strfreejoin(ft_strnewchr(dif, c), str));
	}
	else
		return (str);
}

char	*ft_add_end(char *str, int prec, int *p, char c)
{
	int dif;
	int len;

	len = *p;
	if ((dif = prec - len) > 0)
	{
		*p = len + dif;
		return (ft_strfreejoin(str, ft_strnewchr(dif, c)));
	}
	else
		return (str);
}

char	*ft_width(t_params *param, char *str, int *p)
{
	int		len;
	int		dif;

	len = *p;
	if ((dif = param->width - len) > 0)
	{
		if (param->minus)
			str = ft_strfreejoin(str, ft_strnewchr(dif, ' '));
		else
		{
			if (param->zero)
				str = ft_strfreejoin(ft_strnewchr(dif, '0'), str);
			else
				str = ft_strfreejoin(ft_strnewchr(dif, ' '), str);
		}
	}
	*p = len;
	return (str);
}

void	ft_zs(int width, int len, int zero, int *res)
{
	int dif;
	int chr;

	if (zero)
		chr = '0';
	else
		chr = ' ';
	dif = width - len;
	if (dif > 0)
		*res += dif;
	while (dif > 0)
	{
		ft_putchar_fd(chr, 1);
		dif--;
	}
}
