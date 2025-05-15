/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:40:38 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/05 16:50:03 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Zombie {
 private:
  std::string name;

 public:
  Zombie();
  Zombie(std::string name);
  ~Zombie();
  void setName(std::string name);
  void announce(void);
};

Zombie* zombieHorde(int N, std::string name);
