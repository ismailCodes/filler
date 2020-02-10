/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 20:47:55 by ielmoudn          #+#    #+#             */
/*   Updated: 2020/02/10 18:41:09 by ielmoudn         ###   ########.fr       */
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
	int		heati;

	env->opponent = (env->p_num == 1) ? -2 : -1;
	env->hm_with = 1;
	heati = -1;
	while (++heati < (env->b_coord.x > env->b_coord.y
		? env->b_coord.x : env->b_coord.y))
	{
		j = -1;
		while (++j < env->b_coord.y)
		{
			i = -1;
			while (++i < env->b_coord.x)
			{
				if (env->board[j][i] == env->opponent)
					heatmap(env, i, j, env->hm_with);
			}
		}
		env->opponent = env->hm_with;
		env->hm_with += 1;
	}
}
