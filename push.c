/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlorenz <frlorenz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 00:16:22 by frlorenz          #+#    #+#             */
/*   Updated: 2024/05/23 12:58:27 by frlorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	push(t_list_node **org, t_list_node **dst);

void	stack_push(t_list_node **a, t_list_node **b, char selection)
{
	if (selection == 'a')
	{
		if (*b != NULL)
		{
			push(b, a);
			ft_printf("pa\n");
		}
	}
	if (selection == 'b')
	{
		if (*a != NULL)
		{
			push(a, b);
			ft_printf("pb\n");
		}
	}
}

static void	push(t_list_node **org, t_list_node **dst)
{
	t_list_node	*temporg;
	t_list_node	*tempdst;

	temporg = *org;
	tempdst = *dst;
	if (temporg->next != NULL)
	{
		temporg->next->prev = NULL;
		*org = temporg->next;
	}
	else
		*org = NULL;
	if (*dst == NULL)
		temporg->next = NULL;
	else
	{
		tempdst->prev = temporg;
		temporg->next = tempdst;
	}
	*dst = temporg;
}
