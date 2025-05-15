/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:16:08 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/17 11:12:07 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

#include <iostream>

// Constructors
Character::Character() : unequippedMateria(0) {
  name = "default";
  for (int i = 0; i < 4; i++) {
    inventory[i] = 0;
  }
}

Character::Character(const std::string &name) : unequippedMateria(0) {
  this->name = name;
  for (int i = 0; i < 4; i++) {
    inventory[i] = 0;
  }
}

// Copy Constructor
Character::Character(const Character &src) {
  this->name = src.name;
  for (int i = 0; i < 4; i++) {
    if (src.inventory[i])
      this->inventory[i] = src.inventory[i]->clone();
    else
      this->inventory[i] = 0;
  }
  unequippedMateria = 0;
  node *current = src.unequippedMateria;
  while (current) {
    storeUnequippedMateria(current->m);
    current = current->next;
  }
}

// Assignation Operator
Character &Character::operator=(const Character &src) {
  if (this != &src) {
    this->name = src.name;
    for (int i = 0; i < 4; i++) {
      if (inventory[i]) {
        delete inventory[i];
      }
    }
    for (int i = 0; i < 4; i++) {
      if (src.inventory[i]) {
        this->inventory[i] = src.inventory[i]->clone();
      } else {
        this->inventory[i] = 0;
      }
    }
    deleteUnequippedMateria();
    node *current = src.unequippedMateria;
    while (current) {
      storeUnequippedMateria(current->m);
      current = current->next;
    }
  }
  return *this;
}

// Destructor
Character::~Character() {
  for (int i = 0; i < 4; i++) {
    if (inventory[i]) {
      delete inventory[i];
    }
  }
  deleteUnequippedMateria();
}

// Getters
const std::string &Character::getName() const {
  return name;
}

// Member Functions
void Character::equip(AMateria *m) {
  if (!m) return;

  for (int i = 0; i < 4; i++) {
    if (!inventory[i]) {
      inventory[i] = m;
      std::cout << name << " equipped " << m->getType() << " in slot " << i << '\n';
      return;
    }
  }
  std::cout << name << "'s inventory is full!" << '\n';
}

void Character::unequip(int idx) {
  if (idx >= 0 && idx < 4 && inventory[idx]) {
    std::cout << name << " unequipped " << inventory[idx]->getType() << " from slot " << idx << '\n';
    storeUnequippedMateria(inventory[idx]);
    inventory[idx] = 0;
    return;
  }
  std::cout << name << " can't unequip slot " << idx << " (invalid or empty)" << '\n';
}

void Character::use(int idx, ICharacter &target) {
  if (idx >= 0 && idx < 4 && inventory[idx]) {
    inventory[idx]->use(target);
    return;
  }
  std::cout << name << " tried to use an invalid slot " << idx << '\n';
}

void Character::storeUnequippedMateria(AMateria *m) {
  if (!m) return;
  node *newNode = new node;
  newNode->m = m;
  newNode->next = unequippedMateria;
  unequippedMateria = newNode;
}

void Character::deleteUnequippedMateria() {
  node *current = unequippedMateria;
  while (current) {
    node *next = current->next;
    delete current->m;
    delete current;
    current = next;
  }
  unequippedMateria = 0;
}