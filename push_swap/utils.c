/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vurrigon <vurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 16:45:28 by vurrigon          #+#    #+#             */
/*   Updated: 2019/06/13 18:34:33 by vurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list	*ft_create_lst(int	nbr)
{
	t_list	*list;

	if ((list = malloc(sizeof(t_list))))
	{
		list->value = nbr;
		list->next = NULL;
		return (list);
	}
	return (NULL);
}

t_lst	*create_a(char **data)
{
	t_lst	*current;
	int		i;

	i = 0;
	while (data[i])
	{
		
	}
	while (current->next)
		current = current->next;
	if (!(current->next = ft_create_lst(data)))
		return (0);
}