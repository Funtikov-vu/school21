/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:36:27 by hharvey           #+#    #+#             */
/*   Updated: 2019/02/13 14:12:18 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_back(t_arrnum *a, int racount, char **res)
{
	int i;

	i = 0;
	while (i < racount)
	{
		rra(a, 0);
		*res = ft_strjdelfst(*res, "rra ");
		i++;
	}
}

void	rb_back(t_arrnum *a, int racount, char **res)
{
	int i;

	i = 0;
	while (i < racount)
	{
		rra(a, 0);
		*res = ft_strjdelfst(*res, "rrb ");
		i++;
	}
}

void	norm(t_arrnum *a)
{
	t_arrnum	*temp;
	t_arrnum	*dup;
	int			i;

	temp = ft_arrnumdup(a);
	dup = ft_arrnumdup(a);
	ft_arrnumbblsrt(*temp);
	i = 0;
	while (i < a->size)
	{
		a->arr[ft_arrnumfndposnb(dup, temp->arr[i])] = i;
		i++;
	}
	ft_arrnumdel(dup);
	ft_arrnumdel(temp);
}

void	push_swap(t_arrnum *a, t_arrnum *b)
{
	char	*res;

	norm(a);
	res = 0;
	if (ft_arrnumissrt(*a) && b->size == 0)
		return ;
	sort_a(a, b, a->size, &res);
	free(a->arr);
	free(b->arr);
	smart_print(res);
	free(res);
}
