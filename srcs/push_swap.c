/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 14:37:51 by khelegbe          #+#    #+#             */
/*   Updated: 2021/06/22 15:49:50 by khelegbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_list(t_list *list)
{
	int			i;
	t_number	*number;

	i = 0;
	while (list)
	{
		number = list->content;
		printf("i = %3d\t\tvalue = %10d\tindex = %3d\tnext = %p\n", i++, number->value, number->index, list->next);
		list = list->next;
	}
}

int		check_number(char *num)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (num[i])
	{
		while (num[j])
		{
			if (num[i] != num[j])
				j++;
			else
				return (1);
		}
		i++;
		j = i + 1;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_list		*stack_a;
	t_list		*new_node;
	char		**number_args;
	int			i;
	t_number	*nb;

	if (argc <= 1)
		return (0);
	stack_a = NULL;
	number_args = argv + 1;
	i = 1;
	printf("\n%d\n", check_number(argv[1]));

	// CHECKER NUMERIQUES VALABLES UNIQUEMENT
	while (i < argc)
	{
		// CHECKER DOUBLONS (parcourir toute la liste)
		// CHECKER NUMERIQUES VALABLES UNIQUEMENT ()
		nb = malloc(sizeof(t_number)); 	// A PROTEGER
		nb->index = -1;
		nb->value = ft_atoi(argv[i]);
		new_node = ft_lstnew(nb);		// A PROTEGER
		ft_lstadd_back(&stack_a, new_node);
		i++;
	}
	display_list(stack_a);
	ft_lstclear(&stack_a, free);
	return (0);
}
