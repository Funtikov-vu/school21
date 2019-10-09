/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 16:34:08 by hharvey           #+#    #+#             */
/*   Updated: 2019/02/12 16:14:55 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*get_f(char *s)
{
	if (ft_strequ(s, "rrr"))
		return (rrr);
	else if (ft_strequ(s, "rr"))
		return (rr);
	else if (ft_strequ(s, "ss"))
		return (ss);
	else if (ft_strequ(s, "rb"))
		return (rb);
	else if (ft_strequ(s, "ra"))
		return (ra);
	else if (ft_strequ(s, "rrb"))
		return (rrb);
	else if (ft_strequ(s, "rra"))
		return (rra);
	else if (ft_strequ(s, "pa"))
		return (pa);
	else if (ft_strequ(s, "pb"))
		return (pb);
	else if (ft_strequ(s, "sb"))
		return (sb);
	else if (ft_strequ(s, "sa"))
		return (sa);
	else
		ft_error();
	return (0);
}

void	print_all(t_arrnum a, t_arrnum b)
{
	ft_arrnumprint(a);
	ft_arrnumprint(b);
}

void	add_res(char **res, char *str, t_stacks *stack, int *count)
{
	void	(*f)();

	*res = ft_strjdelfst(*res, str);
	*res = ft_strjdelfst(*res, " ");
	f = get_f(str);
	f(stack->a, stack->b);
	*count += 1;
}

void	add_res_nc(char **res, char *str, t_stacks *stack)
{
	void	(*f)();

	*res = ft_strjdelfst(*res, str);
	*res = ft_strjdelfst(*res, " ");
	f = get_f(str);
	f(stack->a, stack->b);
}

void	set_stack(t_stacks *stack, t_arrnum *a, t_arrnum *b)
{
	stack->a = a;
	stack->b = b;
}
