/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:36:03 by asauvage          #+#    #+#             */
/*   Updated: 2026/01/24 16:15:56 by asauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin_free_s2(char const *s1, char *s2)
{
	char	*res;
	size_t	len_tot;

	len_tot = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = malloc((len_tot) * sizeof(char));
	if (res == NULL)
		return (0);
	res[0] = '\0';
	ft_strlcat(res, s1, ft_strlen(s1) + 1);
	ft_strlcat(res, s2, len_tot);
	free(s2);
	return (res);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}
