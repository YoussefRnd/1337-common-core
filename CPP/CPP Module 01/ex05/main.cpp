/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:46:01 by yboumlak          #+#    #+#             */
/*   Updated: 2025/01/05 13:55:42 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {
  Harl harl;

  harl.complain("DEBUG");
  harl.complain("INFO");
  harl.complain("WARNING");
  harl.complain("ERROR");
  return 0;
}