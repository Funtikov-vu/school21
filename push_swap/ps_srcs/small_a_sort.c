/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_a_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 20:32:28 by hharvey           #+#    #+#             */
/*   Updated: 2019/02/12 16:33:19 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_a_3(t_arrnum *a, int end, char **res)
{
	if (a->arr[1] < a->arr[0] && a->arr[1] > a->arr[2])
	{
		if (end == a->size)
		{
			sa(a, 0);
			rra(a, 0);
			*res = ft_strjdelfst(*res, "sa rra ");
			return ;
		}
		sa(a, 0);
		ra(a, 0);
		sa(a, 0);
		rra(a, 0);
		sa(a, 0);
		*res = ft_strjdelfst(*res, "sa ra sa rra sa ");
	}
}

void	sort_three_a_2(t_arrnum *a, int end, char **res)
{
	if (a->arr[0] > a->arr[1] && a->arr[0] < a->arr[2])
	{
		sa(a, 0);
		*res = ft_strjdelfst(*res, "sa ");
	}
	else if (a->arr[2] > a->arr[1] && a->arr[2] < a->arr[0])
	{
		if (end == a->size)
		{
			ra(a, 0);
			*res = ft_strjdelfst(*res, "ra ");
			return ;
		}
		sa(a, 0);
		ra(a, 0);
		sa(a, 0);
		rra(a, 0);
		*res = ft_strjdelfst(*res, "sa ra sa rra ");
	}
	else
		return (sort_three_a_3(a, end, res));
}

void	sort_three_a(t_arrnum *a, int end, char **res)
{
	if (a->arr[1] > a->arr[0] && a->arr[1] < a->arr[2])
		return ;
	else if (a->arr[2] > a->arr[0] && a->arr[2] < a->arr[1])
	{
		ra(a, 0);
		sa(a, 0);
		rra(a, 0);
		*res = ft_strjdelfst(*res, "ra sa rra ");
	}
	else if (a->arr[0] < a->arr[1] && a->arr[0] > a->arr[2])
	{
		if (end == a->size)
		{
			rra(a, 0);
			*res = ft_strjdelfst(*res, "rra ");
			return ;
		}
		ra(a, 0);
		sa(a, 0);
		rra(a, 0);
		sa(a, 0);
		*res = ft_strjdelfst(*res, "ra sa rra sa ");
	}
	else
		return (sort_three_a_2(a, end, res));
}

void	small_sort_a(t_arrnum *a, t_arrnum *b, int end, char **res)
{
	b = 0;
	if (end < 2)
		return ;
	else if (end == 2)
	{
		if (a->arr[0] > a->arr[1])
		{
			*res = ft_strjdelfst(*res, "sa ");
			sa(a, 0);
		}
		return ;
	}
	else if (end == 3)
		return (sort_three_a(a, end, res));
}
