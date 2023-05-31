/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:08:21 by ababdelo          #+#    #+#             */
/*   Updated: 2023/05/31 11:58:02 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		ac;
	int		cntr;

	ac = 1;
	if (argc == 1)
		return (0);
	initialize_prog(&data, argv, ac);
	if (argc < 3)
	{
		fst_check(&data, argv[1]);
		return (0);
	}
	else
	{
		cntr = countlst(data.stack_a);
		if (is_sorted(data.stack_a) == 1)
			return (0);
		else
			which_oper(&data, argc, cntr);
	}
}
