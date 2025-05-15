/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:41:58 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/13 13:16:59 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#include <iostream>

// Constructors
FragTrap::FragTrap() : ClapTrap() {
  name = "default";
  hitPoints = 100;
  energyPoints = 100;
  attackDamage = 30;
  std::cout << "FragTrap " << name << " created!\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
  this->name = name;
  hitPoints = 100;
  energyPoints = 100;
  attackDamage = 30;
  std::cout << "FragTrap " << name << " created!\n";
}

// Copy constructor
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
  std::cout << "FragTrap " << name << " created by copy!\n";
}

// Assignment operator
FragTrap& FragTrap::operator=(const FragTrap& other) {
  if (this != &other) {
    name = other.name;
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
  }
  std::cout << "FragTrap " << name << " assigned!\n";
  return *this;
}

// Destructor
FragTrap::~FragTrap() {
  std::cout << "FragTrap " << name << " destroyed!\n";
}

// Member functions
void FragTrap::attack(const std::string& target) {
  if (hitPoints > 0 && energyPoints > 0) {
    std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!\n";
    energyPoints--;
  } else {
    std::cout << "FragTrap " << name << " cannot attack!\n";
  }
}

void FragTrap::highFivesGuys(void) {
  std::cout << "FragTrap " << name << " high fives guys!\n";
}