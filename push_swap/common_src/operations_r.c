/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 20:05:20 by hharvey           #+#    #+#             */
/*   Updated: 2019/02/12 16:31:09 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_arrnum *a, t_arrnum *b)
{
	b = 0;
	rarr(a);
}

void	rb(t_arrnum *a, t_arrnum *b)
{
	rarr(b);
	a = 0;
}

void	rr(t_arrnum *a, t_arrnum *b)
{
	rarr(a);
	rarr(b);
}

void	rra(t_arrnum *a, t_arrnum *b)
{
	rrarr(a);
	b = 0;
}

void	rrb(t_arrnum *a, t_arrnum *b)
{
	rrarr(b);
	a = 0;
}
