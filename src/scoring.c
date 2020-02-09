/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scoring.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 12:43:46 by ielmoudn          #+#    #+#             */
/*   Updated: 2020/02/09 17:43:32 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void	check_valid_coord(t_env *env, int i, int j)
{
	int		ii;
	int		jj;
	int		tracker;
	int		score;

	tracker = 0;
	score = 0;
	jj = -1;
	while (++jj < env->p_coord.y)
	{
		ii = -1;
		while (++ii < env->p_coord.x)
		{
			if (env->piece[jj][ii] == 1)
			{
				if (j + jj < env->b_coord.y && i + ii < env->b_coord.x
					&& env->board[j + jj][i + ii] == env->opponent)
					return ;
				if (j + jj < env->b_coord.y && i + ii < env->b_coord.x
					&& env->board[j + jj][i + ii] == env->player)
					tracker++;
				else if (j + jj < env->b_coord.y && i + ii < env->b_coord.x)
					score += env->board[j + jj][i + ii];
			}
		}
	}
	if (score && tracker == 1)
		dprintf(2, "i: %d | j: %d | score : %d", i, j, score);
}

void	score(t_env *env)
{
	int		i;
	int		j;
	env->player = (env->p_num == 1) ? -1 : -2;
	env->opponent = (env->p_num == 1) ? -2 : -1;
	j = -1;
	while (++j < env->b_coord.y)
	{
		i = -1;
		while (++i < env->b_coord.x)
				check_valid_coord(env, i, j);
	}
}