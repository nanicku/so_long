/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshad <mshad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 22:11:22 by mshad             #+#    #+#             */
/*   Updated: 2021/12/08 22:11:23 by mshad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s1n;

	s1n = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!s1n)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s1n[i] = s1[i];
		i++;
	}
	s1n[i] = '\0';
	return (s1n);
}
