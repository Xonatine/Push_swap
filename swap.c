/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlorenz <frlorenz@student.42madrid.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:28:18 by frlorenz          #+#    #+#             */
/*   Updated: 2024/05/23 12:28:54 by frlorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	swap(t_list_node **stack);

void	stack_swaping(t_list_node **a, t_list_node **b, char selection)
{
	if (selection == 'a')
	{
		if (swap(a) == 1)
			ft_printf("sa\n");
	}
	if (selection == 'b')
	{
		if (swap(b) == 1)
			ft_printf("sb\n");
	}
	if (selection == 's')
	{
		if (swap(a) == 1)
		{
			if (swap(b) == 1)
				ft_printf("ss\n");
			else
				swap(a);
		}
	}
}

static int	swap(t_list_node **stack)
{
	t_list_node	*tempf;
	t_list_node	*temps;

	if (*stack != NULL )
	{
		tempf = *stack;
		temps = tempf->next;
		if (temps != NULL)
		{
			tempf->next = temps->next;
			if (temps->next != NULL)
				temps->next->prev = tempf;
			tempf->prev = temps;
			temps->prev = NULL;
			temps->next = tempf;
			*stack = temps;
		}
		else
			return (0);
	}
	else
		return (0);
	return (1);
}
