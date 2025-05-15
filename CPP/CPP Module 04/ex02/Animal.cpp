/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:03:53 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/14 19:34:47 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Constructors
Animal::Animal(void) {
  type = "Animal";
  std::cout << "Animal Default constructor called\n";
}

Animal::Animal(const std::string& type) : type(type) {
  std::cout << "Animal " << getType() << " constructor called\n";
}

// Copy constructor
Animal::Animal(const Animal& obj) {
  std::cout << "Animal Copy constructor called\n";
  *this = obj;
}

// Assignment operator
Animal& Animal::operator=(const Animal& obj) {
  std::cout << "Animal Copy assignment operator called\n";
  if (this != &obj) {
    this->type = obj.type;
  }
  return (*this);
}

// Destructor
Animal::~Animal(void) {
  std::cout << "Animal Destructor called\n";
}

// Getters
std::string Animal::getType(void) const {
  return (this->type);
}

// Member functions
