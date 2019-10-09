/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <hharvey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 14:08:37 by hharvey           #+#    #+#             */
/*   Updated: 2019/04/30 20:35:37 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_mnr_mjr(int nb, int f1, int f2)
{
	print_nb((int)(((unsigned int)(nb) >> 24) & 0xff), f1);
	ft_putchar(',');
	print_nb((int)((nb) & 0xffffff), f2);
}

void	print_l(t_list *lst, int is_dir, int flg)
{
	t_fl	*fl;
	int		format[6];

	print_total(format, is_dir, lst);
	while (lst)
	{
		fl = lst->content;
		print_type(fl);
		print_perms(fl, fl->pname);
		print_nb(fl->sbuff.st_nlink, format[0] + 1);
		ft_putchar(' ');
		print_str(getpwuid(fl->sbuff.st_uid)->pw_name, format[1] + 1);
		ft_putchar(' ');
		print_str(getgrgid(fl->sbuff.st_gid)->gr_name, format[2] + 1);
		ft_putchar(' ');
		if ((fl->sbuff.st_mode & S_IFMT) != S_IFCHR &&
			(fl->sbuff.st_mode & S_IFMT) != S_IFBLK)
			print_nb(fl->sbuff.st_size, format[3]);
		else
			print_mnr_mjr(fl->sbuff.st_rdev, format[4], format[5]);
		print_time(fl);
		print_name(fl, flg);
		ft_putchar('\n');
		lst = lst->next;
	}
}

void	lst_print(t_list *lst, int flg, int is_dir)
{
	t_fl	*fl;

	if (flg & 1)
	{
		print_l(lst, is_dir, flg);
	}
	else
		while (lst)
		{
			fl = lst->content;
			ft_putstr(fl->name);
			if ((flg & 4096) && (fl->sbuff.st_mode & S_IFMT) == S_IFDIR)
				ft_putchar('/');
			ft_putchar('\n');
			lst = lst->next;
		}
}
