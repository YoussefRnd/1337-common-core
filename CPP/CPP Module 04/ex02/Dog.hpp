/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:21:29 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/14 16:35:55 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog : public Animal {
 private:
  Brain* brain;

 public:
  // Constructors
  Dog(void);
  Dog(const std::string& type);

  // Copy constructor
  Dog(const Dog& obj);

  // Assignment operator
  Dog& operator=(const Dog& obj);

  // Destructor
  ~Dog();

  // Member functions
  void makeSound(void) const;
};
