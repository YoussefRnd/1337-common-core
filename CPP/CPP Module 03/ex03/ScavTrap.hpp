/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:27:23 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/13 19:42:58 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
public:
  // Constructors
  ScavTrap();
  ScavTrap(std::string name);
  ScavTrap(std::string name, unsigned int energyPoints);
  
  // Copy constructor
  ScavTrap(const ScavTrap& other);
  
  // Assignment operator
  ScavTrap& operator=(const ScavTrap& other);
  
  // Destructor
  ~ScavTrap();

  // Member functions
  void attack(const std::string& target);
  void guardGate();
};
