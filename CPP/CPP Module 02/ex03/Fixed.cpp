/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:00:31 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/10 13:48:11 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cmath>
#include <iostream>

Fixed::Fixed() : fixedPoint(0) {}

Fixed::Fixed(const int value) {
  fixedPoint = value << FractionalBits;
}

Fixed::Fixed(const float value) {
  fixedPoint = static_cast<int>(roundf(value * (1 << FractionalBits)));
}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed &other) : fixedPoint(other.fixedPoint) {}

Fixed &Fixed::operator=(const Fixed &other) {
  if (this != &other) {
    this->fixedPoint = other.fixedPoint;
  }
  return *this;
}

int Fixed::getRawBits() const { return fixedPoint; }

void Fixed::setRawBits(const int raw) { fixedPoint = raw; }

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

bool Fixed::operator>(const Fixed &other) const {
  return fixedPoint > other.fixedPoint;
}

bool Fixed::operator<(const Fixed &other) const {
  return fixedPoint < other.fixedPoint;
}

bool Fixed::operator>=(const Fixed &other) const {
  return fixedPoint >= other.fixedPoint;
}

bool Fixed::operator<=(const Fixed &other) const {
  return fixedPoint <= other.fixedPoint;
}

bool Fixed::operator==(const Fixed &other) const {
  return fixedPoint == other.fixedPoint;
}

bool Fixed::operator!=(const Fixed &other) const {
  return fixedPoint != other.fixedPoint;
}

Fixed Fixed::operator+(const Fixed &other) const {
  Fixed result;
  result.fixedPoint = this->fixedPoint + other.fixedPoint;
  return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
  Fixed result;
  result.fixedPoint = this->fixedPoint - other.fixedPoint;
  return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
  Fixed result;
  result.fixedPoint = (this->fixedPoint * other.fixedPoint) >> FractionalBits;
  return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
  Fixed result;
  result.fixedPoint = (this->fixedPoint << FractionalBits) / other.fixedPoint;
  return result;
}

Fixed &Fixed::operator++() {
  this->fixedPoint++;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed temp = *this;
  this->fixedPoint++;
  return temp;
}

Fixed &Fixed::operator--() {
  this->fixedPoint--;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed temp = *this;
  this->fixedPoint--;
  return temp;
}

Fixed &Fixed::min(Fixed &num1, Fixed &num2) {
  return num1 < num2 ? num1 : num2;
}

const Fixed &Fixed::min(const Fixed &num1, const Fixed &num2) {
  return num1 < num2 ? num1 : num2;
}

Fixed &Fixed::max(Fixed &num1, Fixed &num2) {
  return num1 > num2 ? num1 : num2;
}

const Fixed &Fixed::max(const Fixed &num1, const Fixed &num2) {
  return num1 > num2 ? num1 : num2;
}
