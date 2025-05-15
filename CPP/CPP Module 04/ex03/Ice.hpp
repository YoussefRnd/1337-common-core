/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:23:40 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/16 23:32:46 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {
 public:
  // Constructors
  Ice();
  Ice(const std::string &type);

  // Copy Constructor
  Ice(const Ice &src);

  // Assignation Operator
  Ice &operator=(const Ice &src);

  // Destructor
  ~Ice();

  // Member Functions
  AMateria *clone() const;
  void use(ICharacter &target);
};