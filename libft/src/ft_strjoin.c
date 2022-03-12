/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 22:11:26 by mshad             #+#    #+#             */
/*   Updated: 2021/12/08 22:11:27 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*cated;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	cated = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!cated)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		cated[i] = s1[i];
		++i;
	}
	free(s1);
	while (s2[j] != '\0')
	{
		cated[i] = s2[j];
		++i;
		++j;
	}
	cated[i] = '\0';
	return (cated);
}
