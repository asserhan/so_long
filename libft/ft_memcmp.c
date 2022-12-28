/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:44:18 by hasserao          #+#    #+#             */
/*   Updated: 2022/12/28 17:37:39 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)s1 > *(unsigned char *)s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		else
		{
			if (*(unsigned char *)s1 < *(unsigned char *)s2)
				return (*(unsigned char *)s1 - *(unsigned char *)s2);
		}
		s1++;
		s2++;
		i++;
	}
	return (0);
}
