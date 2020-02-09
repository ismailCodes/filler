/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 21:13:47 by ielmoudn          #+#    #+#             */
/*   Updated: 2020/02/09 17:41:22 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void	print_board(t_env *env)
{
	int	i;
	int	j;

	j = -1;
	while(++j < env->b_coord.y)
	{
		i = -1;
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
	get_player_num(env);
	get_token_dim(env, 'b');
	get_board(env);
	heatmap_trig(env);
	print_board(env);
	get_token_dim(env, 'p');
	get_piece(env);
	print_piece(env);
	score(env);
	return (0);
}