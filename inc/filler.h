/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 21:12:04 by ielmoudn          #+#    #+#             */
/*   Updated: 2020/02/08 19:01:29 by ielmoudn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "../libs/libft/libft.h"
#include "../inc/filler.h"

# define BUFF_SIZE 1
# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>

typedef struct	s_coord
{
	int		x;
	int		y;
}				t_coord;

typedef struct	s_env
{
	int		p_num;
	int		**board;
	t_coord	b_coord;
	t_coord	p_coord;
}				t_env;

int		get_next_line(const int fd, char **line);
void	get_board(t_env *env);
void	get_player_num(t_env *env);
void	get_board_dim(t_env *env);



#endif