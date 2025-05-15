/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:07:13 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/17 11:14:11 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
 private:
  AMateria *source[4];

 public:
  // Constructors
  MateriaSource();

  // Copy Constructor
  MateriaSource(const MateriaSource &src);

  // Assignation Operator
  MateriaSource &operator=(const MateriaSource &src);

  // Destructor
  ~MateriaSource();

  // Member Functions
  void learnMateria(AMateria *m);
  AMateria *createMateria(const std::string &type);
};
