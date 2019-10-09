/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add_sub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 09:19:57 by djast             #+#    #+#             */
/*   Updated: 2019/10/09 09:20:24 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	make_command_add(t_vm_info *info, t_champ *champs, t_carriage *carr)
{
	int sum;
	(void) champs;

	ft_bzero(carr->args_types, 3 * sizeof(int));
	get_op_arg_type(info, carr);
	get_op_arg(info, carr, carr->op_code);
	sum = carr->registers[carr->args[0] - 1] + carr->registers[carr->args[1] - 1];
	carr->registers[carr->args[2] - 1] = sum;

	if (sum == 0)
		carr->carry = 1;
	else
		carr->carry = 0;
}

void	make_command_sub(t_vm_info *info, t_champ *champs, t_carriage *carr)
{
	int sub;
	(void) champs;

	ft_bzero(carr->args_types, 3 * sizeof(int));
	get_op_arg_type(info, carr);
	get_op_arg(info, carr, carr->op_code);
	sub = carr->registers[carr->args[0] - 1] - carr->registers[carr->args[1] - 1];
	carr->registers[carr->args[2] - 1] = sub;
	calc_jump_size(carr);
	if (sub == 0)
		carr->carry = 1;
	else
		carr->carry = 0;
}