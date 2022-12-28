/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:15:59 by hasserao          #+#    #+#             */
/*   Updated: 2022/12/28 17:38:23 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;

	p = NULL;
	while (*s)
	{
		if (*(char *)s != (char)c)
			s++;
		else
		{
			p = (char *)s;
			s++;
		}
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (p);
}
