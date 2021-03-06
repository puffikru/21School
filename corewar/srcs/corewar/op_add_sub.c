/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add_sub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 09:19:57 by djast             #+#    #+#             */
/*   Updated: 2019/12/06 17:30:27 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	make_command_add(t_vm_info *info, t_carriage *carr)
{
	int sum;

	ft_bzero(carr->args_types, 3 * sizeof(int));
	get_op_arg_type(info, carr);
	get_op_arg(info, carr, carr->op_code);
	if (info->debug_flag == 1)
		ft_printf("add r%d r%d r%d\n", carr->args[0], carr->args[1],
														carr->args[2]);
	sum = carr->registers[carr->args[0] - 1] +
			carr->registers[carr->args[1] - 1];
	carr->registers[carr->args[2] - 1] = sum;
	calc_jump_size(carr);
	if (sum == 0)
		carr->carry = 1;
	else
		carr->carry = 0;
}

void	make_command_sub(t_vm_info *info, t_carriage *carr)
{
	int sub;

	ft_bzero(carr->args_types, 3 * sizeof(int));
	get_op_arg_type(info, carr);
	get_op_arg(info, carr, carr->op_code);
	if (info->debug_flag == 1)
		ft_printf("sub r%d r%d r%d\n", carr->args[0], carr->args[1],
														carr->args[2]);
	sub = carr->registers[carr->args[0] - 1] -
			carr->registers[carr->args[1] - 1];
	carr->registers[carr->args[2] - 1] = sub;
	calc_jump_size(carr);
	if (sub == 0)
		carr->carry = 1;
	else
		carr->carry = 0;
}
