/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Act_Utils_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:09:22 by ababdelo          #+#    #+#             */
/*   Updated: 2023/05/07 13:58:41 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP.h"

void	rra(t_data *data, int let)
{
	int		tmp;
	int		tmp2;
	t_node	*ptr;

	ptr = data->stack_a;
	tmp = ft_getend(ptr)->value;
	tmp2 = ptr->value;
	ptr->value = tmp;
	while (ptr->next != NULL)
	{
		tmp = ptr->next->value;
		ptr->next->value = tmp2;
		tmp2 = tmp;
		ptr = ptr->next;
	}
	if (let == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_data *data, int let)
{
	int		tmp;
	int		tmp2;
	t_node	*ptr;

	ptr = data->stack_b;
	if (data->stack_b == NULL || countlst(data->stack_b) == 1)
		return ;
	tmp = ft_getend(ptr)->value;
	tmp2 = ptr->value;
	ptr->value = tmp;
	while (ptr->next != NULL)
	{
		tmp = ptr->next->value;
		ptr->next->value = tmp2;
		tmp2 = tmp;
		ptr = ptr->next;
	}
	if (let == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_data *data)
{
	rra(data, 0);
	rrb(data, 0);
	write(1, "rrr\n", 4);
}
