/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlorenz <frlorenz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:47:50 by frlorenz          #+#    #+#             */
/*   Updated: 2024/05/30 11:58:58 by frlorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_list_node
{
	int					content;
	int					index;
	int					final_index;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_list_node	*target_node;
	struct s_list_node	*next;
	struct s_list_node	*prev;
}	t_list_node;

int			main(int argc, char **argv);
int			checkin(int argc, char **argv);
t_list_node	*last_node(t_list_node *stack);
void		stack_orderer(t_list_node **stack);
int			fill_stack(t_list_node **stack, int argc, char **argv);
int			stack_size(t_list_node *stack);
void		stack_swaping(t_list_node **a, t_list_node **b, char selection);
void		stack_push(t_list_node **a, t_list_node **b, char selection);
void		stack_rotate(t_list_node **a, t_list_node **b, char selection);
void		stack_reverse_rotate(t_list_node **a, t_list_node **b, char select);
bool		stack_sorted(t_list_node *stack);
void		sort_stack(t_list_node **stack);
t_list_node	*find_small(t_list_node *stack);
t_list_node	*find_cheap(t_list_node *stack);
void		sort_huge_stack(t_list_node **a, t_list_node **b);
void		init_nodes(t_list_node *a, t_list_node *b);
void		finish_rotation(t_list_node **stack, t_list_node *top, char s);
void		move_nodes(t_list_node **a, t_list_node **b);
char		**memfree(char **array, int j);
void		free_stack(t_list_node **stack);

#endif
