/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:26:18 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/04 19:59:02 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>

#include "Weapon.hpp"

class HumanB {
 private:
  std::string name;
  Weapon* weapon;

 public:
  HumanB(std::string name);
  void setWeapon(Weapon& weapon);
  void attack(void);
};

#endif