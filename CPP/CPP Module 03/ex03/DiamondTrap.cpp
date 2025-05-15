/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:44:09 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/13 20:49:25 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#include <iostream>

// Constructors
DiamondTrap::DiamondTrap()
    : ClapTrap("default_clap_name"), name("default") {
  hitPoints = FragTrap::hitPoints;
  energyPoints = ScavTrap::energyPoints;
  attackDamage = FragTrap::attackDamage;
  std::cout << "DiamondTrap " << name << " created!\n";
}

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name, 50), FragTrap(name, 100, 30), name(name) {
  hitPoints = FragTrap::hitPoints;
  energyPoints = ScavTrap::energyPoints;
  attackDamage = FragTrap::attackDamage;
  ClapTrap::name = name + "_clap_name";
  std::cout << "DiamondTrap " << name << " created!\n";
}

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap& src)
    : ClapTrap(src.name + "_clap_name"), name(src.name) {
  hitPoints = src.hitPoints;
  energyPoints = src.energyPoints;
  attackDamage = src.attackDamage;
  std::cout << "DiamondTrap " << name << " created by copy!\n";
}

// Assignment operator
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& src) {
  if (this != &src) {
    ClapTrap::operator=(src);
    ScavTrap::operator=(src);
    FragTrap::operator=(src);

    name = src.name;
    hitPoints = src.hitPoints;
    energyPoints = src.energyPoints;
    attackDamage = src.attackDamage;
  }
  std::cout << "DiamondTrap " << name << " assigned by operator!\n";
  return *this;
}

// Destructor
DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap " << name << " destroyed.\n";
}

// Member functions
void DiamondTrap::attack(const std::string& target) {
  ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
  std::cout << "I am " << name << " and my ClapTrap name is " << ClapTrap::name << std::endl;
}