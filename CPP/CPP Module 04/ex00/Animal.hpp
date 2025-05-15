/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:03:59 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/14 17:34:14 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Animal {
 protected:
  std::string type;

 public:
	// Constructors
  Animal(void);
  Animal(const std::string& type);

	// Copy constructor
  Animal(const Animal& obj); 

	// Assignment operator
  Animal& operator=(const Animal& obj);  

	// Destructor
  virtual ~Animal();         
  
  // Getters
  std::string getType(void) const;
  
  // Member functions
  virtual void makeSound(void) const;                    
};
