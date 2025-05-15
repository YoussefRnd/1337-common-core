/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:18:06 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/12 18:50:16 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
  ScavTrap scavTrap("Wall-E");

  scavTrap.attack("target");
  scavTrap.guardGate();
  scavTrap.takeDamage(10);
  scavTrap.beRepaired(10);
  return 0;
}