/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 00:29:27 by ielmoudn          #+#    #+#             */
/*   Updated: 2020/02/09 00:37:12 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void	get_piece(t_env *env)
{
	int		i;
	int		j;
	char	*line;

	j = -1;
	create_token(env, 'p');
	while(++j < env->p_coord.y)
	{
		i = -1;
		get_next_line(0, &line);
		while(++i < env->p_coord.x)
			env->piece[j][i] = assign_char(line[i]);
		safe_free(line);
	}
}
