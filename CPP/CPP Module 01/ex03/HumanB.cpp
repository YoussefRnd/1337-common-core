/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 19:55:46 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/04 20:13:51 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL){};

void HumanB::setWeapon(Weapon& weapon) { this->weapon = &weapon; };

void HumanB::attack(void) {
  if (weapon) {
    std::cout << name << " attacks with their " << weapon->getType() << '\n';
  } else {
    std::cout << name << " has no weapon to attack with!" << '\n';
  }
}
