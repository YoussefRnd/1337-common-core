/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:40:38 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/05 16:50:13 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Zombie {
 private:
  std::string name;

 public:
  Zombie(std::string name);
  ~Zombie();
  void announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);
