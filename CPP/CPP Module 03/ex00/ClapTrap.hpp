/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:16:39 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/12 22:11:10 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class ClapTrap {
 private:
  std::string name;
  unsigned int hitPoints;
  unsigned int energyPoints;
  unsigned int attackDamage;

 public:
  // Constructors
  ClapTrap();
  ClapTrap(std::string name);

  // Copy constructor
  ClapTrap(const ClapTrap& other);

  // Assignment operator
  ClapTrap& operator=(const ClapTrap& other);

  // Destructor
  ~ClapTrap();

  // Member functions
  void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
};