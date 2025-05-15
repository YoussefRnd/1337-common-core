/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 02:03:53 by yboumlak          #+#    #+#             */
/*   Updated: 2025/02/06 15:45:44 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Bureaucrat;

class Form {
  private:
    const std::string name;
    const int signGrade;
    const int execGrade;
    bool isSigned;

  public:
    // Constructors
    Form();
    Form(const std::string &name, int signGrade, int execGrade);

    // Copy constructor
    Form(const Form &other);

    // Copy assignment operator
    Form &operator=(const Form &other);

    // Destructor
    ~Form();
    
    // Setters and Getters
    std::string getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;

    // Exepctions
    class GradeTooHightExeption : public std::exception {
      public:
        const char *what() const throw() {
          return "Grade is too high";
        }
    };

    class GradeTooLowExeption : public std::exception {
      public:
        const char *what() const throw() {
          return "Grade is too low";
        }
    };

    // Memeber functions
    void beSigned(Bureaucrat &bureaucrat);
};

// Overloading operators
std::ostream &operator<<(std::ostream &os, const Form &form);