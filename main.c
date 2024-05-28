/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlorenz <frlorenz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:19:23 by frlorenz          #+#    #+#             */
/*   Updated: 2024/05/28 19:50:12 by frlorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdlib.h>
#include <stdio.h>

static int	error(int argc, char **argv);
static void	push_swap(t_list_node *a, t_list_node *b, int argc, char **argv);

char	**memfree(char **array, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list_node	*a;
	t_list_node	*b;
	char		**temp;
	int			i;
	int			j;

	a = NULL;
	b = NULL;
	i = 1;
	j = 0;
	if (argc == 2)
	{
		temp = ft_split(argv[1], ' ');
		while (temp[j] != NULL)
			argv[i++] = temp[j++];
		if (temp[0] != NULL)
			argc = i;
	}
	push_swap(a, b, argc, argv);
	exit(-1);
	return (0);
}

static void	push_swap(t_list_node *a, t_list_node *b, int argc, char **argv)
{
	if (error(argc, argv) == 0)
		return ;
	else
		fill_stack(&a, argc, argv);
	if (!stack_sorted(a))
	{
		if (stack_size(a) == 2)
			stack_swaping(&a, &b, 'a');
		else if (stack_size(a) == 3)
			sort_stack(&a);
		else
			sort_huge_stack(&a, &b);
	}
	exit(-1);
}

static int	error(int argc, char **argv)
{
	if (argc == 1 || (argc == 2 && !argv[1][0]))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	else if (checkin(argc, argv) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}
