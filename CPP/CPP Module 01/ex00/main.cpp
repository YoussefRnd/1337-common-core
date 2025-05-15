/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:39:04 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/03 17:17:40 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
  Zombie *zombie = newZombie("Zombie");
  zombie->announce();
  randomChump("randomChump");
  delete zombie;
  return 0;
}