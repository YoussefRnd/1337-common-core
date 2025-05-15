/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:16:35 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/17 11:19:56 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter {
 private:
  std::string name;
  AMateria *inventory[4];
  struct node {
    AMateria *m;
    node *next;
  };
  node *unequippedMateria;

 public:
  // Constructors
  Character();
  Character(const std::string &name);

  // Copy Constructor
  Character(const Character &src);

  // Assignation Operator
  Character &operator=(const Character &src);

  // Destructor
  ~Character();

  // Getters
  const std::string &getName() const;

  // Member Functions
  void equip(AMateria *m);
  void unequip(int idx);
  void use(int idx, ICharacter &target);
  void storeUnequippedMateria(AMateria *m);
  void deleteUnequippedMateria();
};