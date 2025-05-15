/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:17:05 by yboumlak          #+#    #+#             */
/*   Updated: 2025/02/06 16:04:38 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class AForm;

class Bureaucrat {
  private:
    const std::string name;
    int grade;

  public:
    // Constructors
    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);

    // Copy constructor
    Bureaucrat(const Bureaucrat &other);

    // Copy assignment operator
    Bureaucrat &operator=(const Bureaucrat &other);

    // Destructor
    ~Bureaucrat();

    // Getters and Setters
    std::string getName() const;
    int getGrade() const;

    class GradeTooHighException : public std::exception {
      public:
        const char *what() const throw() {
          return "Grade is too high";
        }
    };

    class GradeTooLowException : public std::exception {
      public:
        const char *what() const throw() {
          return "Grade is too low";
        }
    };

    // Member functions
    int incrementGrade();
    int decrementGrade();
    void signForm(AForm &form);
    void executeForm(AForm const &form) const;
};

// Overloading operators
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);