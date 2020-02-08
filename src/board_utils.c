/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 18:45:32 by ielmoudn          #+#    #+#             */
/*   Updated: 2020/02/08 19:21:01 by ielmoudn         ###   ########.fr       */
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

void	get_board_dim(t_env *env)
{
	char	*line;
	char	*temp;

	get_next_line(0, &line);
	temp = line + 8;
	env->b_coord.y = ft_atoi(temp);
	env->b_coord.x = ft_atoi(ft_strchr(temp, ' '));
	// dprintf(2, "y = %d | x = %d\n", env->b_coord.y, env->b_coord.x);
	safe_free(line);
	get_next_line(0, &line);
	safe_free(line);
}

void	create_board(t_env *env)
{
	int		i;

	i = -1;
	env->board = (int**)safe_malloc(sizeof(int*) * env->b_coord.y);
	while (++i < env->b_coord.x)
		env->board[i] = (int*)safe_malloc(sizeof(int) * env->b_coord.x);
}

int		assign_char(char current)
{
	if (current == 'O' || current == 'o')
		return (-1);
	else if (current == 'X' || current == 'x')
		return (-2);
	else
		return (0);
}

void	get_board(t_env *env)
{
	int		i;
	int		j;
	char	*line;
	char	*temp;

	i = -1;
	create_board(env);
	dprintf(2, "y = %d | x = %d\n", env->b_coord.y, env->b_coord.x);
	while(++i < env->b_coord.y)
	{
		j = -1;
		get_next_line(0, &line);
		temp = ft_strchr(line, ' ') + 1;
		while(++j < env->b_coord.x)
		{
			env->board[i][j] = assign_char(temp[j]);
		}
		safe_free(line);
	}
	// i = -1;
	// while(++i < env->b_coord.y)
	// {
	// 	j = -1;
	// 	while(++j < env->b_coord.x)
	// 	{
	// 		ft_putnbr_fd(env->board[i][j], 2);
	// 	}
	// 	ft_putchar_fd('\n', 2);
	// }
}
