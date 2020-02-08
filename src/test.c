/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 21:13:47 by ielmoudn          #+#    #+#             */
/*   Updated: 2020/02/08 18:45:20 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

int main(void)
{
	t_env	*env;

	env = (t_env*)safe_malloc(sizeof(t_env));
	get_player_num(env);
	get_board_dim(env);
	get_board(env);
	return (0);
}