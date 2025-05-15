/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:25:28 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/17 11:12:20 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

#include <iostream>

// Constructors
Ice::Ice() : AMateria("ice") {}

Ice::Ice(const std::string &type) : AMateria(type) {}

// Copy Constructor
Ice::Ice(const Ice &src) : AMateria(src) {
  this->type = src.type;
}

// Assignation Operator
Ice &Ice::operator=(const Ice &src) {
  if (this != &src) {
    this->type = src.type;
  }
  return *this;
}

// Destructor
Ice::~Ice() {}

// Member Functions
AMateria *Ice::clone() const {
  return new Ice(*this);
}

void Ice::use(ICharacter &target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}