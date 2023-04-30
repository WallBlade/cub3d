/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:51:07 by zel-kass          #+#    #+#             */
/*   Updated: 2023/04/30 15:51:17 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double euc_distance(double x1, double y1, double x2, double y2)
{
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

void	get_next_vertical_point(double *x, double *y, double dy)
{
	*x -= 1;
	*y += dy;
}

void	get_next_horizontal_point(double *x, double *y, double dx)
{
	*y += 1;
	*x -= dx;
}