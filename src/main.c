/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 21:13:47 by ielmoudn          #+#    #+#             */
/*   Updated: 2020/02/09 22:28:05 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void	print_board(t_env *env)
{
	int	i;
	int	j;
	int	t;

	t = env->b_coord.x;
	i = -1;
	while (++i < t)
		dprintf(2, "%3d", i);
	dprintf(2, "\n");
	dprintf(2, "\n");
	j = -1;
	while(++j < env->b_coord.y)
	{
		i = -1;
		dprintf(2, "%3d|", j);
		while(++i < env->b_coord.x)
		{
			dprintf(2, "%3d",env->board[j][i]);
		}
		dprintf(2, "\n");
	}
}

void	print_piece(t_env *env)
{
	int	i;
	int	j;

	j = -1;
	while(++j < env->p_coord.y)
	{
		i = -1;
		while(++i < env->p_coord.x)
		{
			dprintf(2, "%3d",env->piece[j][i]);
		}
		dprintf(2, "\n");
	}
}

int main(void)
{
	t_env	*env;

	env = (t_env*)safe_malloc(sizeof(t_env));
	env->best_score = INT_MAX;
	env->max_x = INT_MIN;
	env->max_y = INT_MIN;
	env->min_x = INT_MAX;
	env->min_y = INT_MAX;
	get_player_num(env);
	while (1)
	{
		get_token_dim(env, 'b');
		get_board(env);
		heatmap_trig(env);
	//	print_board(env);
		get_token_dim(env, 'p');
		get_piece(env);
		score(env);
		if (env->best_y == -1 && env->best_x == -1)
			break ;
		else
		dprintf(1, "%d %d\n", env->best_y, env->best_x);
		// dprintf(2, "%d %d score = %d\n",  env->best_y, env->best_x, env->best_score);
		// dprintf(2, "\n\n\n\n");
		reinit_all(env);
	}
	return (0);
}