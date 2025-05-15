/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:12:18 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/09 13:02:32 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point {
 private:
  const Fixed x;
  const Fixed y;

 public:
  Point();
  Point(const float x, const float y);
  Point(const Point &other);

  //! Assignment not supported
  Point &operator=(const Point &);

  ~Point();

  Fixed getX() const;
  Fixed getY() const;
};
