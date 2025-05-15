/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 02:03:53 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/27 20:33:12 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Bureaucrat;

class AForm {
  private:
    const std::string name;
    const int signGrade;
    const int execGrade;
    bool isSigned;

  public:
    // Constructors
    AForm();
    AForm(const std::string &name, int signGrade, int execGrade);

    // Copy constructor
    AForm(const AForm &other);

    // Copy assignment operator
    AForm &operator=(const AForm &other);

    // Destructor
    virtual ~AForm();

    // Setters and Getters
    std::string getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;

    // Exepctions
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

    class FormNotSignedException : public std::exception {
      public:
        const char *what() const throw() {
          return "Form is not signed";
        }
    };

    // Memeber functions
    void beSigned(Bureaucrat &bureaucrat);
    virtual void execute(Bureaucrat const &executor) const = 0;
};

// Overloading operators
std::ostream &operator<<(std::ostream &os, const AForm &form);