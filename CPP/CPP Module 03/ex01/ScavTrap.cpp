/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:18:37 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/13 13:17:19 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#include <iostream>
#include <string>

// Constructors
ScavTrap::ScavTrap() : ClapTrap() {
  name = "default";
  hitPoints = 100;
  energyPoints = 50;
  attackDamage = 20;
  std::cout << "ScavTrap " << name << " created!\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
  this->name = name;
  hitPoints = 100;
  energyPoints = 50;
  attackDamage = 20;
  std::cout << "ScavTrap " << name << " created!\n";
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
  std::cout << "ScavTrap " << name << " created by copy!\n";
}

// Assignment operator
ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
  if (this != &other) {
    name = other.name;
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
  }
  std::cout << "ScavTrap " << name << " assigned!\n";
  return *this;
}

// Destructor
ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap " << name << " destroyed!\n";
}

// Member functions
void ScavTrap::attack(const std::string& target) {
  if (hitPoints > 0 && energyPoints > 0) {
    std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!\n";
    energyPoints--;
  } else {
    std::cout << "ScavTrap " << name << " cannot attack!\n";
  }
}

void ScavTrap::guardGate() {
  std::cout << "ScavTrap " << name << " has entered in Gate keeper mode\n";
}