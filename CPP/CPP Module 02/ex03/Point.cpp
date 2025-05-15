/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:18:50 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/09 13:03:04 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float x, const float y) : x(Fixed(x)), y(Fixed(y)) {}

Point::Point(const Point &other) : x(other.x), y(other.y) {}

Point &Point::operator=(const Point &) {
  std::cerr << "Assignment not supported\n";
  return *this;
}

Point::~Point() {}

Fixed Point::getX() const {
  return x;
}

Fixed Point::getY() const {
  return y;
}