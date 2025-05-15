/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:54:53 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/17 11:12:22 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {
 public:
  // Constructors
  Cure();
  Cure(const std::string &type);

  // Copy Constructor
  Cure(const Cure &src);

  // Assignation Operator
  Cure &operator=(const Cure &src);

  // Destructor
  virtual ~Cure();

  // Member Functions
  virtual AMateria *clone() const;
  virtual void use(ICharacter &target);
};