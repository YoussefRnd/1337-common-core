/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:00:31 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/10 11:40:04 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cmath>
#include <iostream>

Fixed::Fixed() : fixedPoint(0) {
  std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int value) {
  std::cout << "Int constructor called\n";
  fixedPoint = value << FractionalBits;
}

Fixed::Fixed(const float value) {
  std::cout << "Float constructor called\n";
  fixedPoint = static_cast<int>(roundf(value * (1 << FractionalBits)));
}

Fixed::~Fixed() {
  std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &other) : fixedPoint(other.fixedPoint) {
  std::cout << "Copy constructor called\n";
}

Fixed &Fixed::operator=(const Fixed &other) {
  std::cout << "Copy assignment operator called\n";
  if (this != &other) {
    this->fixedPoint = other.fixedPoint;
  }
  return *this;
}

int Fixed::getRawBits() const {
  std::cout << "getRawBits member function called\n";
  return fixedPoint;
}

void Fixed::setRawBits(const int raw) {
  std::cout << "setRawBits member function called\n";
  fixedPoint = raw;
}

float Fixed::toFloat(void) const {
  return static_cast<float>(fixedPoint) / (1 << FractionalBits);
}

int Fixed::toInt(void) const {
  return fixedPoint >> FractionalBits;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
  os << fixed.toFloat();
  return os;
}