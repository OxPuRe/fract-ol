/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:06:15 by auverneu          #+#    #+#             */
/*   Updated: 2015/11/28 14:52:03 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (0);
	if (*str1 == '\200')
		return (200);
	while (n)
	{
		if (*str1 != *str2)
			return (*(unsigned char *)str1 - *(unsigned char *)str2);
		else if (*str1 == '\0')
			return (0);
		str1++;
		str2++;
		n--;
	}
	return (0);
}
