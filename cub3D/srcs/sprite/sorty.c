/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorty.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmerope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:13:00 by cmerope           #+#    #+#             */
/*   Updated: 2021/04/29 18:13:02 by cmerope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	quicksort_swap(double *dist, int *order, int i, int j)
{
	double	gap_dist;
	int		gap_ordinal_point;

	gap_dist = 0;
	gap_ordinal_point = 0;
	gap_dist = dist[i];
	gap_ordinal_point = order[i];
	dist[i] = dist[j];
	order[i] = order[j];
	dist[j] = gap_dist;
	order[j] = gap_ordinal_point;
}

static void	quicksort_unit(double *dist, t_sort *sort, int left, int right)
{
	while ((dist[sort->i] > sort->middle_dist) && (sort->i < right))
		sort->i++;
	while ((sort->middle_dist > dist[sort->j]) && (sort->j > left))
		sort->j--;
}

void	quicksort(double *dist, int *order, int left, int right)
{
	t_sort	sort;

	sort.i = left;
	sort.j = right;
	sort.middle_dist = dist[(left + right) / 2];
	while (sort.i <= sort.j)
	{
		quicksort_unit(dist, &sort, left, right);
		if (sort.i <= sort.j)
			quicksort_swap(dist, order, sort.i++, sort.j--);
	}
	if (left < sort.j)
		quicksort(dist, order, left, sort.j);
	if (sort.i < right)
		quicksort(dist, order, sort.i, right);
}
