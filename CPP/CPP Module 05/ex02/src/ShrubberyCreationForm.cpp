/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 00:27:04 by yboumlak          #+#    #+#             */
/*   Updated: 2025/02/06 15:49:00 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

#include <fstream>
#include <iostream>

#include "../inc/Bureaucrat.hpp"

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm() : AForm(), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) 
  : AForm(other), target(other.target) {}

// Copy assignment operator
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
  if (this != &other) {
    AForm::operator=(other);
    this->target = other.target;
  }
  return *this;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {}

// Member functions
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  if (!getIsSigned()) {
    throw FormNotSignedException();
  } else if (executor.getGrade() > getExecGrade()) {
    throw GradeTooLowException();
  }

  std::ofstream outfile((target + "_shrubbery").c_str());
  if (!outfile) {
    std::cerr << "Error: could not open file" << '\n';
    return;
  }
  std::cout << "Shrubbery successfully created in " << target << "_shrubbery" << '\n';

  outfile << "       _-_\n"
          << "    /~~   ~~\\\n"
          << " /~~         ~~\\\n"
          << "{               }\n"
          << " \\  _-     -_  /\n"
          << "   ~  \\\\ //  ~\n"
          << "_- -   | | _- _\n"
          << "  _ -  | |   -_\n"
          << "      // \\\\\n";

  outfile.close();
}