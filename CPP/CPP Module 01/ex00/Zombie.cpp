/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:46:55 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/03 17:17:32 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
  this->name = name;
}

Zombie::~Zombie() {
  std::cout << name << " is destroyed\n";
}

void Zombie::announce(void) {
  std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
