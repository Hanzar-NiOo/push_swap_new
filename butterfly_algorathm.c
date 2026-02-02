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

static void	push_algorathm(t_stack **a, t_stack **b, int range, int vars[2])
{
	int	idx;

	idx = (*a)->idx;
	if (idx <= vars[TARGET_NUM])
	{
		pb(a, b);
		rb(b);
		vars[TARGET_NUM]++;
		vars[PUSHED_COUNT]++;
	}
	else if (idx <= vars[TARGET_NUM] + range)
	{
		pb(a, b);
		vars[TARGET_NUM]++;
		vars[PUSHED_COUNT]++;
	}
	else
		ra(a);
}

static void	push_ranges_to_b(t_stack **a, t_stack **b, int size)
{
	int	range;
	int	vars[2];

	if (size <= 100)
		range = 15;
	else
		range = 30;
	vars[TARGET_NUM] = 0;
	vars[PUSHED_COUNT] = 0;
	while (vars[PUSHED_COUNT] < size)
		push_algorathm(a, b, range, vars);
}

static void	push_back_to_a(t_stack **a, t_stack **b, int size)
{
	int	max_pos;

	while (*b)
	{
		max_pos = get_max_pos(*b);
		if (max_pos <= size / 2)
		{
			while (max_pos-- > 0)
				rb(b);
		}
		else
		{
			max_pos = size - max_pos;
			while (max_pos-- > 0)
				rrb(b);
		}
		pa(a, b);
		size--;
	}
}

void	butterfly_sort(t_stack **a, t_stack **b)
{
	int	size;

	b = malloc(sizeof (t_stack));
	if (!b)
		error();
	size = stack_size(a);
	push_ranges_to_b(a, b, size);
	push_back_to_a(a, b, size);
}
