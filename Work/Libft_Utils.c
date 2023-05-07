/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Libft_Utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:23:56 by ababdelo          #+#    #+#             */
/*   Updated: 2023/05/07 20:25:35 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP.h"

size_t	ft_strlen(const char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

int	ft_strcmp(char *str, char *ref)
{
	int	index;

	index = 0;
	while (str[index] != '\0' || ref[index] != '\0')
	{
		if (str[index] != ref[index])
			return (str[index] - ref[index]);
		index++;
	}
	return (0);
}

int	wrd_cnt(char const *s, char del)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[index] != '\0')
	{
		while (s[index] == del)
			index++;
		if (s[index] != '\0')
			count++;
		while (s[index] != del && s[index] != '\0')
			index++;
	}
	return (count);
}

int	ft_atoi(t_data *data, char *str)
{
	int	sgn;
	int	index;
	int	result;

	index = 0;
	sgn = 1;
	while (str[index] == 32 || (str[index] >= 9 && str[index] <= 13))
		index++;
	if (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			sgn = -sgn;
		index++;
	}
	result = complete_atoi(data, str, index, sgn);
	return (result);
}

int	complete_atoi(t_data *data, char *str, int index, int sgn)
{
	unsigned int	result;

	result = 0;
	while (str[index])
	{
		if (str[index] >= '0' && str[index] <= '9')
			result = result * 10 + (str[index] - 48);
		else
		{
			data->err = "NAN";
			break ;
		}
		index++;
	}
	check_nbr_range(data, result, sgn);
	return (result * sgn);
}
