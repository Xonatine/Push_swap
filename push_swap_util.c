/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlorenz <frlorenz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:37:00 by frlorenz          #+#    #+#             */
/*   Updated: 2024/05/30 11:53:18 by frlorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	handle_five(t_list_node **a, t_list_node **b)
{
	while (stack_size(*a) > 3)
	{
		init_nodes(*a, *b);
		finish_rotation(a, find_small(*a), 'a');
		stack_push(a, b, 'b');
	}
}

void	sort_huge_stack(t_list_node **a, t_list_node **b)
{
	t_list_node	*small;
	int			size_a;

	size_a = stack_size(*a);
	if (size_a == 5)
		handle_five(a, b);
	else
	{
		while (size_a-- > 3)
			stack_push(a, b, 'b');
	}
	sort_stack(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	stack_orderer(a);
	small = find_small(*a);
	if (small->above_median)
		while (*a != small)
			stack_rotate(a, NULL, 'a');
	else
		while (*a != small)
			stack_reverse_rotate(a, NULL, 'a');
}
