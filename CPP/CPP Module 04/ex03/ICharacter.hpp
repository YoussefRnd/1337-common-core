/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:09:25 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/17 11:21:14 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class AMateria;

class ICharacter {
 public:
  // Destructor
  virtual ~ICharacter() {}

  // Getters
  virtual const std::string &getName() const = 0;

  // Member Functions
  virtual void equip(AMateria *m) = 0;
  virtual void unequip(int idx) = 0;
  virtual void use(int idx, ICharacter &target) = 0;
};