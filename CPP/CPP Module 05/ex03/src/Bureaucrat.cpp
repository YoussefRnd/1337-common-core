/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:52:27 by yboumlak          #+#    #+#             */
/*   Updated: 2025/02/06 15:22:38 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

#include <iostream>

#include "../inc/AForm.hpp"

// Constructors
Bureaucrat::Bureaucrat() : name("default"), grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name) {
  if (grade < 1) {
    throw GradeTooHighException();
  } else if (grade > 150) {
    throw GradeTooLowException();
  }
  this->grade = grade;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {}

// Copy assignment operator
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  if (this != &other) {
    this->grade = other.grade;
  }
  return *this;
}

// Destructor
Bureaucrat::~Bureaucrat() {}

// Getters and Setters
std::string Bureaucrat::getName() const {
  return name;
}

int Bureaucrat::getGrade() const {
  return grade;
}

// Member functions
int Bureaucrat::incrementGrade() {
  if (grade == 1) {
    throw GradeTooHighException();
  }
  grade--;
  return grade;
}

int Bureaucrat::decrementGrade() {
  if (grade == 150) {
    throw GradeTooLowException();
  }
  grade++;
  return grade;
}

void Bureaucrat::signForm(AForm &form) {
  try {
    form.beSigned(*this);
    std::cout << getName() << " signed " << form.getName() << '\n';
  } catch (const std::exception &e) {
    std::cout << getName() << " couldn’t sign " << form.getName()
              << " because " << e.what() << '\n';
  }
}

void Bureaucrat::executeForm(AForm const &form) const {
  try {
    form.execute(*this);
    std::cout << getName() << " executed " << form.getName() << '\n';
  } catch (const std::exception &e) {
    std::cout << getName() << " couldn’t execute " << form.getName()
              << " because " << e.what() << '\n';
  }
}

// Overloading operators
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
  os << bureaucrat.getName() << ", bureaucrat grade: " << bureaucrat.getGrade() << '\n';
  return os;
}