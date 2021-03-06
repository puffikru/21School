/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vurrigon <vurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 19:06:05 by vurrigon          #+#    #+#             */
/*   Updated: 2019/07/27 17:18:26 by vurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "libft/ft_printf.h"

typedef struct			s_lst
{
	struct s_lst	*next;
	int				value;
	int				mark:2;
	int				count_op_a;
	int				count_op_b;
	int				sum_step;
	int				index;
}						t_lst;
typedef struct			s_head
{
	struct s_lst	*a;
	struct s_lst	*b;
	char			*operation;
	int				do_write:2;
	int				do_debug:2;
	int				in_file:2;
}						t_head;
int						valid(char **str);
t_lst					*create_lst(char **data);
t_head					*create_head(char **data, int write,
										int do_debug, int in_file);
int						read_command(t_head **head);
void					do_sa(t_head **head);
void					do_sb(t_head **head);
void					do_ss(t_head **head);
void					do_pa(t_head **head);
void					do_pb(t_head **head);
t_lst					*ft_create_elem(int data, int mark, int index);
void					delete_last_elem(t_lst **list);
void					do_ra(t_head **head);
void					do_rb(t_head **head);
void					do_rr(t_head **head);
void					do_rra(t_head **head);
void					do_rrb(t_head **head);
void					do_rrr(t_head **head);
int						check_sort(t_head *head);
int						get_len_stack(t_lst *stack);
void					sorting_below_four(t_head **head, int length);
void					sorting_below_six(t_head **head, int length);
int						get_smallest(t_lst *stack);
void					case_for_five(t_head **head);
int						get_max(t_lst *stack);
void					sorting_more_six(t_head **head);
void					swap_value(int *a, int *b);
void					main_sorting(t_head **head);
void					solver(t_head **head, t_lst *stack_min);
void					print_stacks(t_head *head, char *command, int tmp);
void					zeroing_marks(t_head **head);
void					indexing(t_head **head);
void					sorting_case_one(t_head **head);
void					sorting_case_two(t_head **head);
void					sorting_case_three(t_head **head);
void					sorting_case_four(t_head **head);
void					sorting_case_five(t_head **head);
void					align_stack(t_head **head);
int						check_stack_b(int value, t_head *head);
int						check_stack_a(int value_b, t_head *head);
int						get_total_steps(int step_a, int step_b);

#endif
