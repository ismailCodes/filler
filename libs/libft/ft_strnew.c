/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 22:16:25 by ielmoudn          #+#    #+#             */
/*   Updated: 2020/02/10 13:27:09 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char*)safe_malloc(size + 1);
	if (!str)
		return (NULL);
	ft_memset(str, 0, size + 1);
	return (str);
}
