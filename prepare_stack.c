/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlorenz <frlorenz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:35:40 by frlorenz          #+#    #+#             */
/*   Updated: 2024/05/23 14:46:20 by frlorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	stack_orderer(t_list_node **stack)
{
	t_list_node	*temp;
	int			i;
	int			mid;

	i = 0;
	if (*stack != NULL)
	{
		temp = *stack;
		mid = stack_size(temp) / 2;
		while (temp)
		{
			temp->index = i;
			if (i <= mid)
				temp->above_median = true;
			else
				temp->above_median = false;
			i++;
			temp = temp->next;
		}
	}
}

static void	set_target_node(t_list_node *a, t_list_node *b)
{
	t_list_node	*current;
	t_list_node	*target_node;
	long		best;

	while (b)
	{
		best = INT_MAX;
		current = a;
		while (current)
		{
			if (current->content > b->content && current->content < best)
			{
				best = current->content;
				target_node = current;
			}
			current = current->next;
		}
		if (INT_MAX == best)
			b->target_node = find_small(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	set_price(t_list_node *a, t_list_node *b)
{
	int	size_a;
	int	size_b;

	size_a = stack_size(a);
	size_b = stack_size(b);
	while (b)
	{
		b->push_price = b->index;
		if (!(b->above_median))
			b->push_price = size_b - (b->index);
		if (b->target_node->above_median)
			b->push_price += b->target_node->index;
		else
			b->push_price += size_a - (b->target_node->index);
		b = b->next;
	}
}

void	set_cheapest(t_list_node *b)
{
	int			best_match_value;
	t_list_node	*best_match_node;

	if (NULL == b)
		return ;
	best_match_value = INT_MAX;
	while (b)
	{
		if (b->push_price < best_match_value)
		{
			best_match_value = b->push_price;
			best_match_node = b;
		}
		b = b->next;
	}
	best_match_node->cheapest = true;
}

void	init_nodes(t_list_node *a, t_list_node *b)
{
	stack_orderer(&a);
	stack_orderer(&b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}
