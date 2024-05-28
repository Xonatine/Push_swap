/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlorenz <frlorenz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:47:18 by frlorenz          #+#    #+#             */
/*   Updated: 2024/05/23 15:18:13 by frlorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	rotate_both(t_list_node **a, t_list_node **b, t_list_node *cheap)
{
	while (*a != cheap->target_node && *b != cheap)
		stack_rotate(a, b, 's');
	stack_orderer(a);
	stack_orderer(b);
}

static void	rrboth(t_list_node **a, t_list_node **b, t_list_node *cheap)
{
	while (*a != cheap->target_node && *b != cheap)
		stack_reverse_rotate(a, b, 's');
	stack_orderer(a);
	stack_orderer(b);
}

void	finish_rotation(t_list_node **stack, t_list_node *top, char s)
{
	while (*stack != top)
	{
		if (s == 'a')
		{
			if (top->above_median)
				stack_rotate(stack, NULL, 'a');
			else
				stack_reverse_rotate(stack, NULL, 'a');
		}
		else if (s == 'b')
		{
			if (top->above_median)
			{
				stack_rotate(stack, stack, 'b');
			}
			else
			{
				stack_reverse_rotate(stack, stack, 'b');
			}
		}
	}
}

void	move_nodes(t_list_node **a, t_list_node **b)
{
	t_list_node	*cheap;

	cheap = find_cheap(*b);
	if (cheap->above_median && cheap->target_node->above_median)
		rotate_both(a, b, cheap);
	else if (!(cheap->above_median) && !(cheap->target_node->above_median))
		rrboth(a, b, cheap);
	finish_rotation(b, cheap, 'b');
	finish_rotation(a, cheap->target_node, 'a');
	stack_push(a, b, 'a');
}
