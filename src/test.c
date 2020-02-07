/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 21:13:47 by ielmoudn          #+#    #+#             */
/*   Updated: 2020/02/08 00:34:18 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void	get_player_num(t_env *env)
{
	char	*line;

	get_next_line(0, &line);
	ft_putendl_fd(line, 2);
	env->p_num = line[10] - 48;
	safe_free(line);
}

void	get_board(t_env *env)
{
	char	*line;
	char	*temp;

	get_next_line(0, &line);
	temp = line + 8;
	env->b_coord.y = ft_atoi(temp);
	env->b_coord.x = ft_atoi(ft_strchr(temp, ' '));
	safe_free(line);
	get_next_line(0, &line);
	safe_free(line);
}

int main(void)
{
	t_env	*env;

	env = (t_env*)safe_malloc(sizeof(t_env));
	get_player_num(env);
	get_board(env);
	return (0);
}