/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlorenz <frlorenz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:30:42 by frlorenz          #+#    #+#             */
/*   Updated: 2024/05/28 12:04:42 by frlorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	rotate(t_list_node **stack);
static void	reverse_rotate(t_list_node **stack);

void	stack_rotate(t_list_node **a, t_list_node **b, char selection)
{
	if (a != NULL)
	{
		if (selection == 'a')
		{
			rotate(a);
			ft_printf("ra\n");
		}
		else if (selection == 'b')
		{
			rotate(b);
			ft_printf("rb\n");
		}
		else if (selection == 's')
		{
			if (b != NULL)
			{
				rotate(a);
				rotate(b);
				ft_printf("rr\n");
			}
		}
	}
}

void	stack_reverse_rotate(t_list_node **a, t_list_node **b, char select)
{
	if (a != NULL)
	{
		if (select == 'a')
		{
			reverse_rotate(a);
			ft_printf("rra\n");
		}
		else if (select == 'b')
		{
			reverse_rotate(b);
			ft_printf("rrb\n");
		}
		else if (select == 's')
		{
			if (b != NULL)
			{
				reverse_rotate(a);
				reverse_rotate(b);
				ft_printf("rrr\n");
			}
		}
	}
}

static void	rotate(t_list_node **stack)
{
	t_list_node	*temp;
	t_list_node	*last;

	temp = *stack;
	if (temp != NULL && temp->next != NULL)
	{
		last = last_node(*stack);
		temp->next->prev = NULL;
		*stack = temp->next;
		temp->next = NULL;
		temp->prev = last;
		last->next = temp;
	}
}

static void	reverse_rotate(t_list_node **stack)
{
	t_list_node	*temp;
	t_list_node	*last;

	temp = *stack;
	if (temp != NULL && temp->next != NULL)
	{
		last = last_node(*stack);
		last->prev->next = NULL;
		last->prev = NULL;
		temp->prev = last;
		last->next = temp;
		*stack = last;
	}
}
