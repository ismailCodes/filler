/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scoring.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 12:43:46 by ielmoudn          #+#    #+#             */
/*   Updated: 2020/02/10 20:56:14 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void	free_token(int ***token, int j)
{
	int		i;

	i = -1;
	while (++i < j)
	{
		safe_free((*token)[i]);
		(*token)[i] = NULL;
	}
	safe_free(*token);
	*token = NULL;
}

void	reinit_all(t_env *env)
{
	env->best_score = INT_MAX;
	env->best_x = -1;
	env->best_y = -1;
	env->max_x = INT_MIN;
	env->max_y = INT_MIN;
	env->min_x = INT_MAX;
	env->min_y = INT_MAX;
}

void	score_h(t_env *env, int score, int x, int y)
{
	if (score < env->best_score)
	{
		env->best_score = score;
		env->best_x = x;
		env->best_y = y;
	}
}

void	check_valid_coord(t_env *env, int y, int x)
{
	int		stji[4];

	stji[1] = 0;
	stji[0] = 0;
	stji[2] = env->min_y - 1;
	while (++stji[2] < env->max_y + 1)
	{
		stji[3] = env->min_x - 1;
		while (++stji[3] < env->max_x + 1)
		{
			if (env->piece[stji[2]][stji[3]] == 1)
			{
				if (COND1 && COND_OP)
					return ;
				if (COND1 && COND_PLAY)
					stji[1]++;
				else if (COND1)
					stji[0] += env->board[y + stji[2]][x + stji[3]];
				else
					return ;
			}
		}
	}
	if (stji[1] == 1)
		score_h(env, stji[0], x, y);
}

void	score(t_env *env)
{
	int		x;
	int		y;

	env->player = (env->p_num == 1) ? -1 : -2;
	env->opponent = (env->p_num == 1) ? -2 : -1;
	y = -1;
	while (++y < env->b_coord.y)
	{
		x = -1;
		while (++x < env->b_coord.x)
			check_valid_coord(env, y, x);
	}
}
