/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 10:28:00 by tmeyer            #+#    #+#             */
/*   Updated: 2018/11/30 14:38:44 by tmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <string.h>
# include "./libft/includes/libft.h"
# define BUFF_SIZE 32

int		get_next_line(const int fd, char **line);

#endif
