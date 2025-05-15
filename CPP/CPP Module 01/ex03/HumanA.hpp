/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:57:41 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/05 16:49:56 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#include "Weapon.hpp"

class HumanA {
 private:
  std::string name;
  Weapon& weapon;

 public:
  HumanA(std::string name, Weapon& weapon);
  void attack(void);
};
