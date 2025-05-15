/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:40:26 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/12 22:16:22 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
 public:
  // Constructors
  FragTrap();
  FragTrap(std::string name);
  
  // Copy constructor
  FragTrap(const FragTrap& other);
  
  // Assignment operator
  FragTrap& operator=(const FragTrap& other);
  
  // Destructor
  ~FragTrap();

  // Member functions
  void attack(const std::string& target);
  void highFivesGuys(void);
};
