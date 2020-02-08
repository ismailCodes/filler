/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 20:47:55 by ielmoudn          #+#    #+#             */
/*   Updated: 2020/02/09 00:26:41 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

int			heatmap(t_env *env, int j, int i, int hm_with)
{
	if (i - 1 >= 0 && j - 1 >= 0)
		env->board[i - 1][j - 1] == 0 ? env->board[i - 1][j - 1] = hm_with : 0;
	if (i - 1 >= 0)
		env->board[i - 1][j] == 0 ? env->board[i - 1][j] = hm_with : 0;
	if (i - 1 >= 0 && j + 1 < env->b_coord.x)
		env->board[i - 1][j + 1] == 0 ? env->board[i - 1][j + 1] = hm_with : 0;
	if (j - 1 >= 0)
		env->board[i][j - 1] == 0 ? env->board[i][j - 1] = hm_with : 0;
	if (i + 1 < env->b_coord.y && j - 1 >= 0)
		env->board[i + 1][j - 1] == 0 ? env->board[i + 1][j - 1] = hm_with : 0;
	if (i + 1 < env->b_coord.y && j + 1 < env->b_coord.x)
		env->board[i + 1][j + 1] == 0 ? env->board[i + 1][j + 1] = hm_with : 0;
	if (i + 1 < env->b_coord.y)
		env->board[i + 1][j] == 0 ? env->board[i + 1][j] = hm_with : 0;
	if (j + 1 < env->b_coord.x)
		env->board[i][j + 1] == 0 ? env->board[i][j + 1] = hm_with : 0;
	return (1);
}

void		heatmap_trig(t_env *env)
{
	int		i;
	int		j;
	int		tracker;

	env->opponent = (env->p_num == 1) ? -2 : -1;
	tracker = 1;
	env->hm_with = 1;
	while (tracker--)
	{
		j = -1;
		while (++j < env->b_coord.y)
		{
			i = -1;
			while (++i < env->b_coord.x)
			{
				env->board[j][i] == 0 ? tracker = 1 : 0;
				if (env->board[j][i] == env->opponent)
					heatmap(env, i, j, env->hm_with);
			}
		}
		env->opponent = env->hm_with;
		env->hm_with += 1;
	}
}
