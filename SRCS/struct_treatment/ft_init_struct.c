/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy <georgy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:39:40 by georgy            #+#    #+#             */
/*   Updated: 2020/11/18 19:45:16 by georgy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/ft_printf.h"

static t_args	*ft_init_struct(t_args *arg)
{
	if ((arg = (t_args*)ft_calloc(1, sizeof(t_args))) == NULL)
		return (NULL);
	arg->i = 0;
	arg->len = 0;
	return (arg);
}
