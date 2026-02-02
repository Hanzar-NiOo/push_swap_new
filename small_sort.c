/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:33:42 by hnioo             #+#    #+#             */
/*   Updated: 2025/12/01 23:10:42 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_three(t_stack **a)
{
    int	first;
	int	second;
	int	third;

	first = (*a)->num;
	second = (*a)->next->num;
	third = (*a)->next->next->num;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

static void min_move_top(t_stack **a, long size)
{
    int	    min;
	int	    pos;
    
	min = min_num(a);
	pos = find_pos(a, min);
    if (pos == 1)
        ra (a);
    else if (pos == 2)
    {
        ra (a);
        ra (a);
    }
    else if (pos == 3)
    {
        if (size == 5)
            rra(a);
        rra(a);
    }
    else if (pos == 4)
        rra(a);
}

void    small_sort(t_stack **a)
{
    t_stack **b;

    b = NULL;
    b = malloc(sizeof(t_stack *));
    if (stack_size(a) == 2)
        sa(a);
    else if (stack_size(a) == 3)
        sort_three(a);
    else if (stack_size(a) == 4 || stack_size(a) == 5)
    {
        if (stack_size(a) == 5)
        {
            min_move_top(a, stack_size(a));
            pb (a, b);
        }
        min_move_top(a, stack_size(a));
        pb (a, b);
        sort_three (a);
        if (stack_size(b) == 2)
            pa (a, b);
        pa (a, b);
    }
}
