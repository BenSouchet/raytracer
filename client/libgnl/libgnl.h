/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgnl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 08:40:07 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/30 16:49:10 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGNL_H
# define LIBGNL_H

# include "../libvect/libvect.h"

# ifndef GNL_BUFF_SIZE
#  define GNL_BUFF_SIZE 100
# endif

# ifndef GNL_SEP_CHAR
#  define GNL_SEP_CHAR '\n'
# endif

# ifndef GNL_APPEND_CHAR
#  define GNL_APPEND_CHAR GNL_SEP_CHAR
# endif

# ifndef GNL_IGNORE
#  define GNL_IGNORE ""
# endif

# define GNL_STR			1
# define GNL_APPEND			2
# define GNL_CHECK_SIZE		4

int		get_next_line(int fd, t_vect *v, t_vect *line, int opts);
int		gnl_vect(int fd, t_vect *v, t_vect *line, int opts);
int		gnl_lines(int fd, t_vect *lines, int opts);
size_t	gnl_read_all(int fd, t_vect *buf, int opts, size_t *calls);

#endif
