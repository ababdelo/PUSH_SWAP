/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PUSH_SWAP.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:12:12 by ababdelo          #+#    #+#             */
/*   Updated: 2023/05/23 14:30:34 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}t_node;

typedef struct s_data
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*slst;
	t_node	*head;

	char	**av;
	char	*err;
	int		size;
	int		offset;
	int		mid;
	int		start;
	int		end;
}	t_data;

void	initialize_struct(t_data *data, char **av);
void	print_msg(char *str);
void	fill_list(t_data *data, int ac);
void	lst_add_back(t_node *stack_a, int data);
void	print_list(t_node *lst, char c);
void	check_args(t_data *data);
void	get_error_ref(t_data *data);
void	push_bgval(t_node *head, t_data *data);
void	check_nbr_range(t_data *data, unsigned int nbr, int sgn);
void	fst_check(t_data *data, char *argv);

t_node	*sort_lst(t_data *data);
void	complete_sort_task(t_node *i);

t_node	*ft_getend(t_node *lst);
t_node	*get_lst_targ(t_node *lst, int targ);
t_node	*getbglsval(t_node *head);
t_node	*getsmllstval(t_node *head);
t_node	*getlstmidpos(t_node *head);

size_t	ft_strlen(const char *str);

int		ft_atoi(t_data *data, char *str);
int		complete_atoi(t_data *data, char *str, int index, int sgn);
int		countlst(t_node *lst);
int		count_tilltarget(t_node *head, int targ);
int		check_repetition(t_data *data);
int		ft_strcmp(char *str, char *ref);
int		which_closer2range(t_data *data, int targ, int size);
int		which_closer2targ(int targ_pos, int size);

int		is_sorted(t_node *head);
int		is_member(t_data *data, int targ, int del);

void	delete_lst(t_node **lst, t_node *target);
void	lst_add_front(t_node **lst, int data);

void	sort_2nbr(t_data *data);
void	sort_3nbr(t_data *data, t_node *head);
void	sort_5nbr(t_data *data);
void	sort_largenbr(t_data *data);

void	initialize_prog(t_data *data, char **argv, int ac);
void	which_oper(t_data *data, int ac, int cntr);
void	approach2sort(t_data *data, t_node *head_a);
void	update_cntrlvar(t_data *data);
void	complete_sort_largenbr(t_data *data);

void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);

void	pb(t_data *data);
void	pa(t_data *data);

void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);

void	rra(t_data *data, int let);
void	rrb(t_data *data, int let);
void	rrr(t_data *data);

#endif
