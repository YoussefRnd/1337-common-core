/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 23:23:34 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/27 20:45:08 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"

#include <iostream>

#include "../inc/Bureaucrat.hpp"

// Constructors
AForm::AForm() : name("default"), signGrade(150), execGrade(150), isSigned(false) {}

AForm::AForm(const std::string &name, int signGrade, int execGrade) : name(name), signGrade(signGrade), execGrade(execGrade), isSigned(false) {
  if (signGrade < 1 || execGrade < 1) {
    throw GradeTooHighException();
  } else if (signGrade > 150 || execGrade > 150) {
    throw GradeTooLowException();
  }
}

// Copy constructor
AForm::AForm(const AForm &other)
    : name(other.name), signGrade(other.signGrade), execGrade(other.execGrade), isSigned(other.isSigned) {}

// Copy assignment operator
AForm &AForm::operator=(const AForm &other) {
  if (this != &other) {
    this->isSigned = other.isSigned;
  }
  return *this;
}

// Destructor
AForm::~AForm() {}

// Getters and Setters
std::string AForm::getName() const {
  return name;
}

bool AForm::getIsSigned() const {
  return isSigned;
}

int AForm::getSignGrade() const {
  return signGrade;
}

int AForm::getExecGrade() const {
  return execGrade;
}

// Member functions
void AForm::beSigned(Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > this->getSignGrade()) {
    throw GradeTooLowException();
  }
  this->isSigned = true;
}

// Overloading operators
std::ostream &operator<<(std::ostream &os, const AForm &form) {
  os << "AForm name: " << form.getName() << ", is signed: " << form.getIsSigned()
     << ", grade to sign: " << form.getSignGrade() << ", grade to execute: " << form.getExecGrade() << '\n';
  return os;
}