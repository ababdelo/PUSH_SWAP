/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sort_Utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:27:35 by ababdelo          #+#    #+#             */
/*   Updated: 2023/05/07 20:35:26 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP.h"

int	is_sorted(t_node *head)
{
	while (head != NULL && head->next != NULL)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

int	is_member(t_data *data, int targ, int del)
{
	t_node	*start;
	t_node	*end;

	start = get_lst_targ(data->slst, data->start);
	end = get_lst_targ(data->slst, data->end);
	while (start != end && start != NULL)
	{
		if (targ == start->value)
		{
			if (del == 1)
				delete_lst(&data->slst, start);
			return (1);
		}
		start = start->next;
	}
	return (0);
}

void	push_bgval(t_node *head, t_data *data)
{
	int	cntr;

	cntr = countlst(head);
	if (cntr == 1)
		rra(data, 1);
	else if (cntr == 2)
	{
		rra(data, 1);
		rra(data, 1);
	}
	if (countlst(data->stack_a) == 5)
	{
		if (cntr == 3)
		{
			ra(data);
			ra(data);
		}
		else if (cntr == 4)
			ra(data);
	}
	else if (countlst(data->stack_a) == 4)
		if (cntr == 3)
			ra(data);
	pb(data);
}

void	update_cntrlvar(t_data *data)
{
	int	mgcnbr;

	mgcnbr = 4;
	data->head = data->stack_a;
	data->size = countlst(data->head);
	if (data->size >= 50 && data->size <= 150)
		mgcnbr = 8;
	else if (data->size >= 150 && data->size <= 250)
		mgcnbr = 14;
	else if (data->size > 250 && data->size <= 450)
		mgcnbr = 20;
	else if (data->size > 450)
		mgcnbr = 24;
	data->mid = data->size / 2;
	data->offset = data->size / mgcnbr;
	data->start = data->mid - data->offset;
	data->end = data->mid + data->offset;
}

void	approach2sort(t_data *data, t_node *head_a)
{
	int	size;

	size = countlst(data->stack_a);
	if (is_member(data, head_a->value, 1) || data->size <= 3)
	{
		pb(data);
		if (data->stack_b->value < getlstmidpos(data->stack_b)->value)
			rb(data);
		head_a = data->stack_a;
	}
	else
	{
		if (which_closer2range(data, head_a->value, size))
			ra(data);
		else
			rra(data, 1);
	}
}
