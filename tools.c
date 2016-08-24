/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarie-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 13:41:46 by smarie-c          #+#    #+#             */
/*   Updated: 2016/08/24 13:41:50 by smarie-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_column_count(char *str)
{
	int		ret;
	int		i;
	int		j;

	ret = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (ft_isdigit(str[i + j]))
			j++;
		if (j)
			ret++;
		i += j;
		while (str[i] && !ft_isdigit(str[i]))
			i++;
	}
	return (ret);
}

int				ft_check_line(char *map, int fd)
{
	static int		i = -1;

	if (i == -1)
		i = ft_column_count(map);
	else if (i != ft_column_count(map))
	{
		close(fd);
		free(map);
		ft_putendl_fd("WRONG MAP {map is not a square}!", 2);
		exit(0);
	}
	return (i);
}

int				ft_getn_number(char *str, int n)
{
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	while (str[i])
	{
		if (ret == n)
			return (ft_atoi(str + i));
		while (!ft_isdigit(str[i]) && str[i])
			i++;
		while (ft_isdigit(str[i]))
			i++;
		ret++;
	}
	return (0);
}

void			ft_isnum_or_space(t_data *data, char *map, int fd)
{
	int		i;

	i = 0;
	while (map[i])
	{
		if (map[i] != '-' && map[i] != ' ' && map[i] != '\t'
			&& (map[i] < '0' || map[i] > '9'))
		{
			close(fd);
			free(map);
			ft_putendl_fd("WRONG MAP {trailing characters on the map}!", 2);
			ft_free_data(data);
		}
		i++;
	}
}

int				ft_open(t_data *data, char *map)
{
	int		fd;

	if ((fd = open(map, O_RDONLY)) <= 0)
	{
		ft_putendl_fd("WRONG MAP {file is not in valid format}!", 2);
		ft_free_data(data);
	}
	return (fd);
}
