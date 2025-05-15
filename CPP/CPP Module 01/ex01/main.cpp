/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:39:04 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/03 20:20:42 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
  int N = 5;
  std::string name = "Zombie";
  Zombie* horde = zombieHorde(N, name);

  for (int i = 0; i < N; ++i) {
    horde[i].announce();
  }

  delete[] horde;
  return 0;
}
