/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:55:20 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/13 13:11:35 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
 private:
  std::string name;

 public:
  // Constructors
  DiamondTrap();
  DiamondTrap(std::string name);

  // Copy constructor
  DiamondTrap(const DiamondTrap& src);

  // Assignment operator
  DiamondTrap& operator=(const DiamondTrap& src);

  // Destructor
  ~DiamondTrap();

  // Member functions
  void attack(const std::string& target);
  void whoAmI();
};