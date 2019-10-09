/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_arrstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <hharvey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 18:34:39 by hharvey           #+#    #+#             */
/*   Updated: 2019/04/30 19:37:12 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_fl	*fl_str_gen(char *str, int flg)
{
	t_fl	*fl;

	fl = (t_fl*)malloc(sizeof(t_fl));
	if (lstat(str, &fl->sbuff) == -1)
	{
		free(fl);
		print_error(str);
		return (0);
	}
	if (((fl->sbuff.st_mode & S_IFMT) == S_IFLNK) && !(flg & 1))
		stat(str, &fl->sbuff);
	fl->name = str;
	fl->pname = str;
	file_set_time(fl, flg);
	return (fl);
}

t_list	*lst_arrstr_get(int n, char **arr, int flg, t_list **lst_dir)
{
	t_list	*lst;
	t_fl	*fl;
	int		i;

	i = -1;
	lst = 0;
	while (++i < n)
	{
		if ((fl = fl_str_gen(arr[i], flg)) == 0)
			continue ;
		if ((fl->sbuff.st_mode & S_IFMT) != S_IFDIR)
			lst = lst_sort_add(lst, ft_lstput(fl, sizeof(*fl)), flg, flg & 8);
		else
			*lst_dir = lst_sort_add(*lst_dir,
					ft_lstput(fl, sizeof(*fl)), flg, flg & 8);
	}
	return (lst);
}

void	sub_dir(t_list *lst_dir, int flg, int n)
{
	t_fl	*fl;
	t_list	*temp;

	while (lst_dir)
	{
		fl = lst_dir->content;
		if (n > 1)
		{
			ft_putstr(fl->name);
			ft_putstr(":\n");
		}
		ls_dir(fl->name, flg);
		if (lst_dir->next)
			ft_putchar('\n');
		free(lst_dir->content);
		temp = lst_dir->next;
		free(lst_dir);
		lst_dir = temp;
	}
}

void	ls_arrstr(int n, char **arr, int flg)
{
	t_list	*lst_fl;
	t_list	*lst_dir;
	t_list	*temp;

	lst_dir = 0;
	ft_arrstr_bblsrt(arr, n);
	lst_fl = lst_arrstr_get(n, arr, flg, &lst_dir);
	lst_print(lst_fl, flg, 0);
	if (lst_fl && lst_dir)
		ft_putchar('\n');
	sub_dir(lst_dir, flg, n);
	while (lst_fl)
	{
		free(lst_fl->content);
		free(lst_fl);
		temp = lst_fl->next;
		lst_fl = temp;
	}
}
