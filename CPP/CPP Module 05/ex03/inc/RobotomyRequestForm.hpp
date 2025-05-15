/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:08:54 by yboumlak          #+#    #+#             */
/*   Updated: 2025/02/06 16:04:38 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
  private:
    std::string target;

  public:
    // Constructors
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string &target);

    // Copy constructor
    RobotomyRequestForm(const RobotomyRequestForm &other);

    // Copy assignment operator
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

    // Destructos
    ~RobotomyRequestForm();

    // Member functions
    void execute(Bureaucrat const &executor) const;
};
