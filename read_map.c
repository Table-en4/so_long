/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 18:28:17 by molapoug          #+#    #+#             */
/*   Updated: 2025/06/03 18:13:30 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	len_y(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	elements_pos(t_game *pos)
{
	t_map	*map;

	map = NULL;
	map->c = 0;
	map->p = 0;
	map->e = 0;
	map->y = len_y(pos->map->map) - 1;
	while (map->y--)
	{
		map->x = 0;
		while (pos->map->map[map->y][map->x] != '\0')
		{
			if (pos->map->map[map->y][map->x] == 'C')
				map->c++;
			else if (pos->map->map[map->y][map->x] == 'P')
			{
				display_img(*pos);
			}
			//	map.p++;
			else if (pos->map->map[map->y][map->x] == 'E')
				map->e++;
			map->x++;
		}
	}
	if (map->c == 0 || map->p == 0 || map->p == 0)
		perror("Map error\n");
}

char	**get_map(char *map)
{
	char	*line;
	char	*lines;
	int		fd;

	map = "maps/map.ber";
	line = "";
	lines = ft_strdu("");
	fd = open(map, 'r');
	if (fd < 0)
		perror("Can't open file\n");
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
			break ;
		lines = ft_strjoin(lines, line);
		free(line);
	}
	free(line);
	close(fd);
	if (lines[0] == '\0')
		perror("Bad map\n");
	return (ft_split(lines, '\n'));
}

void	display_pos(t_game game)
{
	int	i;

	i = 0;
	while (game.map->map[i])
	{
		get_map(*game.map->map);
		printf("%d\n", i);
		i++;
	}
}
