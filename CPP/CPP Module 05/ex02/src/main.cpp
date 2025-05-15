/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 23:21:49 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/31 01:03:25 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

int main() {
  try {
    Bureaucrat boss("Boss", 1);
    Bureaucrat intern("Intern", 150);

    ShrubberyCreationForm shrubbery("Home");
    RobotomyRequestForm robotomy("Bender");
    PresidentialPardonForm pardon("Marvin");

    std::cout << "\n[ Intern tries to sign forms ]" << std::endl;
    intern.signForm(shrubbery);
    intern.signForm(robotomy);
    intern.signForm(pardon);

    std::cout << "\n[ Boss signs all forms ]" << std::endl;
    boss.signForm(shrubbery);
    boss.signForm(robotomy);
    boss.signForm(pardon);

    std::cout << "\n[ Intern tries to execute forms ]" << std::endl;
    intern.executeForm(shrubbery);
    intern.executeForm(robotomy);
    intern.executeForm(pardon);

    std::cout << "\n[ Boss executes all forms ]" << std::endl;
    boss.executeForm(shrubbery);
    boss.executeForm(robotomy);
    boss.executeForm(pardon);

  } catch (const std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  return 0;
}