/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 21:13:47 by ielmoudn          #+#    #+#             */
/*   Updated: 2020/02/10 20:04:26 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void	init_env(t_env *env)
{
	env->best_score = INT_MAX;
	env->max_x = INT_MIN;
	env->max_y = INT_MIN;
	env->min_x = INT_MAX;
	env->min_y = INT_MAX;
}

void	print_coords(int best_x, int best_y)
{
	ft_putnbr(best_y);
	ft_putchar(' ');
	ft_putnbr(best_x);
	ft_putchar('\n');
}

int		main(void)
{
	int		p_num;
	t_env	*env;

	get_player_num(&p_num);
	env = (t_env*)safe_malloc(sizeof(t_env));
	init_env(env);
	env->p_num = p_num;
	while (1)
	{
		reinit_all(env);
		get_token_dim(env, 'b');
		get_board(env);
		heatmap_trig(env);
		get_token_dim(env, 'p');
		get_piece(env);
		score(env);
		if (env->best_y == -1 && env->best_x == -1)
			break ;
		else
			print_coords(env->best_x, env->best_y);
		free_token(&env->piece, env->p_coord.y);
		free_token(&env->board, env->b_coord.y);
	}
	free_all();
	return (0);
}
