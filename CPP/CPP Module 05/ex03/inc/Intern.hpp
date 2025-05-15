/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 01:13:52 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/31 01:23:31 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class AForm;

class Intern {
  public:
    // Constructors
    Intern();
    
    // Destructor
    ~Intern();

    // Member functions
    AForm *makeForm(const std::string &formName, const std::string &target);
};