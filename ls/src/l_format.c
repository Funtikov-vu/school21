/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_format.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <hharvey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 17:39:25 by hharvey           #+#    #+#             */
/*   Updated: 2019/04/30 17:43:29 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sub_frmt(int nb, int *frmt)
{
	if (nb > *frmt)
		*frmt = nb;
}

int		sub_minor(int nb)
{
	return ((int)((nb) & 0xffffff));
}

int		sub_major(int nb)
{
	return ((int)(((unsigned int)(nb) >> 24) & 0xff));
}

int		get_format_n_ttl(t_list *lst, int format[6])
{
	t_fl		*fl;
	int			res;
	struct stat	buff;

	res = 0;
	while (lst)
	{
		fl = lst->content;
		buff = ((t_fl*)lst->content)->sbuff;
		res += fl->sbuff.st_blocks;
		sub_frmt(ft_numlen(buff.st_nlink), format);
		sub_frmt(ft_strlen(getpwuid(buff.st_uid)->pw_name), format + 1);
		sub_frmt(ft_strlen(getgrgid(buff.st_gid)->gr_name), format + 2);
		sub_frmt(ft_numlen(buff.st_size), format + 3);
		if ((buff.st_mode & S_IFMT) == S_IFCHR ||
			(buff.st_mode & S_IFMT) == S_IFBLK)
		{
			sub_frmt(ft_numlen(sub_major(buff.st_rdev)) + 1, format + 4);
			sub_frmt(ft_numlen(sub_minor(buff.st_rdev)) + 1, format + 5);
		}
		lst = lst->next;
	}
	if (format[3] < format[4] + format[5] + 1)
		format[3] = format[4] + format[5] + 1;
	return (res);
}
