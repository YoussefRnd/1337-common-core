/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 01:22:48 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/31 02:32:18 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

#include <iostream>
#include "../inc/AForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

// Constructors
Intern::Intern() {}

// Destructor
Intern::~Intern() {}

// Member functions
AForm *createPresidential(const std::string &target) {
  return new PresidentialPardonForm(target);
}

AForm *createRequest(const std::string &target) {
  return new RobotomyRequestForm(target);
}

AForm *createShrubbery(const std::string &target) {
  return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) {
  struct FormType {
      std::string name;
      AForm *(*create)(const std::string &target);
  };

  FormType formTypes[] = {
      {"shrubbery creation", createShrubbery},
      {"robotomy request", createRequest},
      {"presidential pardon", createPresidential}};

  for (int i = 0; i < 3; i++) {
    if (formName == formTypes[i].name) {
      std::cout << "Intern create " << formName << '\n';
      return formTypes[i].create(target);
    }
  }
  std::cout << "Error: Unknown form type '" << formName << "'" << '\n';
  return NULL;
}