/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:30:20 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/17 11:13:59 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class IMateriaSource {
 public:
  // Destructor
  virtual ~IMateriaSource() {}

  // Member Functions
  virtual void learnMateria(AMateria*) = 0;
  virtual AMateria* createMateria(std::string const& type) = 0;
};