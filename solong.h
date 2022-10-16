/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:43:12 by muganiev          #+#    #+#             */
/*   Updated: 2022/10/16 17:02:52 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #ifndef SOLONG_H
 # define SOLONG_H
 
 # include <stdio.h>
 # include <stdlib.h>
 # include <unistd.h>
 # include "mlx/mlx.h"
 # include "gnl/get_next_line.h"

 typedef	s_prog;
 void		*mlx;
 void		*window;
 int		size_x;
 int		size_y;
 t_map		map;
 #endif