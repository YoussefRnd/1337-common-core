/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:42:47 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/09 11:13:05 by yboumlak         ###   ########.fr       */
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
  
  bool operator>(const Fixed &other) const;
  bool operator<(const Fixed &other) const;
  bool operator>=(const Fixed &other) const;
  bool operator<=(const Fixed &other) const;
  bool operator==(const Fixed &other) const;
  bool operator!=(const Fixed &other) const;
  
  Fixed operator+(const Fixed &other) const;
  Fixed operator-(const Fixed &other) const;
  Fixed operator*(const Fixed &other) const;
  Fixed operator/(const Fixed &other) const;
  
  Fixed &operator++();
  Fixed operator++(int);
  Fixed &operator--();
  Fixed operator--(int);

  static Fixed &min(Fixed &num1, Fixed &num2);
  static const Fixed &min(const Fixed &num1, const Fixed &num2);
  static Fixed &max(Fixed &num1, Fixed &num2);
  static const Fixed &max(const Fixed &num1, const Fixed &num2);
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);
