/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:42:47 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/09 11:53:11 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed {
 private:
  int fixedPoint;
  static const int FractionalBits = 8;

 public:
  Fixed();
  Fixed(const int value);
  Fixed(const float value);
  ~Fixed();
  Fixed(const Fixed &other);
  Fixed &operator=(const Fixed &other);
  int getRawBits(void) const;
  void setRawBits(const int raw);
  float toFloat(void) const;
  int toInt(void) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);
