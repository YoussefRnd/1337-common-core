/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 23:36:46 by yboumlak          #+#    #+#             */
/*   Updated: 2025/02/06 16:04:38 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"

#include <iostream>

#include "../inc/Bureaucrat.hpp"

// Constructors
PresidentialPardonForm::PresidentialPardonForm() : AForm(), target("default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), target(target) {}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), target(other.target) {}

// Copy assignment operator
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
  if (this != &other) {
    AForm::operator=(other);
    target = other.target;
  }
  return *this;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {}

// Member functions
void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
  if (!getIsSigned()) {
    throw FormNotSignedException();
  } else if (executor.getGrade() > getExecGrade()) {
    throw GradeTooLowException();
  }

  std::cout << target << " has been pardoned by Zafod Beeblebrox" << '\n';
}
