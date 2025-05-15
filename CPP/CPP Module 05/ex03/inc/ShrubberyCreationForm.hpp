/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 00:06:37 by yboumlak          #+#    #+#             */
/*   Updated: 2025/02/06 16:04:38 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
  private:
    std::string target;

  public:
    // Constructors
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string &target);

    // Copy constructor
    ShrubberyCreationForm(const ShrubberyCreationForm &other);

    // Copy assignment operator
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

    // Destructor
    ~ShrubberyCreationForm();

    // Member functions
    void execute(Bureaucrat const &executor) const;
};
