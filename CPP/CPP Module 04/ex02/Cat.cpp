/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:20:43 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/14 17:05:06 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructors
Cat::Cat(void) {
  std::cout << "Cat Default constructor called\n";
  type = "Cat";
  brain = new Brain();
}

Cat::Cat(const std::string& type) : Animal(type) {
  std::cout << "Cat " << getType() << " constructor called\n";
  brain = new Brain();
}

// Copy constructor
Cat::Cat(const Cat& obj) {
  std::cout << "Cat Copy constructor called\n";
  brain = new Brain(*obj.brain);
  *this = obj;
}

// Assignment operator
Cat& Cat::operator=(const Cat& obj) {
  std::cout << "Cat Copy assignment operator called\n";
  if (this != &obj) {
    this->type = obj.type;
    delete this->brain;
    this->brain = new Brain(*obj.brain);
  }
  return (*this);
}

// Destructor
Cat::~Cat(void) {
  std::cout << "Cat Destructor called\n";
  delete brain;
}

// Member functions
void Cat::makeSound(void) const {
  std::cout << "Meow Meow!!!\n";
}