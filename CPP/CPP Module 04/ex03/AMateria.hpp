/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:39:16 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/17 11:21:18 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class ICharacter;

class AMateria {
 protected:
  std::string type;

 public:
  // Constructors
  AMateria();
  AMateria(const std::string &type);

  // Copy Constructor
  AMateria(const AMateria &src);

  // Assignation Operator
  AMateria &operator=(const AMateria &src);

  // Destructor
  virtual ~AMateria();

  // Getters
  const std::string &getType() const;

  // Member Functions
  virtual AMateria *clone() const = 0;
  virtual void use(ICharacter &target);
};