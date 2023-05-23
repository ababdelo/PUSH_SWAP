/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sort_Utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:41:32 by ababdelo          #+#    #+#             */
/*   Updated: 2023/05/23 13:02:36 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP.h"

t_node	*sort_lst(t_data *data)
{
	t_node	*i;
	t_node	*lst;

	lst = malloc(sizeof(t_node));
	i = data->stack_a;
	lst->value = i->value;
	lst->next = NULL;
	if (!lst)
		return (NULL);
	i = data->stack_a->next;
	while (i != NULL)
	{
		lst_add_back(lst, i->value);
		i = i->next;
	}
	complete_sort_task(get_lst_targ(lst, 1));
	return (lst);
}

void	complete_sort_task(t_node *i)
{
	int		tmp;
	t_node	*j;

	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			if (i->value > j->value)
			{
				tmp = i->value;
				i->value = j->value;
				j->value = tmp;
			}
			j = j->next;
		}
		i = i->next;
	}
}

int	which_closer2range(t_data *data, int targ, int size)
{
	int		r_closer_pos;
	int		l_closer_pos;
	int		right;
	int		left;
	t_node	*head;

	r_closer_pos = size;
	l_closer_pos = size;
	head = data->stack_a;
	while (head != NULL)
	{
		if (is_member(data, head->value, 0))
		{
			right = count_tilltarget(data->stack_a, targ);
			left = size - right;
			if (right < r_closer_pos)
				r_closer_pos = right;
			if (left < l_closer_pos)
				l_closer_pos = left;
		}
		head = head->next;
	}
	if (r_closer_pos < l_closer_pos)
		return (1);
	return (0);
}

int	which_closer2targ(int targ_pos, int size)
{
	int		r_closer_pos;
	int		l_closer_pos;
	int		right;
	int		left;

	r_closer_pos = size;
	l_closer_pos = size;
	right = targ_pos;
	left = size - right;
	if (right < r_closer_pos)
		r_closer_pos = right;
	if (left < l_closer_pos)
		l_closer_pos = left;
	if (r_closer_pos < l_closer_pos)
		return (1);
	return (0);
}

void	complete_sort_largenbr(t_data *data)
{
	t_node	*targ;
	int		size;

	data->size = 1;
	while (data->size)
	{
		size = countlst(data->stack_b);
		data->size = countlst(data->stack_b);
		targ = getbglsval(data->stack_b);
		if (targ != NULL)
		{
			if (targ->value == data->stack_b->value)
				pa(data);
			else
			{
				if (which_closer2targ(
						(countlst(data->stack_b) - countlst(targ)), size))
					rb(data);
				else
					rrb(data, 1);
			}
		}
	}
}
