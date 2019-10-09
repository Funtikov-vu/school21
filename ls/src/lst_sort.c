/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <hharvey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 13:27:23 by hharvey           #+#    #+#             */
/*   Updated: 2019/04/29 18:47:52 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	comp_ascii(t_list *lst, t_list *lst2, int is_r)
{
	if (!lst || !lst2)
		return (1);
	if (is_r)
		return (comp_ascii(lst2, lst, 0));
	return (ft_strcmp(((t_fl*)lst->content)->name,
			((t_fl*)lst2->content)->name) >= 0);
}

int	comp_time(t_list *lst, t_list *lst2, int is_r)
{
	t_fl	*fl1;
	t_fl	*fl2;

	if (!lst || !lst2)
		return (1);
	if (is_r)
		return (comp_time(lst2, lst, 0));
	fl1 = lst->content;
	fl2 = lst2->content;
	if (fl1->time < fl2->time)
		return (1);
	if (fl1->time == fl2->time)
		return (ft_strcmp(fl1->name, fl2->name) >= 0);
	return (0);
}

int	comp_size(t_list *lst, t_list *lst2, int is_r)
{
	t_fl *fl1;
	t_fl *fl2;

	if (!lst || !lst2)
		return (1);
	if (is_r)
		return (comp_size(lst2, lst, 0));
	fl1 = lst->content;
	fl2 = lst2->content;
	if (fl1->sbuff.st_size < fl2->sbuff.st_size)
		return (1);
	if (fl1->sbuff.st_size == fl2->sbuff.st_size)
		return (ft_strcmp(fl1->name, fl2->name) >= 0);
	return (0);
}

int	none_comp(t_list *lst, t_list *lst2, int is_r)
{
	is_r = 42;
	if (!lst || !lst2)
		return (1);
	return (1);
}
