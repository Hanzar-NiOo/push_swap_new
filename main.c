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

static char	**get_results(long argc, char **argv)
{
	char	**results;
	long		idx;
	long		arg_idx;

	if (argc < 2)
		error();
	else if (argc == 2)
	{
		if (!argv[1])
			error();
		results = ft_split(argv[1], ' ');
	}
	else
	{
		idx = 0;
		arg_idx = 1;
		results = malloc((argc) * sizeof(char *));
		while (argv[arg_idx])
			results[idx++] = argv[arg_idx++];
		results[idx] = '\0';
	}
	return (results);
}

static long	check_results(char **results)
{
	long	idx;
	long	char_idx;

	// if (!check_argv(results))
	// 	return (0);
	idx = 0;
	while (results[idx])
	{
		char_idx = 0;
		while (results[idx][char_idx])
		{
			if (char_idx == 0 && ((results[idx][char_idx] == '+')
				|| (results[idx][char_idx] == '-'))
				&& !results[idx][char_idx + 1])
				char_idx++;
			else if ((results[idx][char_idx] >= 48)
				&& (results[idx][char_idx] <= 57))
				char_idx++;
			else
				return (0);
		}
		idx++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char	**results;
	t_stack	**a;
	t_stack	**b;

	// check_invalid_num(argv);
	// check_argv(argv);
	results = get_results(argc, argv);
	if (!check_results(results))
		error();
	a = get_stack(results);
	if (!a)
		error();
	b = NULL;
	if (is_duplicated(a) || !is_valid_input(a))
		error();
	if (!is_sorted(a))
	{
		if (stack_size(a) <= 5)
			small_sort(a);
		else
			butterfly_sort(a, b);
	}
	return (0);
}
