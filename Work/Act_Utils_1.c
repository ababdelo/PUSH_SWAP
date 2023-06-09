/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Act_Utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:08:59 by ababdelo          #+#    #+#             */
/*   Updated: 2023/05/07 13:58:28 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP.h"

void	sa(t_data *data)
{
	int	tmp;

	tmp = data->stack_a->value;
	data->stack_a->value = data->stack_a->next->value;
	data->stack_a->next->value = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_data *data)
{
	int	tmp;

	if (data->stack_b == NULL || countlst(data->stack_b) == 1)
		return ;
	tmp = data->stack_b->value;
	data->stack_b->value = data->stack_b->next->value;
	data->stack_b->next->value = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_data *data)
{
	int	tmp;

	tmp = data->stack_a->value;
	data->stack_a->value = data->stack_a->next->value;
	data->stack_a->next->value = tmp;
	if (data->stack_b == NULL || countlst(data->stack_b) == 1)
		return ;
	tmp = data->stack_b->value;
	data->stack_b->value = data->stack_b->next->value;
	data->stack_b->next->value = tmp;
	write(1, "ss\n", 3);
}

void	pa(t_data *data)
{
	if (data->stack_b == NULL)
		return ;
	lst_add_front(&data->stack_a, data->stack_b->value);
	delete_lst(&data->stack_b, get_lst_targ(data->stack_b, 1));
	write(1, "pa\n", 3);
}

void	pb(t_data *data)
{
	if (data->stack_a == NULL)
		return ;
	lst_add_front(&data->stack_b, data->stack_a->value);
	delete_lst(&data->stack_a, get_lst_targ(data->stack_a, 1));
	write(1, "pb\n", 3);
}
