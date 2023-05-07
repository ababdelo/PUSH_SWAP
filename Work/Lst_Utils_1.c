/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lst_Utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:21:58 by ababdelo          #+#    #+#             */
/*   Updated: 2023/05/07 13:47:53 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP.h"

t_node	*ft_getend(t_node *lst)
{
	t_node	*head = lst;

	while(head->next != NULL)
		head = head->next;
	return(head);
}

void	lst_add_front(t_node **lst, int data)
{
	t_node	*head;
	
	head = malloc(sizeof(t_node));
	head->value = data;
	head->next = *lst;
	*lst = head;
}

int	countlst(t_node *lst)
{
	t_node	*head;
	int 	count;

	count = 0;
	head = lst;
	while(head != NULL)
	{
		head = head->next;
		count++;
	}
	return (count);
}

t_node	*get_lst_targ(t_node *lst, int targ)
{
	t_node	*head;
	int		cntr;
	int		index;

	head = lst;
	cntr = countlst(head);
	index = 0;
	while(index < cntr && head != NULL)
	{
		index++;
		if(index == targ)
			break;
		head = head->next;
	}
	return(head);
}

void lst_add_back(t_node *stack_a,int data)
{
	t_node	*stack_a1;
	t_node	*ptr;

	stack_a1 = malloc(sizeof(struct s_node) * 1);
	stack_a1->value = data;
	stack_a1->next = NULL;
	ptr = ft_getend(stack_a);
	ptr->next = stack_a1;
}
