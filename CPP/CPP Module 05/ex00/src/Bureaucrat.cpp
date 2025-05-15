/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:52:27 by yboumlak          #+#    #+#             */
/*   Updated: 2025/02/06 16:04:38 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

#include <iostream>

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
    grade = other.grade;
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

// Overloading operators
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
  os << bureaucrat.getName() << ", bureaucrat grade: " << bureaucrat.getGrade() << '\n';
  return os;
}
