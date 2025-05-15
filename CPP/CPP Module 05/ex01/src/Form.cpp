/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 23:23:34 by yboumlak          #+#    #+#             */
/*   Updated: 2025/02/06 15:40:49 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"

#include <iostream>

#include "../inc/Bureaucrat.hpp"

// Constructors
Form::Form() : name("default"), signGrade(150), execGrade(150), isSigned(false) {}

Form::Form(const std::string &name, int signGrade, int execGrade) : name(name), signGrade(signGrade), execGrade(execGrade), isSigned(false) {
  if (signGrade < 1 || execGrade < 1) {
    throw GradeTooHightExeption();
  } else if (signGrade > 150 || execGrade > 150) {
    throw GradeTooLowExeption();
  }
}

// Copy constructor
Form::Form(const Form &other) 
  : name(other.name), signGrade(other.signGrade), execGrade(other.execGrade), isSigned(other.isSigned) {}

// Copy assignment operator
Form &Form::operator=(const Form &other) {
  if (this != &other) {
    this->isSigned = other.isSigned;
  }
  return *this;
}

// Destructor
Form::~Form() {}

// Getters and Setters
std::string Form::getName() const {
  return name;
}

bool Form::getIsSigned() const {
  return isSigned;
}

int Form::getSignGrade() const {
  return signGrade;
}

int Form::getExecGrade() const {
  return execGrade;
}

// Member functions
void Form::beSigned(Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > this->getSignGrade()) {
    throw GradeTooLowExeption();
  }
  this->isSigned = true;
}

// Overloading operators
std::ostream &operator<<(std::ostream &os, const Form &form) {
  os << "Form name: " << form.getName() << ", is signed: " << form.getIsSigned() 
     << ", grade to sign: " << form.getSignGrade() << ", grade to execute: " << form.getExecGrade() << '\n';
  return os;
}