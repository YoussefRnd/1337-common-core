/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:21:50 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/14 17:05:38 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructors
Dog::Dog(void) {
  std::cout << "Dog Default constructor called\n";
  type = "Dog";
  brain = new Brain();
}

Dog::Dog(const std::string& type) : Animal(type) {
  std::cout << "Dog " << getType() << " constructor called\n";
  brain = new Brain();
}

// Copy constructor
Dog::Dog(const Dog& obj) {
  std::cout << "Dog Copy constructor called\n";
  brain = new Brain(*obj.brain);
  *this = obj;
}

// Assignment operator
Dog& Dog::operator=(const Dog& obj) {
  std::cout << "Dog Copy assignment operator called\n";
  if (this != &obj) {
    this->type = obj.type;
    delete this->brain;
    this->brain = new Brain(*obj.brain);
  }
  return (*this);
}

// Destructor
Dog::~Dog(void) {
  std::cout << "Dog Destructor called\n";
  delete brain;
}

// Member functions
void Dog::makeSound(void) const {
  std::cout << "Barkring!!!\n";
}