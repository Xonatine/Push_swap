/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlorenz <frlorenz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 00:16:11 by frlorenz          #+#    #+#             */
/*   Updated: 2024/05/28 12:02:32 by frlorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static t_list_node	*find_highest(t_list_node *stack);
t_list_node			*find_small(t_list_node *stack);
void				sort_stack(t_list_node **stack);
t_list_node			*find_cheap(t_list_node *stack);

bool	stack_sorted(t_list_node *stack)
{
	if (NULL == stack)
		return (1);
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (false);
		stack = stack->next;
	}
	return (true);
}

static t_list_node	*find_highest(t_list_node *stack)
{
	int			highest;
	t_list_node	*high_node;

	if (NULL == stack)
		return (NULL);
	highest = INT_MIN;
	while (stack)
	{
		if (stack->content > highest)
		{
			highest = stack->content;
			high_node = stack;
		}
		stack = stack->next;
	}
	return (high_node);
}

t_list_node	*find_small(t_list_node *stack)
{
	t_list_node	*small_node;
	int			small;

	if (stack == NULL)
		return (NULL);
	small = INT_MAX;
	while (stack)
	{
		if (stack->content < small)
		{
			small = stack->content;
			small_node = stack;
		}
		stack = stack->next;
	}
	return (small_node);
}

t_list_node	*find_cheap(t_list_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	sort_stack(t_list_node **stack)
{
	t_list_node	*high_node;

	high_node = find_highest(*stack);
	if (high_node == *stack)
		stack_rotate(stack, NULL, 'a');
	else if ((*stack)-> next == high_node)
		stack_reverse_rotate(stack, NULL, 'a');
	if ((*stack)->content > (*stack)->next->content)
		stack_swaping(stack, NULL, 'a');
}
