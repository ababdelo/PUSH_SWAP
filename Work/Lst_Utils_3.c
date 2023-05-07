/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lst_Utils_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:27:54 by ababdelo          #+#    #+#             */
/*   Updated: 2023/05/07 13:49:14 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP.h"

int	count_tilltarget(t_node *head, int targ)
{
	int	index;

	index = 0;
	while (head != NULL && head->value != targ)
	{
		index++;
		head = head->next;
	}
	return (index);
}
