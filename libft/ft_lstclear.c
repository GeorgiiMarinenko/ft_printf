/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarlena <aarlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:16:28 by aarlena           #+#    #+#             */
/*   Updated: 2020/11/04 19:58:55 by aarlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*start;

	start = *lst;
	while (start)
	{
		tmp = start->next;
		if (del)
		{
			del(start->content);
		}
		free(start);
		start = tmp;
	}
	*lst = NULL;
}
