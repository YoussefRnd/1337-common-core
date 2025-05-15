/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:13:25 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/17 12:01:25 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Brain {
 private:
  std::string ideas[100];

 public:
  // Constructors
  Brain();

  // Copy Constructor
  Brain(const Brain &src);

  // Assignation Operator
  Brain &operator=(const Brain &src);

  // Destructor
  ~Brain();
};