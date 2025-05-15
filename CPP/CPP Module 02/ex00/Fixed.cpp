/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:46:34 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/07 17:00:22 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>

Fixed::Fixed() : fixedPoint(0) {
  std::cout << "Default constructor called\n";
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
