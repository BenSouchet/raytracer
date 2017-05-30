/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_bar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 18:28:26 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/11 10:44:56 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_informations(t_rt *r, int i)
{
	r->inf = (char **)malloc(sizeof(char *) * 35);
	i = (
	s(&r->inf[0], INF0) && s(&r->inf[1], INF1) && s(&r->inf[2], INF2) &&
	s(&r->inf[3], INF3) && s(&r->inf[4], INF4) && s(&r->inf[5], INF5) &&
	s(&r->inf[6], INF6) && s(&r->inf[7], INF7) && s(&r->inf[8], INF8) &&
	s(&r->inf[9], INF9) && s(&r->inf[13], INF13) && s(&r->inf[14], INF14) &&
	s(&r->inf[15], INF15) && s(&r->inf[16], INF16) && s(&r->inf[21], INF21) &&
	s(&r->inf[24], INF24) && s(&r->inf[25], INF25) && s(&r->inf[26], INF26) &&
	s(&r->inf[27], INF27) && s(&r->inf[28], INF28) && s(&r->inf[29], INF29) &&
	s(&r->inf[30], INF30) && s(&r->inf[31], INF31)) ? 1 : 1;
}
