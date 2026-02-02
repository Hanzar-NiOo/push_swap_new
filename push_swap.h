/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 00:06:17 by hnioo             #+#    #+#             */
/*   Updated: 2025/12/02 14:05:27 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define TARGET_NUM 0
# define PUSHED_COUNT 1

# include "libft/libft.h"

typedef struct s_stack
{
	int				num;
	int				idx;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

void	error(void);
int		assign_idx(char **results, int num);
t_stack	*new_node(int num, char **results);
void	append_node(t_stack **head, t_stack *node);
t_stack	**get_stack(char **results);
int		is_duplicated(t_stack **a);
int		is_valid_input(t_stack **a);
t_stack	*lst_last(t_stack *lst);
int		is_sorted(t_stack **a);
int		stack_size(t_stack **a);

void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

int		min_num(t_stack **stack);
int		find_pos(t_stack **a, int value);
void	sort_three(t_stack **a);
void	small_sort(t_stack **a);
int		get_max_pos(t_stack *stack);
void	butterfly_sort(t_stack **a, t_stack **b);

#endif