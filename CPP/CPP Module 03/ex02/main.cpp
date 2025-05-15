/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:42:33 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/12 18:51:42 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
  FragTrap fragTrap("XVII");

  fragTrap.attack("Bandit");
  fragTrap.takeDamage(20);
  fragTrap.beRepaired(10);
  fragTrap.highFivesGuys();
  return 0;
}