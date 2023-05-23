/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FT_Check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:05:10 by ababdelo          #+#    #+#             */
/*   Updated: 2023/05/23 14:31:34 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP.h"

void	fst_check(t_data *data, char *argv)
{
	check_args(data);
	if (ft_strcmp(data->err, "NAN") == 0)
		print_msg("Error ' Found a !Digit Number '\n");
	ft_atoi(data, argv);
	if (ft_strcmp(data->err, "INT_MAX") == 0)
		print_msg("Error ' Number Size is Out of Range (Nbr >> INT_MAX) '\n");
	else if (ft_strcmp(data->err, "INT_MIN") == 0)
		print_msg("Error ' Number Size is Out of Range (Nbr >> INT_MIN) '\n");
}

void	check_args(t_data *data)
{
	int	j;
	int	i;

	i = 0;
	while (data->av[++i] != NULL)
	{
		j = -1;
		if (data->av[i][0] == '-' || data->av[i][0] == '+')
			j++;
		while (data->av[i][++j] != '\0')
		{
			if (data->av[i][j] < '0' || data->av[i][j] > '9')
			{
				data->err = "NAN";
				return ;
			}
		}
	}
}

void	check_nbr_range(t_data *data, unsigned int nbr, int sgn)
{
	if (nbr > INT_MAX && sgn == 1)
		data->err = "INT_MAX";
	else if (nbr > 2147483648 && sgn == -1)
		data->err = "INT_MIN";
}

int	check_repetition(t_data *data)
{
	t_node	*head;
	t_node	*head2;
	int		cntr;

	head = data->stack_a;
	while (head != NULL)
	{
		cntr = 0;
		head2 = data->stack_a;
		while (head2 != NULL)
		{
			if (head->value == head2->value)
				cntr++;
			head2 = head2->next;
		}
		if (cntr > 1)
			return (1);
		head = head->next;
	}
	return (0);
}
