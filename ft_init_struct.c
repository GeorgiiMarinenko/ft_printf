/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy <georgy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 17:34:51 by georgy            #+#    #+#             */
/*   Updated: 2020/12/02 23:14:45 by georgy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_args	*ft_init_struct(t_args *f)
{
	if ((f = (t_args*)ft_calloc(1, sizeof(t_args))) == NULL)
		return (NULL);
	f->i = 0;
	f->len = 0;
	return (f);
}
