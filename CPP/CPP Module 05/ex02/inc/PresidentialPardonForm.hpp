/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 23:33:29 by yboumlak          #+#    #+#             */
/*   Updated: 2025/02/06 15:49:17 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
  private:
    std::string target;

  public:
    // Constructors
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string &target);

    // Copy constructor
    PresidentialPardonForm(const PresidentialPardonForm &other);

    // Copy assignment operator
    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

    // Destructos
    ~PresidentialPardonForm();

    // Member functions
    void execute(Bureaucrat const &executor) const;
};