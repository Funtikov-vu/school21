/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_ps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 20:03:12 by hharvey           #+#    #+#             */
/*   Updated: 2019/02/12 16:30:28 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_arrnum *a, t_arrnum *b)
{
	parr(a, b);
}

void	pa(t_arrnum *a, t_arrnum *b)
{
	parr(b, a);
}

void	sa(t_arrnum *a, t_arrnum *b)
{
	b = 0;
	sarr(a);
}

void	sb(t_arrnum *a, t_arrnum *b)
{
	a = 0;
	sarr(b);
}

void	ss(t_arrnum *a, t_arrnum *b)
{
	sarr(a);
	sarr(b);
}
