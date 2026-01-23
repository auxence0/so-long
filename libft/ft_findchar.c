/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 10:45:50 by asauvage          #+#    #+#             */
/*   Updated: 2026/01/20 15:23:30 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_findchar(char *str, char search)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == search)
			return (i);
		i++;
	}
	return (-1);
}
