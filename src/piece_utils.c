/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 00:29:27 by ielmoudn          #+#    #+#             */
/*   Updated: 2020/02/09 23:01:05 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void	real_shape(t_env *env)
{
	int		i;
	int		j;

	j = -1;
	while (++j < env->p_coord.y)
	{
		i = -1;
		while(++i < env->p_coord.x)
		{
			if (env->piece[j][i] == 1)
			{
				env->min_x = (i < env->min_x) ? i : env->min_x;
				env->min_y = (j < env->min_y) ? j : env->min_y;
				env->max_x = (i > env->max_x) ? i : env->max_x;
				env->max_y = (j > env->max_y) ? j : env->max_y;
			}
		}
	}
}

void	get_piece(t_env *env)
{
	int		i;
	int		j;
	char	*line;

	j = -1;
	create_token(env, 'p');
	while (++j < env->p_coord.y)
	{
		i = -1;
		get_next_line(0, &line);
		while(++i < env->p_coord.x)
			env->piece[j][i] = assign_char(line[i]);
		safe_free(line);
	}
	real_shape(env);
}
