/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 18:45:32 by ielmoudn          #+#    #+#             */
/*   Updated: 2020/02/09 00:33:03 by ielmoudn         ###   ########.fr       */
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

void	get_token_dim(t_env *env, char b_p)
{
	char	*line;
	char	*temp;

	get_next_line(0, &line);
	temp = line + ((b_p == 'b') ? 8 : 6);
	if (b_p == 'b')
	{
		env->b_coord.y = ft_atoi(temp);
		env->b_coord.x = ft_atoi(ft_strchr(temp, ' '));
		safe_free(line);
		get_next_line(0, &line);
	}
	else
	{
		env->p_coord.y = ft_atoi(temp);
		env->p_coord.x = ft_atoi(ft_strchr(temp, ' '));
	}
	safe_free(line);
}

void	create_token(t_env *env, char b_p)
{
	int		i;

	i = -1;
	if (b_p == 'b')
	{
		env->board = (int**)safe_malloc(sizeof(int*) * env->b_coord.y);
		while (++i < env->b_coord.y)
			env->board[i] = (int*)safe_malloc(sizeof(int) * env->b_coord.x);
	}
	else
	{
		env->piece = (int**)safe_malloc(sizeof(int*) * env->p_coord.y);
		while (++i < env->p_coord.y)
			env->piece[i] = (int*)safe_malloc(sizeof(int) * env->p_coord.x);
	}
	
}

int		assign_char(char current)
{
	if (current == 'O' || current == 'o')
		return (-1);
	else if (current == 'X' || current == 'x')
		return (-2);
	else if (current == '*')
		return (1);
	else
		return (0);
}

void	get_board(t_env *env)
{
	int		i;
	int		j;
	char	*line;
	char	*temp;

	j = -1;
	create_token(env, 'b');
	while(++j < env->b_coord.y)
	{
		i = -1;
		get_next_line(0, &line);
		temp = ft_strchr(line, ' ') + 1;
		while(++i < env->b_coord.x)
			env->board[j][i] = assign_char(temp[i]);
		safe_free(line);
	}
}
