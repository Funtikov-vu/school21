/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:57:05 by hharvey           #+#    #+#             */
/*   Updated: 2019/02/12 16:27:07 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a_init(int *i, int *blen, int *blen2, int *racount)
{
	*i = -1;
	*blen = 0;
	*blen2 = 0;
	*racount = 0;
}

int		sort_a_while(t_stacks stack, char **res, int end, int *blen)
{
	int			i;
	t_arrnum	*a;
	t_arrnum	*b;
	int			blen2;
	int			med;

	*blen = 0;
	blen2 = 0;
	a = stack.a;
	b = stack.b;
	med = ft_arrnumgetmed(*a, 0, end);
	i = -1;
	while (++i < end)
		if (a->arr[0] < med)
		{
			add_res_nc(res, "pb", &stack);
			if (b->arr[0] < med / 2)
				add_res(res, "rb", &stack, &blen2);
			else
				*blen += 1;
		}
		else
			add_res_nc(res, "ra", &stack);
	return (blen2);
}

void	sort_a(t_arrnum *a, t_arrnum *b, int end, char **res)
{
	int			med;
	int			blen;
	int			blen2;
	t_stacks	stack;

	set_stack(&stack, a, b);
	med = ft_arrnumgetmed(*a, 0, end);
	if (end <= 3)
		return (small_sort_a(a, b, end, res));
	else
		blen2 = sort_a_while(stack, res, end, &blen);
	if (end - blen - blen2 != a->size)
		ra_back(a, end - blen - blen2, res);
	sort_a(a, b, end - blen - blen2, res);
	sort_b(a, b, blen, res);
	sort_b(a, b, blen2, res);
}
