/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vurrigon <vurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 16:38:56 by vurrigon          #+#    #+#             */
/*   Updated: 2019/08/30 16:39:39 by vurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	list_to_array(t_map *map, t_room *rooms, int count_rooms)
{
	t_room	*tmp;
	t_room	**array;
	int		i;

	i = 0;
	array = (t_room **)malloc(sizeof(rooms) * count_rooms);
	tmp = rooms;
	while (tmp)
	{
		array[i++] = tmp;
		tmp = tmp->next;
	}
	array[i] = NULL;
	map->array_rooms = array;
}

int		room_cmp(char *a, char *b)
{
	int		cmp;

	if ((cmp = ft_strcmp(a, b)) == 0)
		error("Error: Duplicate detected");
	return (cmp);
}

void	ft_swap(t_room **a, t_room **b)
{
	t_room	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int		sort_pass(t_room **array, int size)
{
	int		res;
	int		pos;

	res = 1;
	pos = 0;
	while (pos < size - 1)
	{
		//printf("OTLADKA === %s %s\n", (array[pos])->name, (array[pos + 1])->name);
		if (room_cmp((array[pos])->name, (array[pos + 1])->name) > 0)
		{
			res = 0;
			ft_swap(&array[pos], &array[pos + 1]);
		}
		pos++;
	}
	return (res);
}

void	sort_array_by_name(t_map **map, int size)
{
	t_room	**array;
	int		position;

	array = (*map)->array_rooms;
	position = 0;
	while (position < size)
	{
		if (sort_pass(array, size - position))
			return ;
		position++;
	}
}