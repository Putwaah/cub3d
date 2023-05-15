#include "cub3d.h"

static int	check_from_start(t_map *map, int z)
{
	int	first;

	first = 0;
	while (map->map_cpy[z][first] != '1' && map->map_cpy[z][first])
	{
		if (map->map_cpy[z][first] == '0')
			exit_error(map, "map not closed");
		if (map->map_cpy[z][first] == 'N' || map->map_cpy[z][first] == 'S'
			|| map->map_cpy[z][first] == 'W' || map->map_cpy[z][first] == 'E')
			exit_error(map, "map error");
		first++;
	}
	if (map->map_cpy[z][first] != '1')
		exit_error(map, "problemo");
	return (first);
}

static int	check_from_end(t_map *map, int z)
{
	int	last;

	last = ft_strlen(map->map_cpy[z]);
	while (map->map_cpy[z][last] != '1' && last >= 0)
	{
		if (map->map_cpy[z][last] == '0')
			exit_error(map, "map error");
		if (map->map_cpy[z][last] == 'N' || map->map_cpy[z][last] == 'S'
			|| map->map_cpy[z][last] == 'W' || map->map_cpy[z][last] == 'E')
			exit_error(map, "map error");
		last--;
	}
	if (map->map_cpy[z][last] != '1')
		exit_error(map, "problemo");
	return (last);
}

static void	check_connect_start(t_map *map, int line, int start)
{
	int start_above;
	int	start_under;

	start_above = check_from_start(map, line - 1);
	start_under = check_from_start(map, line + 1);
	connect_start_above(map, line, start, start_above);
	connect_start_under(map, line, start, start_under);
}

static void	check_connect_end(t_map *map, int line, int last)
{
	int last_above;
	int	last_under;

	last_above = check_from_end(map, line - 1);
	last_under = check_from_end(map, line + 1);
	connect_end_above(map, line, last, last_above);
	connect_end_under(map, line, last, last_under);
}

void	check_the_line(t_map *map, int z)
{
	int	first;
	int last;
	int	tmp;
	
	first = check_from_start(map, z);
	last = check_from_end(map, z);
	tmp = first;
	while (tmp < last)
	{
		if (map->map_cpy[z][tmp] == '0' && (map->map_cpy[z + 1][tmp] == ' '
			|| map->map_cpy[z - 1][tmp] == ' ' || map->map_cpy[z][tmp + 1] == ' '
			|| map->map_cpy[z - 1][tmp - 1] == ' '))
			exit_error(map, "map error");
		tmp++;
	} 
	check_connect_start(map, z, first);
	check_connect_end(map, z, last);
}