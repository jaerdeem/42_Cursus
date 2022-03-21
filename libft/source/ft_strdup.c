/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkan <aalkan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:20:18 by aalkan            #+#    #+#             */
/*   Updated: 2022/03/09 13:20:19 by aalkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*ptr;
	size_t	index;

	ptr = (char *)malloc(sizeof(*str) * (ft_strlen(str) + 1));
	if (!ptr)
		return (NULL);
	index = 0;
	while (str[index])
	{
		ptr[index] = str[index];
		index++;
	}
	ptr[index] = '\0';
	return (ptr);
}
