/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scoring.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 12:43:46 by ielmoudn          #+#    #+#             */
/*   Updated: 2020/02/09 23:00:58 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void	free_token(int **token, int j)
{
	int		i;

	i = -1;
	while (++i < j)
		safe_free(token[j]);
	safe_free(token);
}

void	reinit_all(t_env *env)
{
	//free_token(env->board, env->b_coord.y);
	// free_token(env->piece, env->p_coord.y);
	env->best_score = INT_MAX;
	env->best_x = -1;
	env->best_y = -1;
	env->max_x = INT_MIN;
	env->max_y = INT_MIN;
	env->min_x = INT_MAX;
	env->min_y = INT_MAX;
}

void	check_valid_coord(t_env *env, int y, int x)
{
	int		ii;
	int		jj;
	int		tracker;
	int		score;

	tracker = 0;
	score = 0;
	jj = env->min_y - 1;
	//	dprintf(2, "jj: %d | to: %d \n", jj, env->p_coord.y - env->max_y);
	while (++jj < env->max_y + 1)
	{
		ii = env->min_x - 1;
		//	dprintf(2, "ii: %d | to: %d \n", ii, env->p_coord.x - env->max_x + 1);
		while (++ii < env->max_x + 1)
		{
			if (env->piece[jj][ii] == 1)
			{
				if (y + jj < env->b_coord.y && x + ii < env->b_coord.x
					&& env->board[y + jj][x + ii] == env->opponent)
					return ;
				if (y + jj < env->b_coord.y && x + ii < env->b_coord.x
					&& env->board[y + jj][x + ii] == env->player)
					tracker++;
				else if (y + jj < env->b_coord.y && x + ii < env->b_coord.x)
					score += env->board[y + jj][x + ii];
				else
					return ;
			}
		}
	}
	if (tracker == 1)
	{
		if (score < env->best_score)
		{
			env->best_score = score;
			env->best_x = x;
			env->best_y = y;
		}
	}
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