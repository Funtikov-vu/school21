/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdflib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharvey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:16:30 by hharvey           #+#    #+#             */
/*   Updated: 2019/01/29 15:53:18 by hharvey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDFLIB_H

# define FDFLIB_H
# define MOVE 100
# define RANGLE PI/24
# define DEF_SCALE 1.5

# include "libft.h"

typedef struct		s_pntarr
{
	t_3point		**pnt;
	int				size_x;
	int				size_y;
}					t_pntarr;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img_data;
	int				bpp;
	int				size_line;
	int				endian;
}					t_mlx;

typedef struct		s_ang
{
	double			x;
	double			y;
	double			z;
}					t_ang;

typedef struct		s_all
{
	t_pntarr		pntarr;
	t_pntarr		*temp;
	t_mlx			mlx;
	t_3point		ang;
	t_3point		shift;
	int				scale;
}					t_all;

int					ft_end(void *param);
void				set_all(t_all *all, t_mlx mlx, t_pntarr pntarr);
void				set_mlx(t_mlx *mlx, void *mlx_ptr, void *win_ptr);
void				set_pntarr(t_pntarr *pntarr, t_3point **pnt,
		int size_x, int size_y);
void				ft_parcing(int argc, char **argv, t_pntarr *pntarr);
int					ft_gradient(int x, int delta, int color_min,
		int color_max);
void				set_ang(t_ang *ang, double x, double y, double z);
t_pntarr			*cpy_pntarr(t_pntarr pntarr);
void				del_pntarr(t_pntarr *pntarr);

void				x_rotate(t_pntarr pntarr, double alpha);
void				y_rotate(t_pntarr pntarr, double alpha);
void				z_rotate(t_pntarr pntarr, double alpha);
char				*draw_pnt(t_pntarr pntarr, t_mlx mlx, int color);

void				shift(t_pntarr pntarr, t_3point pnt);
void				shift_z(t_pntarr pntarr, int shift);
void				scaling(t_pntarr pntarr, int k);

void				move_to_zero(t_pntarr pntarr);
void				move_back(t_pntarr pntarr);

#endif
