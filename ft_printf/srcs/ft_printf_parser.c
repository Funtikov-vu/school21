/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 20:40:43 by hharvey           #+#    #+#             */
/*   Updated: 2018/12/26 17:05:05 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printflib.h"

void	ft_sub_read_size(t_params *param, char c)
{
	char *str;

	str = param->type;
	if (ft_strlen(str) == 1)
	{
		if (c == 'z' || c == 'j' || c == 'L')
			str[0] = c;
		if (c == 'l' && str[0] == 'h')
			str[0] = c;
	}
	else
	{
		if (str[0] == 'h')
		{
			param->type[0] = c;
			param->type[1] = 0;
			param->type[3] = 0;
		}
	}
}

void	ft_read_size(t_params *param, char c)
{
	char *str;

	str = param->type;
	if (ft_strlen(str) > 1)
	{
		if (param->type[0] == 'h')
		{
			param->type[1] = 0;
			param->type[2] = 0;
			param->type[0] = c;
		}
	}
	else if (!str[0])
		ft_strncat(param->type, &c, 1);
	else if (str[0] == c)
	{
		if (c == 'z' || c == 'j' || c == 'L')
			return ;
		ft_strncat(param->type, &c, 1);
	}
	else
		ft_sub_read_size(param, c);
}

int		ft_read_wp(t_params *param, const char *str, int *p, va_list ap)
{
	int i;

	ap = 0;
	i = *p;
	while (str[i] == 'l' || str[i] == 'L' || str[i] == 'h' ||
			str[i] == 'j' || str[i] == 'z')
	{
		ft_read_size(param, str[i]);
		i++;
	}
	*p = i - 1;
	return (1);
}

void	ft_sub_readparams(t_params *param, int *p, const char *str)
{
	int i;

	i = *p;
	if (!end_type(str[i]))
	{
		param->type[0] = str[i];
		param->type[1] = 0;
		if (!str[i])
			i--;
	}
	else
		ft_strncat(param->type, &str[i], 1);
	if ((param->precision != -1 || param->minus) && str[i] != 'C' &&
			str[i] != 'c' && str[i] != 'S' && str[i] != 's' && end_type(str[i]))
		param->zero = 0;
	ft_check_type(param->type);
	*p = i;
}

void	ft_readparams(t_params *param, int *p, const char *str, va_list ap)
{
	int i;

	i = *p;
	while (str[++i] && !end_type(str[i]))
		if (str[i] == '+')
			param->plus = 1;
		else if (str[i] == '-')
			param->minus = 1;
		else if (str[i] == ' ')
			param->space = 1;
		else if (str[i] == '0')
			param->zero = 1;
		else if (str[i] == '#')
			param->hash = 1;
		else if (ft_isdigit2(str[i]) || str[i] == '*')
			param->width = ft_get_width(str, &i, ap, param);
		else if (str[i] == '.')
			param->precision = ft_get_precision(str, &i, ap);
		else if (str[i] == 'l' || str[i] == 'L' || str[i] == 'h' ||
				str[i] == 'j' || str[i] == 'z')
			ft_read_wp(param, str, &i, ap);
		else
			break ;
	*p = i;
	ft_sub_readparams(param, p, str);
}
