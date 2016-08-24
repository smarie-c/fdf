/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarie-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 13:59:42 by smarie-c          #+#    #+#             */
/*   Updated: 2016/08/24 13:59:46 by smarie-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include "minilibx_macos/mlx.h"
# define WIDTH 1000
# define HEIGHT 1000
# define ABS(x) ( ( (x) < 0) ? -(x) : (x) )
# define FONT_COLOR 0x330066
# define NB_KEY 16
# define KEY_R 15
# define KEY_ESC 53
# define KEY_PLUS 69
# define KEY_MINUS 78
# define KEY_NUM_2 84
# define KEY_NUM_3 85
# define KEY_NUM_4 86
# define KEY_NUM_6 88
# define KEY_NUM_8 91
# define KEY_NUM_9 92
# define KEY_PAGE_UP 116
# define KEY_PAGE_DOWN 121
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
	double		w;
	double		a;
	double		b;
	double		c;
	int			color;
}				t_vector;

typedef struct	s_matrix
{
	double	a;
	double	b;
	double	c;
	double	d;
	double	e;
	double	f;
	double	g;
	double	h;
	double	i;
	double	j;
	double	k;
	double	l;
	double	m;
	double	n;
	double	o;
	double	p;
}				t_matrix;

typedef struct	s_data
{
	int			nb_line;
	int			nb_col;
	t_vector	***map;
	t_matrix	rotx;
	t_matrix	roty;
	t_matrix	rotz;
	t_matrix	translate;
	t_matrix	scale;
	t_matrix	tmp;
	double		posx;
	double		posy;
	double		posz;
	double		rot_x;
	double		rot_y;
	double		rot_z;
	double		c_scale;
	double		cz_scale;
	double		s_scale;
	int			c_color;
	void		*core;
	void		*win;
	void		*img;
	char		*str;
	int			bpp;
	int			sl;
	int			endian;
}				t_data;

typedef void	(*t_fct)(t_data *);

typedef struct	s_key
{
	int		key;
	t_fct	fct;
}				t_key;

void			actu_map(t_data *data);

void			ft_quadrilage(t_data *data);

void			m4_rot_x(t_matrix *m, double angle);
void			m4_rot_y(t_matrix *m, double angle);
void			m4_rot_z(t_matrix *m, double angle);

void			down_rot_x(t_data *data);
void			down_rot_y(t_data *data);
void			down_rot_z(t_data *data);

void			ft_put_pixel_to_screen(t_data *e, int x, int y, int color);

void			up_c_scale(t_data *data);
void			down_c_scale(t_data *data);
void			up_cz_scale(t_data *data);
void			down_cz_scale(t_data *data);

int				ft_event_expose(t_data *data);
int				ft_event(int keycode, t_data *data);

t_key			**ft_get_key(int flag);

void			read_object(char *file, t_data *data);

void			ft_clear_with_color(t_data *data, int color);

t_vector		*m4_mul_v4(t_matrix *m, t_vector *v);
t_matrix		*m4_mul_m4(t_matrix *m, t_matrix *b, t_matrix *a);
void			m4_identity(t_matrix *m);
void			m4_translate(t_matrix *m, double i, double j, double k);
void			m4_scale(t_matrix *m, double nx, double ny, double nz);

void			right_event(t_data *data);
void			left_event(t_data *data);
void			down_event(t_data *data);
void			up_event(t_data *data);

int				ft_getn_number(char *str, int n);
int				ft_open(t_data *data, char *map);
void			ft_isnum_or_space(t_data *data, char *map, int fd);
int				ft_check_line(char *map, int fd);

void			up_rot_x(t_data *data);
void			up_rot_y(t_data *data);
void			up_rot_z(t_data *data);

void			init_matrix(t_data *data);
void			init_var(t_data *data);
void			ft_free_data(t_data *data);

#endif
