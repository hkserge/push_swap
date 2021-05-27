/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 14:37:51 by khelegbe          #+#    #+#             */
/*   Updated: 2021/05/27 15:51:26 by khelegbe         ###   ########.fr       */
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
	// CHECKER DOUBLONS
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
}
