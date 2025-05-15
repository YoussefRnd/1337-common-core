/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:41:57 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/10 16:35:46 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsp.hpp"

Fixed crossProduct(const Point &a, const Point &b, const Point &c) {
  return (b.getX() - a.getX()) * (c.getY() - a.getY()) -
         (b.getY() - a.getY()) * (c.getX() - a.getX());
}

bool bsp(const Point a, const Point b, const Point c, const Point point) {
  Fixed ab = crossProduct(a, b, point);
  Fixed bc = crossProduct(b, c, point);
  Fixed ca = crossProduct(c, a, point);

  //* if positive means it's on oneside of the edge if the negative it's the oposite side, 
  //* so if all cross products are on the same side, the point is inside the triangle.
  return (ab > Fixed(0) && bc > Fixed(0) && ca > Fixed(0)) ||
         (ab < Fixed(0) && bc < Fixed(0) && ca < Fixed(0));
}
