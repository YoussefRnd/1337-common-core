/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:39:20 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/17 11:19:40 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

#include <iostream>

#include "ICharacter.hpp"

// Constructors
AMateria::AMateria() : type("default") {}

AMateria::AMateria(const std::string &type) : type(type) {}

// Copy Constructor
AMateria::AMateria(const AMateria &src) : type(src.type) {}

// Assignation Operator
AMateria &AMateria::operator=(const AMateria &src) {
  if (this != &src) {
    this->type = src.type;
  }
  return *this;
}

// Destructor
AMateria::~AMateria() {}

// Getters
const std::string &AMateria::getType() const { return this->type; }

// Member Functions
void AMateria::use(ICharacter &target) {
  std::cout << "* uses some " << this->type << " on " << target.getName() << " *" << std::endl;
}