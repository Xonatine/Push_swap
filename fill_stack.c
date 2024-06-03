/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlorenz <frlorenz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:58:09 by frlorenz          #+#    #+#             */
/*   Updated: 2024/05/30 12:41:55 by frlorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static t_list_node	*new_node(char *number);
int					stack_size(t_list_node *stack);
t_list_node			*last_node(t_list_node *stack);
static void			attach_node(t_list_node **stack, t_list_node *new);

int	fill_stack(t_list_node **stack, int argc, char **argv)
{
	t_list_node	*node;
	int			i;

	i = 1;
	while (i < argc)
	{
		node = new_node(argv[i]);
		if (!node)
		{
			memfree(argv, argc);
			free_stack(stack);
			return (0);
		}
		attach_node(stack, node);
		i++;
	}
	return (1);
}

static t_list_node	*new_node(char *number)
{
	t_list_node	*node;

	node = (t_list_node *) malloc (sizeof (t_list_node));
	if (!node)
		return (0);
	node->content = ft_atoi(number);
	node->index = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

int	stack_size(t_list_node *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

t_list_node	*last_node(t_list_node *stack)
{
	int	i;
	int	j;

	i = stack_size(stack);
	j = 0;
	while (j < i - 1)
	{
		stack = stack->next;
		j++;
	}
	return (stack);
}

static void	attach_node(t_list_node **stack, t_list_node *new)
{
	t_list_node	*last;

	last = *stack;
	if (last == NULL)
	{
		*stack = new;
		new ->index = 0;
	}
	else
	{
		last = last_node(*stack);
		last->next = new;
		new->prev = last;
		new->index = last->index + 1;
	}
}
