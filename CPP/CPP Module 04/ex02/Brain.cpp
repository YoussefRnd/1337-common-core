/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:19:40 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/14 17:15:50 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#include <iostream>

// Constructors
Brain::Brain() {
  std::cout << "Brain constructor called\n";
}

// Copy Constructor
Brain::Brain(const Brain &src) {
  std::cout << "Brain copy constructor called\n";
  *this = src;
}

// Assignation Operator
Brain &Brain::operator=(const Brain &src) {
  std::cout << "Brain assignation operator called\n";
  if (this != &src) {
    for (int i = 0; i < 100; i++) {
      this->ideas[i] = src.ideas[i];
    }
  }
  return *this;
}

// Destructor
Brain::~Brain() {
  std::cout << "Brain destructor called\n";
}
