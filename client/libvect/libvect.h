/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvect.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 16:01:26 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/30 16:49:19 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVECT_H
# define LIBVECT_H

# define GROWTH_FACTOR	1.618

# define VECT(p, s)		((t_vect){.data = p, .used = s, .total = s})

# define VECT_ADD(v, d)		(vect_add(v, &d, sizeof(d)))
# define VECT_STRADD(v, d)	(vect_add(v, &d, sizeof(d) - 1))

# define VSTRCMP(v, s)	vect_memcmp(v, s, sizeof(s) - 1)
# define VSTRSTR(v, s)	vect_memmem(v, s, sizeof(s) - 1)

# include <stdlib.h>

typedef struct	s_vect
{
	void		*data;
	size_t		used;
	size_t		total;
}				t_vect;

int				vect_add(t_vect *v, void *data, size_t size);
int				vect_cmp(t_vect *a, t_vect *b);
int				vect_grow(t_vect *v, size_t n);
int				vect_memcmp(t_vect *a, unsigned char *s, size_t n);
int				vect_mset(t_vect *v, unsigned char c, size_t size, size_t n);
int				vect_mset_end(t_vect *v, unsigned char c, size_t size);
int				vect_push(t_vect *v, void *data, size_t size, size_t n);
int				vect_req(t_vect *v, size_t n);
void			*vect_memmem(t_vect *a, unsigned char *s, size_t n);
void			vect_del(t_vect *v);
void			vect_init(t_vect *v);

#endif
