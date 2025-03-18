/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yigsahin <yigsahin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:04:23 by yigsahin          #+#    #+#             */
/*   Updated: 2024/11/28 13:12:30 by yigsahin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	length(char *str)
{
	size_t	len;

	len = 0;
	while (str && str[len])
		len++;
	return (len);
}

int	check_line(char *buffer)
{
	int	i;

	if (!buffer)
		return (0);
	i = 0;
	while (buffer[i])
		if (buffer[i++] == '\n')
			return (1);
	return (0);
}

char	*string_join(char *str1, char *str2)
{
	char	*str;
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;

	len1 = length(str1);
	len2 = length(str2);
	str = (char *)malloc(len1 + len2 + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (i < len1)
		str[i++] = str1[j++];
	j = 0;
	while (j < len2)
		str[i++] = str2[j++];
	str[i] = '\0';
	free(str1);
	return (str);
}
