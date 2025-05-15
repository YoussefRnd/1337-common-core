/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:54:48 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/17 11:12:18 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

#include <iostream>

// Constructors
Cure::Cure() : AMateria("cure") {}

Cure::Cure(const std::string &type) : AMateria(type) {}

// Copy Constructor
Cure::Cure(const Cure &src) : AMateria(src) {
  this->type = src.type;
}

// Assignation Operator
Cure &Cure::operator=(const Cure &src) {
  if (this != &src) {
    this->type = src.type;
  }
  return *this;
}

// Destructor
Cure::~Cure() {}

// Member Functions
AMateria *Cure::clone() const {
  return new Cure(*this);
}

void Cure::use(ICharacter &target) {
  std::cout << "* heals " << target.getName() << "’s wounds *\n";
}