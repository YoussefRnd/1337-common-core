/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:46:05 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/05 16:49:17 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Harl {
 private:
  void debug(void);
  void info(void);
  void warning(void);
  void error(void);

 public:
  void complain(std::string level);
};
