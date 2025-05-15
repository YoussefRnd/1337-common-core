/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:06:33 by yboumlak          #+#    #+#             */
/*   Updated: 2025/02/06 15:49:06 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"

#include <iostream>
#include <cstdlib>

#include "../inc/Bureaucrat.hpp"

// Constructors
RobotomyRequestForm::RobotomyRequestForm() : AForm(), target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), target(target) {}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) 
  : AForm(other), target(other.target) {}

// Copy assignment operator
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
  if (this != &other) {
    AForm::operator=(other);
    this->target = other.target;
  }
  return *this;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {}

// Member functions
void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  if (!getIsSigned()) {
    throw FormNotSignedException();
  } else if (executor.getGrade() > getExecGrade()) {
    throw GradeTooLowException();
  }

  std::cout << "*drilling noises*" << '\n';
  if (rand() % 2) {
    std::cout << target << " has been robotomized successfully" << '\n';
  } else {
    std::cout << target << " robotomization failed" << '\n';
  }
}