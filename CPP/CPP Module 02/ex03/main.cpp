/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:06:25 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/10 16:22:20 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Point.hpp"
#include "bsp.hpp"

void isInTriangle(const Point &a, const Point &b, const Point &c, const Point &s) {
  std::cout << "Testing Point (" << s.getX() << ", " << s.getY() << "): ";
  if (bsp(a, b, c, s)) {
    std::cout << "Point is inside the triangle." << std::endl;
  } else {
    std::cout << "Point is outside the triangle." << std::endl;
  }
}

int main() {
  Point a(0, 0);
  Point b(5, 0);
  Point c(2, 5);

  Point inside(2, 2);
  isInTriangle(a, b, c, inside);

  Point outside(6, 6);
  isInTriangle(a, b, c, outside);

  Point onEdge(2, 0);
  isInTriangle(a, b, c, onEdge);

  Point onLine(1, 0);
  isInTriangle(a, b, c, onLine);

  Point largeTrianglePoint(500, 500);
  isInTriangle(a, b, c, largeTrianglePoint);

  return 0;
}