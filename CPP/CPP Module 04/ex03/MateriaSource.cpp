/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:08:05 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/17 11:34:18 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

#include <iostream>

// Constructors
MateriaSource::MateriaSource() {
  for (int i = 0; i < 4; i++) {
    source[i] = 0;
  }
}

// Copy Constructor
MateriaSource::MateriaSource(const MateriaSource &src) {
  for (int i = 0; i < 4; i++) {
    if (src.source[i]) {
      this->source[i] = src.source[i]->clone();
    } else {
      this->source[i] = 0;
    }
  }
}

// Assignation Operator
MateriaSource &MateriaSource::operator=(const MateriaSource &src) {
  if (this != &src) {
    for (int i = 0; i < 4; i++) {
      if (this->source[i]) {
        delete this->source[i];
      }
    }
    for (int i = 0; i < 4; i++) {
      if (this->source[i]) {
        this->source[i] = src.source[i]->clone();
      } else {
        this->source[i] = 0;
      }
    }
  }
  return *this;
}

// Destructor
MateriaSource::~MateriaSource() {
  for (int i = 0; i < 4; i++) {
    if (source[i]) {
      delete source[i];
    }
  }
}

// Member Functions
void MateriaSource::learnMateria(AMateria *m) {
  if (!m) return;

  for (int i = 0; i < 4; i++) {
    if (!source[i]) {
      source[i] = m;
      std::cout << "MateriaSource learned " << m->getType() << " in slot " << i << '\n';
      return;
    }
  }
  std::cout << "MateriaSource storage is full! Cannot learn " << m->getType() << '\n';
  delete m;
}

AMateria *MateriaSource::createMateria(const std::string &type) {
  for (int i = 0; i < 4; i++) {
    if (source[i] && source[i]->getType() == type) {
      std::cout << "MateriaSource created a new " << type << '\n';
      return source[i]->clone();
    }
  }
  std::cout << "MateriaSource doesn't know this Materia type: " << type << '\n';
  return 0;
}
