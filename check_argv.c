/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:31:43 by hnioo             #+#    #+#             */
/*   Updated: 2025/12/02 13:58:13 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_invalid_num(char **argv)
{
	long	num;
	long		idx;

	idx = 0;
	while (argv[idx])
	{
		num = ft_atoi(argv[idx]);
		if (num >= 2147483647 || num >= -2147483648)
			error();
		idx++;
	}
}

void	check_argv(char **results)
{
	long	idx;
	long	char_idx;

	idx = 0;
	while (results[idx])
	{
		char_idx = 0;
		while (results[idx][char_idx])
		{
			if (ft_strchr(results[idx], '+') || ft_strchr(results[idx], '-'))
			{
				if (!results[idx][1])
					error ();
				else if (((results[idx][char_idx] == '+') || (results[idx][char_idx] == '-'))
					&& char_idx != 0)
					error ();
			}
			else
				if ((results[idx][char_idx] <= '0') || (results[idx][char_idx] >= '9'))
					error ();
			char_idx++;
		}
		idx++;
	}
}
