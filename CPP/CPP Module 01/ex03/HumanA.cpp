/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 19:59:26 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/04 20:00:51 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {};

void HumanA::attack(void) {
  std::cout << name << " attacks with their " << weapon.getType() << '\n';
}
