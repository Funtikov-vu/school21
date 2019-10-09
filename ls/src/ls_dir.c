/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <hharvey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 18:45:25 by hharvey           #+#    #+#             */
/*   Updated: 2019/04/30 20:35:44 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list	*lst_sort_add(t_list *lst, t_list *new, int flg, int is_r)
{
	int		(*comp)();
	t_list	*start;
	t_list	*prev;

	start = lst;
	prev = 0;
	comp = get_comp(flg);
	while (lst && comp(new, lst, is_r))
	{
		prev = lst;
		lst = lst->next;
	}
	if (!prev)
	{
		new->next = lst;
		return (new);
	}
	prev->next = new;
	new->next = lst;
	return (start);
	return (0);
}

int		check_name(int flg, char *str)
{
	if (str[0] != '.')
		return (1);
	if ((flg & 2052) == 0)
		return (0);
	if (flg & 4)
		return (1);
	if (ft_strequ(str, ".") || ft_strequ(str, ".."))
		return (0);
	return (1);
}

t_list	*lst_get(char *str, int flg)
{
	DIR				*dirp;
	t_list			*lst;
	struct dirent	*dp;
	t_fl			*fl;

	dirp = opendir(str);
	if (!dirp)
	{
		str[ft_strlen(str) - 1] = 0;
		if (ft_strrchr(str, '/'))
			str = ft_strrchr(str, '/') + 1;
		print_error(str);
		return (0);
	}
	lst = 0;
	while ((dp = readdir(dirp)))
	{
		if (!check_name(flg, dp->d_name))
			continue ;
		fl = file_gen(str, dp, flg);
		lst = lst_sort_add(lst, ft_lstput(fl, sizeof(t_fl)), flg, flg & 8);
	}
	closedir(dirp);
	return (lst);
}

void	sub_rec(char *str, char *fname, int flg)
{
	char *temp;

	temp = ft_strjoin(str, fname);
	ft_putchar('\n');
	ft_putstr(temp);
	ft_putstr(":\n");
	ls_dir(temp, flg);
	free(temp);
}

t_list	*ls_dir(char *str, int flg)
{
	t_list	*lst;
	t_fl	*fl;
	t_list	*swap;

	str = ft_strjoin(str, "/");
	lst = lst_get(str, flg);
	lst_print(lst, flg, 1);
	while (lst)
	{
		fl = lst->content;
		if (flg & 2 && S_ISDIR(fl->sbuff.st_mode) &&
				!ft_strequ(fl->name, ".") && !ft_strequ(fl->name, ".."))
			sub_rec(str, fl->name, flg);
		del_file_lst(fl, 42);
		swap = lst->next;
		free(lst);
		lst = swap;
	}
	free(str);
	return (lst);
}
