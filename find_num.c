/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 20:52:09 by hnioo             #+#    #+#             */
/*   Updated: 2025/12/02 13:17:10 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long    min_num(t_stack **stack)
{
    t_stack *tmp;
    long    min_num;

    tmp = *stack;
    min_num = tmp->num;
    while (tmp)
    {
        if (tmp->num < min_num)
            min_num = tmp->num;
        tmp = tmp->next;
    }
    return (min_num);
}

int	find_pos(t_stack **a, int value)
{
	t_stack	*tmp;
	int		i;

	tmp = *a;
	i = 0;
	while (tmp)
	{
		if (tmp->num == value)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

long    get_max_pos(t_stack *stack)
{
	long	max_idx;
	long	pos;
	long	max_pos;

	max_idx = stack->idx;
	pos = 0;
	max_pos = 0;
	while (stack)
	{
		if (max_idx < stack->idx)
		{
			max_idx = stack->idx;
			max_pos = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (max_pos);
}
