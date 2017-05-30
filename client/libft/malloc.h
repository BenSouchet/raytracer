/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 17:54:13 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/30 16:50:20 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <stdlib.h>

# define MALLOC_F malloc
# define MALLOC_ERR(x) ft_malloc_err(x, __FILE__, __LINE__)

# define MALLOC(p, x) if (!(p = MALLOC_F(x))) MALLOC_ERR(x)
# define MALLOC_N(p, n) MALLOC(p, sizeof(*p) * n)
# define MALLOC1(p) MALLOC_N(p, 1)

# define MALLOC_ZERO(p, x) MALLOC(p, x); ft_bzero(p, x)
# define MALLOC_ZERO_N(p, n) MALLOC_N(p, n); ft_bzero(p, sizeof(*p) * n)
# define MALLOC1_ZERO(p) MALLOC_ZERO(p, 1)

void	*ft_null(size_t size);
void	ft_malloc_err(size_t size, const char *file, int line);

#endif
