/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:13:04 by hharvey           #+#    #+#             */
/*   Updated: 2019/02/12 15:31:45 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "libft.h"
# include "mlx.h"

# define WD_X 2560
# define WD_Y 1200

typedef struct		s_all
{
	t_mlx			mlx;
	t_arrnum		*a;
	t_arrnum		*b;
	double			wide;
	double			height;
}					t_all;

typedef struct		s_dblpoint
{
	double			x;
	double			y;
}					t_dblpoint;

typedef struct		s_stacks
{
	t_arrnum		*a;
	t_arrnum		*b;
}					t_stacks;

void				add_res_nc(char **res, char *str, t_stacks *stack);
void				add_res(char **res, char *str, t_stacks *stack,
							int *pcount);
void				set_stack(t_stacks *stack, t_arrnum *a, t_arrnum *b);

void				ft_dblpointset(t_dblpoint *p, double x, double y);

void				visual_checker(t_arrnum *a, t_arrnum *b);
int					ft_end(void *param);
void				init(t_mlx *mlx);

void				read_stacks(t_arrnum *a, t_arrnum *b, int argc,
								char **argv);
t_arrnum			*readnums(t_arrnum *arrnum, int argc, char **argv);
void				split_n_read(t_arrnum *a, char *str);

void				*get_f(char *s);

void				sort_a(t_arrnum *a, t_arrnum *b, int end, char **res);
void				small_sort_a(t_arrnum *a, t_arrnum *b, int end, char **res);
void				small_sort_b(t_arrnum *a, t_arrnum *b, int end, char **res);
void				sort_b(t_arrnum *a, t_arrnum *b, int end, char **res);
void				push_swap(t_arrnum *a, t_arrnum *b);
void				smart_print(char *str);
void				rb_back(t_arrnum *a, int racount, char **res);
void				ra_back(t_arrnum *a, int racount, char **res);

void				sarr(t_arrnum *arrnum);
void				rarr(t_arrnum *arrnum);
void				rrarr(t_arrnum *arrnum);
void				parr(t_arrnum *arrnum1, t_arrnum *arrnum2);

void				pa(t_arrnum *a, t_arrnum *b);
void				pb(t_arrnum *a, t_arrnum *b);
void				sa(t_arrnum *a, t_arrnum *b);
void				sb(t_arrnum *a, t_arrnum *b);
void				ss(t_arrnum *a, t_arrnum *b);
void				ra(t_arrnum *a, t_arrnum *b);
void				rb(t_arrnum *a, t_arrnum *b);
void				rr(t_arrnum *a, t_arrnum *b);
void				rra(t_arrnum *a, t_arrnum *b);
void				rrb(t_arrnum *a, t_arrnum *b);
void				rrr(t_arrnum *a, t_arrnum *b);

void				print_all(t_arrnum a, t_arrnum b);

#endif
