/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:21:50 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/14 17:33:51 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructors
Dog::Dog(void) {
	type = "Dog";
	std::cout << "Dog Default constructor called\n";
}

Dog::Dog(const std::string& type) : Animal(type) {
	std::cout << "Dog " << getType() << " constructor called\n";
}

// Copy constructor
Dog::Dog(const Dog& obj) {
	std::cout << "Dog Copy constructor called\n";
	*this = obj;
}

// Assignment operator
Dog& Dog::operator=(const Dog& obj) {
	std::cout << "Dog Copy assignment operator called\n";
	if (this != &obj) {
		this->type = obj.type;
	}
	return (*this);
}

// Destructor
Dog::~Dog(void) {
	std::cout << "Dog Destructor called\n";
}

// Member functions
void Dog::makeSound(void) const {
	std::cout << "Barkring!!!\n";
}