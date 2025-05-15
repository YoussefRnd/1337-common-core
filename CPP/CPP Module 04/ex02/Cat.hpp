/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:19:41 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/14 16:36:58 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat : public Animal {
 private:
  Brain* brain;

 public:
  // Constructors
  Cat(void);
  Cat(const std::string& type);

  // Copy constructor
  Cat(const Cat& obj);

  // Assignment operator
  Cat& operator=(const Cat& obj);

  // Destructor
  ~Cat();

  // Member functions
  void makeSound(void) const;
};
