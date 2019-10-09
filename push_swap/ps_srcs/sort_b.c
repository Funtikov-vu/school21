/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:57:27 by hharvey           #+#    #+#             */
/*   Updated: 2019/02/12 14:53:07 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b_init(int *i, int *alen, int *rbcount)
{
	*i = -1;
	*alen = 0;
	*rbcount = 0;
}

void	sort_b(t_arrnum *a, t_arrnum *b, int end, char **res)
{
	int			med;
	int			i;
	int			alen;
	int			rbcount;
	t_stacks	stack;

	set_stack(&stack, a, b);
	med = ft_arrnumgetmed(*b, 0, end);
	sort_b_init(&i, &alen, &rbcount);
	if (end <= 3)
		return (small_sort_b(a, b, end, res));
	else
		while (++i < end)
			if (b->arr[0] > med)
				add_res(res, "pa", &stack, &alen);
			else
				add_res(res, "rb", &stack, &rbcount);
	if (end - alen != b->size)
		rb_back(b, rbcount, res);
	sort_a(a, b, alen, res);
	sort_b(a, b, end - alen, res);
}
