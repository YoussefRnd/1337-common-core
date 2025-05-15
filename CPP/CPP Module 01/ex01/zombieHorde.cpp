/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:17:45 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/03 19:57:09 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
  Zombie* horde = new Zombie[N];
  for (int i = 0; i < N; ++i) {
    horde[i].setName(name);
  }
  return horde;
}