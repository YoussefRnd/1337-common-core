/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:51:55 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/13 18:25:28 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include <iostream>

// Constructors
ClapTrap::ClapTrap() : name("default"), hitPoints(10), energyPoints(10), attackDamage(0) {
  std::cout << "ClapTrap " << name << " created!\n";
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
  std::cout << "ClapTrap " << name << " created!\n";
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& other)
    : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage) {
  std::cout << "ClapTrap " << name << " created!\n";
}

// Assignment operator
ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
  if (this != &other) {
    name = other.name;
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
  }
  return *this;
}

// Destructor
ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap " << name << " destroyed!\n";
}

// Member functions
void ClapTrap::attack(const std::string& target) {
  if (hitPoints > 0 && energyPoints > 0) {
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!\n";
    energyPoints--;
  } else {
    std::cout << "ClapTrap " << name << " cannot attack!\n";
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
  hitPoints = (amount > hitPoints) ? 0 : hitPoints - amount;
  std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!\n";
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (hitPoints > 0 && energyPoints > 0) {
    hitPoints += amount;
    energyPoints--;
    std::cout << "ClapTrap " << name << " repairs " << amount << " points of health!\n";
  } else {
    std::cout << "ClapTrap " << name << " cannot be repaired!\n";
  }
}