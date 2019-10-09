/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <hharvey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:33:34 by hharvey           #+#    #+#             */
/*   Updated: 2019/04/30 20:17:19 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#define FLAG_LIST "lRart1UcuSfAp"
#define TIME_FLAG "Ucu"
#define PRINT_FLAG "1l"

void	usage(char c)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("usage: ls [-lRart1UcuSfA] [file ...]\n", 2);
	exit(1);
}

void	read_flags(int *fl, char *str)
{
	int	pos;

	while (*str)
	{
		if ((pos = ft_strchrpos(FLAG_LIST, *str)) > -1)
		{
			if (ft_strchr(PRINT_FLAG, *str))
				*fl = *fl & 0xfffffde;
			else if (ft_strchr(TIME_FLAG, *str))
				*fl = *fl & 0xffffe3f;
			*fl = *fl | ft_pow(2, pos);
		}
		else
			usage(*str);
		str++;
	}
}
