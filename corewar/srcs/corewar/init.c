/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:58:35 by djast             #+#    #+#             */
/*   Updated: 2019/10/08 16:20:51 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"


t_carriage			*init_carriage(int id, t_champ *cur_player, t_vm_info *info)
{
	t_carriage *new_carriage;
	int i;

	new_carriage = (t_carriage *)malloc(sizeof(t_carriage));
	new_carriage->id = id;
	new_carriage->carry = 0;
	new_carriage->op_code = -1;
	new_carriage->cycle_last_live = -1;
	new_carriage->op_steps = 0;
	new_carriage->jump_size = 0;
	new_carriage->cur_pos = (id - 1) * (MEM_SIZE / info->count_players);
	new_carriage->registers[0] = -cur_player->id;
	i = 1;
	while (i < REG_NUMBER)
		new_carriage->registers[i++] = 0;
	new_carriage->next = NULL;
	return (new_carriage);
}


t_vm_info			*init_vm_info(t_champ *players)
{
	t_vm_info *info;

	info = (t_vm_info *)malloc(sizeof(t_vm_info));
	info->count_players = get_player_count(players);
	info->cycles_to_die = CYCLE_TO_DIE;
	info->cycle = 0;
	info->live = 0;
	info->last_live_player = NULL;
	info->map = ft_strnew(MEM_SIZE);
	return (info);
}

t_champ				*init_champ(int id)
{
	t_champ *champ;

	champ = (t_champ *)malloc(sizeof(t_champ));
	champ->id = id;
	champ->name = NULL;
	champ->comment = NULL;
	champ->code_size = -1;
	champ->code = NULL;
	champ->count_lives = 0;
	champ->last_live = 0;
	champ->next = NULL;
	return (champ);
}