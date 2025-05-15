/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:34:20 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/12 21:46:03 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ClapTrap.hpp"

int main(void) {
  ClapTrap claptrap("Clappy");

  claptrap.attack("target1");
  claptrap.takeDamage(5);
  claptrap.beRepaired(3);
  return 0;
}