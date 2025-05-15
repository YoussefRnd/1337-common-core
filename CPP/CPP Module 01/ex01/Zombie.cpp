/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:46:55 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/03 20:13:49 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : name("Zombie1") {}

Zombie::Zombie(std::string name) : name(name) {}

Zombie::~Zombie() {
  std::cout << name << " is destroyed\n";
}

void Zombie::setName(std::string name) {
  this->name = name;
}

void Zombie::announce(void) {
  std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
