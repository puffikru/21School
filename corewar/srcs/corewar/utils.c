/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vurrigon <vurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 16:51:08 by djast             #+#    #+#             */
/*   Updated: 2019/12/29 15:29:37 by vurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			get_player_count(t_champ *champs)
{
	int		count;
	t_champ	*cur_champ;

	count = 0;
	cur_champ = champs;
	while (cur_champ != NULL)
	{
		count++;
		cur_champ = cur_champ->next;
	}
	return (count);
}

int			bytecode_to_int(t_vm_info *info, int pos, int count_bytes)
{
	int				result;
	int				i;
	int				sign;
	unsigned char	*buff;

	buff = (unsigned char *)malloc(sizeof(unsigned char) * count_bytes);
	i = 0;
	while (pos < 0)
		pos += MEM_SIZE;
	while (i++ < count_bytes)
		buff[i - 1] = info->map[(pos + i - 1) % MEM_SIZE];
	result = 0;
	i = 0;
	sign = buff[0] & 0b10000000;
	while (count_bytes)
	{
		if (sign)
			result += (buff[count_bytes - 1] ^ 0xFF) << (i++ * 8);
		else
			result += buff[count_bytes - 1] << (i++ * 8);
		count_bytes--;
	}
	result = sign ? ~(result) : result;
	free(buff);
	return (result);
}

char		*int_to_bytecode(int value, int size)
{
	int8_t		i;
	char		*data;

	i = 0;
	data = ft_strnew(size);
	while (size)
	{
		data[size - 1] = (uint8_t)((value >> i) & 0xFF);
		i += 8;
		size--;
	}
	return (data);
}

void		create_carr_copy(t_vm_info *info, t_carriage *carr)
{
	t_carriage	*new_carr;
	int			i;

	new_carr = init_carriage(carr->champ, info);
	i = 0;
	while (i++ < REG_NUMBER)
		new_carr->registers[i - 1] = carr->registers[i - 1];
	new_carr->carry = carr->carry;
	new_carr->cycle_last_live = carr->cycle_last_live;
	new_carr->next = info->carriages;
	info->carriages = new_carr;
}

char		*hex_to_charhex(int value)
{
	char	*data;

	data = ft_strnew(2);
	data[0] = value / 16 + '0';
	data[1] = value % 16 + '0';
	return (data);
}
